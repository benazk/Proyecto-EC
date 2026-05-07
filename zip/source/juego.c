


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
int tiempo;
int tecla;
extern int spriteIndice;
extern int scrollY;
extern int collisionOffsetx;
extern int collisionOffsety;


void initStructs(){ //Esto pone valores por defecto a structs estaticos con una sola instancia y a algunas variables
	stat.nivelNum = 1;
	stat.monedas = 0;
	mapa[0] = (Nivel){14, 160, 1}; // Máximo de scrollY, tamaño de array del mapa y dificultad
	mapa[1] = (Nivel){14, 160, 2};
	mapa[2] = (Nivel){14, 160, 3};
	stat.nivActual = &mapa[0];
	personaje.x = 96;
	personaje.y = 160;
	personaje.posEnMapa = 3;
	personaje.estadisticas = &stat;
	scrollY = 0;
}

void crearMonedas(){
	bool spawned = false; //Solo una moneda se crea o sustituye por llamada a esta funcion
    if (numMonedas >= MAX_MONEDAS) return;
	int i;
	int x = rand() % 224;
	int y = (rand() % 32*(personaje.estadisticas->nivActual->altura)) - 32*(personaje.estadisticas->nivActual->altura + 6); // Puede ir desde arriba del mapa (Número negativo) hasta y = 192 (abajo del mapa)
	for(i = 0; i < numEnemigos; i++){
		if(monedas[i].recogida){ //En caso de que en array haya un hueco para una moneda, es ocupado y se salta el paso de crear otra instancia de Moneda
			spawned = true;
			monedas[i].posx = x;
			monedas[i].posy = y;
			monedas[i].gestorMoneda = &GC;
			monedas[i].spriteID = MONEDA_SPRITE;
			monedas[i].gfxpoint = monedaSuelo;
			monedas[i].spriteBitMap = monedaTile;
			monedas[i].spriteSize = SPRITE32;
			monedas[i].size = 27;
			monedas[i].valor = 1;
			monedas[i].recogida = 0;
			//iprintf("\x1b[1;0H Moneda:(%d %d)",monedas[i].posx ,monedas[i].posy);
		}
	}
	if(!spawned){
		Moneda *m = &monedas[numMonedas++];
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
	}
	
}

bool VerificarColision(int x1, int x2, int y1, int y2, int width1, int width2, int height1, int height2, int a){ // Sirve para saber si ha habido una colisión entre dos entidades
    bool collision = false;
	if ((x1 < (x2 + width2) && (x1 + width1) > x2) && (y1 < (y2 + height2) && (y1 + height1) > y2))
		collision = true;
	
	//iprintf("\x1b[%d;0H Personaje: (%d %d), Enemigo:(%d %d)", a, x2, y2, x1, y1);
	collisionOffsetx = abs(x2 - x1);
	collisionOffsety = abs(y2 - y1);
	//iprintf("\x1b[10;0H CollisionOffset: (%d %d)", collisionOffsetx, collisionOffsety);
	return collision;
}

bool VerificarPunto(int x1, int x2, int y1, int y2, int size1){
	bool touch = false;
	if(x2 < (x1 + size1 + (32-size1)/2) && y2 < (y1 + size1 + (32-size1)/2)){
		touch = true;
	}
	iprintf("\x1b[4;4H Toco moneda? %d", touch);
	return touch; // Verifica que 
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
			enemigos[i].spriteID = tipoEnemigo;
			enemigos[i].gestorEnemigo = &GM;
			enemigos[i].direccion = dir;
			enemigos[i].tileOrigen = origen;
			enemigos[i].colOrigen = column;
			switch(tipoEnemigo){
				case COCHE_SPRITE:
					enemigos[i].gfxpoint = gfxCoche;
					enemigos[i].spriteBitMap = cocheMap;
					enemigos[i].spriteSize = SPRITE32;
					break;
			}
		}
	}
	if(!spawned){
		Enemigo *e = &enemigos[numEnemigos++];
		e->posx = x;
		e->posy = y;
		e->spriteID = tipoEnemigo;
		e->gestorEnemigo = &GM;
		e->direccion = dir;
		enemigos[i].tileOrigen = origen;
		enemigos[i].colOrigen = column;
		switch(tipoEnemigo){
			case COCHE_SPRITE:
				e->gfxpoint = gfxCoche;
				e->spriteBitMap = cocheMap;
				e->spriteSize = SPRITE32;
				break;
		}
	}
	
}

void morir(){
	subEstado = MUERTE;
	oamClear(&oamMain, 0, 0);
	oamUpdate(&oamMain);
	DeshabilitarInterrrupciones();
	PararTempo();
	consoleClear();
	int j;
	for (j = 0; j < numEnemigos; j++) { // Actualiza la posicion de los enemigos cada tick del reloj
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
	switch(personaje.estadisticas->nivActual->dificultad){
		case 1:
			map1[personaje.posEnMapa].estaPersonaje = false;
			map1[3].estaPersonaje = true;
			break;
	}
	personaje.posEnMapa = 3;
	personaje.vivo = false;
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
	oamClear(&oamMain, 0, 0);
	oamUpdate(&oamMain);
	DeshabilitarInterrrupciones();
	PararTempo();
	consoleClear();
	int j;
	for (j = 0; j < numEnemigos; j++) { // Actualiza la posicion de los enemigos cada tick del reloj
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
	switch(personaje.estadisticas->nivActual->dificultad){
		case 1:
			map1[personaje.posEnMapa].estaPersonaje = false;
			map1[3].estaPersonaje = true;
			break;
	}
	personaje.posEnMapa = 3;
	personaje.vivo = false;
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
	videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
		DISPLAY_BG2_ACTIVE | // Enable BG2 for display
		DISPLAY_BG3_ACTIVE | // Enable BG3 for display
		DISPLAY_SPR_ACTIVE | // Enable sprites for display
		DISPLAY_SPR_1D       // Enable 1D tiled sprites
		);
	visualizarFondoVictoria();
}


void juego(){
	srand(time(NULL));
	spriteIndice = 1; // No está en 0 ya que el personaje es el indice 0
	initStructs();
	Estado=MENU;
	
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	ConfigurarTeclado(0x4000 | 0x03F1); // Como las teclas SELECT, START y B van por interrupción, se pondrán sus bits a 1, es decir 0100 0011 1111 0001 o 0x43F1     

	int latch = 58982;//(int)(65536 - (33554432/256)*1/20); 20 interrupciones por segundo, 20 ticks/s
	int timer_control = 0x0042;

	ConfigurarTemporizador(latch, timer_control);

	EstablecerVectorInt();

	HabilitarInterrupciones();

	
	// Con esta configuración muestra al personaje y el mapa
	
	
	while(1){ //Bucle del juego
		ActualizarTeclado(); 
		int tecla;
		switch(Estado){
			
			case MENU:
				iprintf("\x1b[4;2H Jugar (START)");
				iprintf("\x1b[12;2H Stats (SELECT)");
				iprintf("\x1b[20;2H Salir (B)");
				if(!TeclaDetectada()) break;
				tecla = TeclaPulsada();
				if(tecla==START){ //Lleva al juego, muestra el mapa y todo.
					HabilitarIntTeclado();
					HabilitarIntTempo();
					PonerEnMarchaTempo();
					consoleClear();
					GuardarSpritesMemoria(gfxpersonaje, personajeMap, SPRITE32);
					int i;
					for(i = 0; i < MAX_MONEDAS; i++) crearMonedas();
					renderMapa(personaje.estadisticas->nivelNum);
					iprintf("\x1b[6;0H Cantidad de sprites: %d", spriteIndice);
					Estado=JUEGO;
					subEstado=IDLE;
				}
				if(tecla==SELECT){ //Si la tecla es select, te lleva a las stats

				}
				if(tecla==B){ // Cierra el emulador
					swiSoftReset();//Funcion de nds para "apagar" la consola
				}
				break;
			case JUEGO:
				if(PantallaTactilPulsada()) {
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
						}
						iprintf("\x1b[0;1H %d MONEDAS", personaje.estadisticas->monedas);
						if(!subirBarca && map1[personaje.posEnMapa].spriteID == AGUA_SUELO){ 
							//morir(); // Mueres
						}
						break;
					case PAUSA:
						if(tecla==SELECT){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							subEstado=IDLE;
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
						}
						else if(tecla==B){
							Estado=MENU;
							consoleClear();
							oamClear(&oamMain, 0, 0);
							oamUpdate(&oamMain);
						}
						break;
					case MUERTE:
						if(tecla==START){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
								DISPLAY_BG2_ACTIVE | // Enable BG2 for display
								DISPLAY_SPR_ACTIVE | // Enable sprites for display
								DISPLAY_SPR_1D       // Enable 1D tiled sprites
								);
							subEstado=IDLE;
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
						}
						else if(tecla==B){
							videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
								DISPLAY_BG2_ACTIVE | // Enable BG2 for display
								DISPLAY_SPR_ACTIVE | // Enable sprites for display
								DISPLAY_SPR_1D       // Enable 1D tiled sprites
								);
							Estado=MENU;
							subEstado=IDLE;
							consoleClear();
							oamClear(&oamMain, 0, 0);
							oamUpdate(&oamMain);
						}
					case VICTORIA:
						if(tecla==START){ //Salir de la pausa, habilitando las interrupciones y reanudando el temporizador
							videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
								DISPLAY_BG2_ACTIVE | // Enable BG2 for display
								DISPLAY_SPR_ACTIVE | // Enable sprites for display
								DISPLAY_SPR_1D       // Enable 1D tiled sprites
								);
							subEstado=IDLE;
							consoleClear();
							HabilitarIntTeclado();
							HabilitarIntTempo();
							PonerEnMarchaTempo();
						}
						else if(tecla==B){
							videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
								DISPLAY_BG2_ACTIVE | // Enable BG2 for display
								DISPLAY_SPR_ACTIVE | // Enable sprites for display
								DISPLAY_SPR_1D       // Enable 1D tiled sprites
								);
							Estado=MENU;
							subEstado=IDLE;
							consoleClear();
							oamClear(&oamMain, 0, 0);
							oamUpdate(&oamMain);
					}
					default:
						break;
				}
				
				break;
			case STATS:
				if(!TeclaDetectada()) break;
				tecla = TeclaPulsada();
				break;  
		}
		
	}
}

