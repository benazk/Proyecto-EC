


#include <nds.h>
 		// Librería de la NDS
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
#include "maps.h"
#include "gestionEntidades.h"

Prota personaje;
Stats stat;
Enemigo enemigos[MAX_ENEMIGOS];
Moneda monedas[MAX_MONEDAS];
Nivel mapa[NUM_MAPAS];

int numEnemigos = 0;
int numMonedas = 0;
extern touchPosition pos_pantalla;
int tiempoMaximo;
int tecla;
extern int spriteIndice;
extern int scrollY;
extern int collisionOffsetx;
extern int collisionOffsety;


void initStructs(){ //Esto pone valores por defecto a structs estáticos con una sola instancia y a algunas variables
	stat.nivelNum = 1;
	stat.monedas = 0;
	mapa[0] = (Nivel){14, 160, 60}; // Máximo de scrollY, tamaño de array del mapa y tiempo
	mapa[1] = (Nivel){20, 208, 45};
	mapa[2] = (Nivel){24, 240, 30};
	stat.nivActual = &mapa[0];
	personaje.x = 96;
	personaje.y = 160;
	personaje.posEnMapa = 3;
	personaje.estadisticas = &stat;
	scrollY = 0;
}

void crearMonedas(){ 
	int x = rand() % 224;
	int y = rand() % personaje.estadisticas->nivActual->altura + 6 - 1;	// Puede ir desde la columna mas alta del mapa hasta 0
	Moneda *m = &monedas[numMonedas];
	m->posx = x;
	m->posy = y;
	m->gestorMoneda = &GC;
	m->spriteID = MONEDA_SPRITE;
	m->gfxpoint = monedaSuelo;
	m->spriteBitMap = monedaTile;
	m->spriteSize = SPRITE32;
	m->size = 27;
	m->valor = 1;
	m->recogida = false;
	numMonedas++;
}
void recrearMoneda(){ //Cuando se pilla una moneda, se sustituye con esta función (Función en desuso)
	int i;
	int x = rand() % 224;
	int y = (rand() % 32*(personaje.estadisticas->nivActual->altura + 6 - 1));// - 32*(personaje.estadisticas->nivActual->altura + 6); // Puede ir desde arriba del mapa (Número negativo) hasta y = 192 (abajo del mapa)
	for(i = 0; i < numMonedas; i++){
		if(monedas[i].recogida){ //En caso de que en array haya un hueco para una moneda, es ocupado y se salta el paso de crear otra instancia de Moneda
			monedas[i].posx = x;
			monedas[i].posy = y;
			monedas[i].gestorMoneda = &GC;
			monedas[i].spriteID = MONEDA_SPRITE;
			monedas[i].gfxpoint = monedaSuelo;
			monedas[i].spriteBitMap = monedaTile;
			monedas[i].spriteSize = SPRITE32;
			monedas[i].size = 27;
			monedas[i].valor = 1;
			monedas[i].recogida = false;
			return;
			
		}
	}
}

bool VerificarColision(int x1, int x2, int y1, int y2, int width1, int width2, int height1, int height2, int a){ // Sirve para saber si ha habido una colisión entre dos entidades con anchura/altura
    bool collision = false;
	if ((x1 < (x2 + width2) && (x1 + width1) > x2) && (y1 < (y2 + height2) && (y1 + height1) > y2))
		collision = true;
	collisionOffsetx = abs(x2 - x1);
	collisionOffsety = abs(y2 - y1);
	return collision;
}

bool VerificarPunto(int x1, int x2, int y1, int y2, int size1){
	bool touch = false;
	if(x2 < (x1 + size1) && y2 < (y1 + size1)){
		touch = true;
	}
	return touch; // Verifica que una moneda ha sido tocada con la touchScreen
}


void spawnEnemigo(int x, int y, int tipoEnemigo, int dir, int origen, int column) { // Pone un enemigo en el array de enemigos (El bucle es por si un enemigo se ha eliminado y para que otro ocupe su posición)
	bool spawned = false; //Solo un enemigo se crea o sustituye por llamada
    if (numEnemigos >= MAX_ENEMIGOS) return;
	int i;
	for(i = 0; i < numEnemigos; i++){
		if(enemigos[i].gestorEnemigo == NULL && !spawned){ //En caso de que en array haya un hueco para un enemigo, es ocupado y se salta el paso de crear otra instancia de Enemigo
			spawned = true;
			enemigos[i].posx = x;
			enemigos[i].posy = y;
			enemigos[i].gestorEnemigo = &GM;
			enemigos[i].direccion = dir;
			enemigos[i].tileOrigen = origen;
			enemigos[i].colOrigen = column;
		}
	}
	if(!spawned){
		Enemigo *e = &enemigos[numEnemigos++];
		e->posx = x;
		e->posy = y;
		e->spriteID = tipoEnemigo;
		e->gestorEnemigo = &GM;
		e->direccion = dir;
		e->tileOrigen = origen;
		e->colOrigen = column;
		switch(tipoEnemigo){ // Por falta de tiempo este switch se queda con un solo case (Hay muchos switch así)
			case COCHE_SPRITE:
				e->gfxpoint = gfxCoche;
				e->spriteBitMap = cocheMap;
				e->spriteSize = SPRITE32;
				break;
			case COCHE_SPRITE2:
				e->gfxpoint = gfxCoche2;
				e->spriteBitMap = tileFlor2;
				e->spriteSize = SPRITE32;
				break;
		}
	}
	
}

void resetVariables(){
	oamClear(&oamMain, 0, 0);
	oamUpdate(&oamMain);
	DeshabilitarInterrrupciones();
	PararTempo();
	consoleClear();
	int j;
	for (j = 0; j < numEnemigos; j++) { //"elimina" a los enemigos del array
		enemigos[j].spriteIndice = 0;
		map1[enemigos[j].tileOrigen].enemigoSpawn = true; // Si el enemigo se pasa de x, la tile que genera enemigos puede volver a generarlos
		enemigos[j].posx = 0;
		enemigos[j].posy = 0;
		enemigos[j].spriteSize = 0;
		enemigos[j].spriteID = 0;
		enemigos[j].gfxpoint = NULL;
		enemigos[j].gestorEnemigo = NULL;
		enemigos[j].tileOrigen = 0;
	}
	switch(personaje.estadisticas->nivelNum){ // Pone al personaje al inicio del nivel
		case 1:
			map1[personaje.posEnMapa].estaPersonaje = false;
			map1[3].estaPersonaje = true;
			break;
		case 2:
			map2[personaje.posEnMapa].estaPersonaje = false;
			map2[3].estaPersonaje = true;
			break;
		case 3:
			map3[personaje.posEnMapa].estaPersonaje = false;
			map3[3].estaPersonaje = true;
			break;
	}
	personaje.posEnMapa = 3;
	personaje.x = 96;
	personaje.y = 160;
	personaje.estadisticas->monedas = 0;
	scrollY = 0;
	numEnemigos = 0;
	spriteIndice = 1;
	collisionOffsetx = 32;
	collisionOffsety = 32;
	pos_pantalla.px = 0;
	pos_pantalla.py = 0;
}

void morir(){
	subEstado = MUERTE;
	resetVariables();
	videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
		DISPLAY_BG2_ACTIVE | // Enable BG2 for display
		DISPLAY_BG3_ACTIVE | // Enable BG3 for display
		DISPLAY_SPR_ACTIVE | // Enable sprites for display
		DISPLAY_SPR_1D       // Enable 1D tiled sprites
		);
	visualizarFondoMuerte();
}

void ganar(){
	subEstado = VICTORIA;
	resetVariables();
	iprintf("\x1b[2;0H Desarrolladores: Yo");
	iprintf("\x1b[4;0H Diseno de niveles: Yo");
	iprintf("\x1b[6;0H Banda sonora: Yo (no)");
	iprintf("\x1b[8;0H Modelos 3D: Nadie");
	iprintf("\x1b[10;0H Sprites: Yo");
	iprintf("\x1b[12;0H Menciones especiales:");
	iprintf("\x1b[13;0H Benat Ezquerro");
	iprintf("\x1b[15;0H Creditos: Yo");
	iprintf("\x1b[17;0H Yo, 2026");
	videoSetMode(MODE_5_2D | 
		DISPLAY_BG2_ACTIVE | 
		DISPLAY_BG3_ACTIVE | 
		DISPLAY_SPR_ACTIVE | 
		DISPLAY_SPR_1D       
		);
	visualizarFondoVictoria();
}



void checkOpciones(){

	if(pos_pantalla.py <= 64){
		visualizarFondoSelectUno();
		stat.nivActual = &mapa[0];
		stat.nivelNum = 1;
		int latch = 58982;//(int)(65536 - (33554432/256)*1/20); 20 interrupciones por segundo, 20 ticks/s
		int timer_control = 0x0042;
		ConfigurarTemporizador(latch, timer_control);
		GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);
        GuardarSpritesMemoria(gfxCoche, cocheMap, SPRITE32);
	}
	else if (pos_pantalla.py > 64 && pos_pantalla.py <=128){
		visualizarFondoSelectDos();
		stat.nivActual = &mapa[1];
		stat.nivelNum = 2;
		int latch = 60293;//(int)(65536 - (33554432/256)*1/25); 25 interrupciones por segundo, 25 ticks/s
		int timer_control = 0x0042;
		ConfigurarTemporizador(latch, timer_control);
		GuardarSpritesMemoria(sueloSuelo, tileSuelo, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        GuardarSpritesMemoria(aguaSuelo2, tileAgua2, SPRITE32);
        GuardarSpritesMemoria(gfxCoche2, tileFlor2, SPRITE32);
	}
	else{ // ESTO AUN NO ESTÁ HECHO (NO LO VOY A HACER)
		/*visualizarFondoSelectTres();
		stat.nivActual = &mapa[2];
		stat.nivelNum = 3;
		int latch = 60854;//(int)(65536 - (33554432/256)*1/28); 28 interrupciones por segundo, 28 ticks/s
		int timer_control = 0x0042;
		ConfigurarTemporizador(latch, timer_control);
		/*GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
        GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);
        GuardarSpritesMemoria(gfxCoche, cocheMap, SPRITE32);*/
	}
}

void irMenu(){ //Para volver al menú
	consoleClear();
	iprintf("\x1b[4;2H Jugar (START)");
	iprintf("\x1b[12;2H Salir (B)");
	iprintf("\x1b[20;2H Elige la dificultad con");
	iprintf("\x1b[22;2H la pantalla tactil");
	visualizarFondoSelectUno();
	stat.nivActual = &mapa[0];
	stat.nivelNum = 1;
	int latch = 58982;//(int)(65536 - (33554432/256)*1/20); 20 interrupciones por segundo, 20 ticks/s
	int timer_control = 0x0042;
	ConfigurarTemporizador(latch, timer_control);
	subEstado=IDLE;
	Estado=MENU;
	oamClear(&oamMain, 0, 0);
	oamUpdate(&oamMain);
}

void juego(){
	spriteIndice = 1; // No está en 0 ya que el personaje es el indice 0
	initStructs();
	Estado=MENU;
	iprintf("\x1b[4;2H Jugar (START)");
	iprintf("\x1b[12;2H Salir (B)");
	iprintf("\x1b[20;2H Elige la dificultad con");
	iprintf("\x1b[22;2H la pantalla tactil");
	videoSetMode(MODE_5_2D | 
		DISPLAY_BG2_ACTIVE | 
		DISPLAY_BG3_ACTIVE | 
		DISPLAY_SPR_ACTIVE | 
		DISPLAY_SPR_1D       
		);
	
	visualizarFondoSelectUno();
	
	// Con esta configuración muestra al personaje y el mapa 1, estos sprites se descargarán de memoria cuando se cambie de mapa
	GuardarSpritesMemoria(florSuelo, tileFlor, SPRITE32); //Es necesario guardar todos los sprites necesarios en memoria antes de nada
    GuardarSpritesMemoria(aguaSuelo, tileAgua, SPRITE32);
    GuardarSpritesMemoria(gfxCoche, cocheMap, SPRITE32);
	GuardarSpritesMemoria(metaSuelo, metaTile, SPRITE32);
    GuardarSpritesMemoria(monedaSuelo, monedaTile, SPRITE32);
	GuardarSpritesMemoria(gfxpersonaje, personajeMap, SPRITE32);

	ConfigurarTeclado(0x4000 | 0x03F1); // Como las teclas SELECT, START y B van por interrupción, se pondrán sus bits a 1, es decir 0100 0011 1111 0001 o 0x43F1     
	int latch = 58982;//(int)(65536 - (33554432/256)*1/20); 20 interrupciones por segundo, 20 ticks/s
	int timer_control = 0x0042;
	ConfigurarTemporizador(latch, timer_control);

	EstablecerVectorInt();

	HabilitarInterrupciones();

	

	while(1){ //Bucle del juego
		ActualizarTeclado(); 
		int tecla;
		switch(Estado){
			
			case MENU:
				PantallaTactilPulsada();
				if(keysUp() & KEY_TOUCH) { // Como al pulsar no funciona bien, espero a que deje de pulsar y en esa posicion hago el check
					checkOpciones(); // Para seleccionar la dificultad con la pantalla táctil
				}
				if(!TeclaDetectada()) break;
				tecla = TeclaPulsada();
				if(tecla==START){ //Lleva al juego, muestra el mapa y todo.
					srand(time(NULL));
					HabilitarIntTeclado();
					HabilitarIntTempo();
					PonerEnMarchaTempo();
					consoleClear();
					videoSetMode(MODE_5_2D | 
						DISPLAY_SPR_ACTIVE | 
						DISPLAY_SPR_1D       
						);
					tiempoMaximo = personaje.estadisticas->nivActual->tiempo;
					int i;
					for(i = 0; i < MAX_MONEDAS; i++) crearMonedas();
					Estado=JUEGO;
					renderMapa(personaje.estadisticas->nivelNum); // Se renderiza el mapa dependiendo del 
					
				}
				if(tecla==B){ // Cierra el programa
					return 0;
				}
				break;
			case JUEGO:
				PantallaTactilPulsada();
				if(keysUp() & KEY_TOUCH) { // Como al pulsar no funciona bien, espero a que deje de pulsar y en esa posicion hago el check
					iprintf("\x1b[14;0H TOUCH %d %d", pos_pantalla.px, pos_pantalla.py);
					checkMonedas();
				}
				if(!TeclaDetectada()) break;
				tecla = TeclaPulsada();
				switch (subEstado){
					case IDLE:
						if(tecla==SELECT){ //Para entrar en un estado de pausa, que inhibe todas las interrupciones y detiene el temporizador
							subEstado=PAUSA;
							consoleClear();
							iprintf("\x1b[6;H PAUSA");
							InhibirIntTeclado();
							InhibirIntTempo();
							PararTempo();
							break;
						}
						if(!subirBarca && map1[personaje.posEnMapa].spriteID == AGUA_SUELO){ 
							morir(); // Mueres
							break;
						}
						
					case PAUSA:
						if(tecla==SELECT){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							subEstado=IDLE;
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
							break;
						}
						else if(tecla==B){
							videoSetMode(MODE_5_2D | 
								DISPLAY_BG2_ACTIVE | 
								DISPLAY_BG3_ACTIVE | 
								DISPLAY_SPR_ACTIVE | 
								DISPLAY_SPR_1D       
								);
							irMenu();
							break;
						}
					case MUERTE:
						if(tecla==START){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							videoSetMode(MODE_5_2D | 
								DISPLAY_SPR_ACTIVE | 
								DISPLAY_SPR_1D       
								);
							subEstado=IDLE;
							resetVariables();
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
							break;
						}
						else if(tecla==B){
							videoSetMode(MODE_5_2D | 
								DISPLAY_BG2_ACTIVE | 
								DISPLAY_BG3_ACTIVE | 
								DISPLAY_SPR_ACTIVE | 
								DISPLAY_SPR_1D       
								);
							irMenu();
							break;
						}
					case VICTORIA:
						if(tecla==START){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							videoSetMode(MODE_5_2D |
								DISPLAY_SPR_ACTIVE |
								DISPLAY_SPR_1D       
								);
							subEstado=IDLE;
							resetVariables();
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
							break;
						}
						else if(tecla==B){
							videoSetMode(MODE_5_2D | 
								DISPLAY_BG2_ACTIVE | 
								DISPLAY_BG3_ACTIVE | 
								DISPLAY_SPR_ACTIVE | 
								DISPLAY_SPR_1D       
								);
							irMenu();
							break;
						}
					default:
						break;
				}
				
				break;
		}
		
	}
}

