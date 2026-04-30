

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
#include "maps.h"
#include "gestionEntidades.h"
int Estado;
static int tick=0;
static int seg=0;
static float moverEntidad=1.0f;
extern Prota personaje;

void RutAtencionTeclado (){
	DeshabilitarInterrrupciones();
	int tecla = TeclaPulsada(); //Función de perifericos.c que mira que bit de TECLAS_DAT está activo
	if (Estado == JUEGO){ //Las variables en mayúsculas van a ser elementos de enums
		//iprintf("\x1b[0;0H scroll vertical: %d", scrollY);
		
		if (tecla==DERECHA && personaje.x < 224){ // Gestiona cuando el usuario pulsa DERECHA
			personaje.x += 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa++;
			map1[personaje.posEnMapa].estaPersonaje = true;
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0); //Esto es mayormente estático, ya que estoy mostrando siempre al personaje y siempre tiene el mismo id de sprite
			oamUpdate(&oamMain);
		}
		if (tecla==IZQUIERDA && personaje.x > 0){
			personaje.x -= 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa--;
			map1[personaje.posEnMapa].estaPersonaje = true;
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
		if (tecla==ARRIBA && personaje.y > 0){
			if(personaje.y < 159 && scrollY < 16) scrollY++;
			else personaje.y -= 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa+=8;
			map1[personaje.posEnMapa].estaPersonaje = true;
			
			int res = personaje.x % 32;
			iprintf("\x1b[9;0H resto de %d y hay agua? %d", res, map1[personaje.posEnMapa].spriteID == AGUA_SUELO);
			if(personaje.enBarca &&  res != 0 && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) { // Si al salir de la barca,y el sprite no esta alineado con la tile (personaje.x mod spriteSize)
				iprintf("\x1b[10;0H Alineacion de %d a %d", personaje.x - res, personaje.x + (32 - res));
				if(personaje.x % 32 > 16){ // Con respecto a la izquierda de la tile
					personaje.posEnMapa++;
					personaje.x = personaje.x  + (32 - res/*para llegar a lo que queda del resto de 32*/) % 32; // Esto alinea el personaje con una tile (la más cercana)
				}
				else{
					personaje.posEnMapa--; //En caso de que la tile más cercana esté a la "izquierda"
					personaje.x = personaje.x - res;
				}
			} 
			if(personaje.enBarca && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) personaje.enBarca = false;
			
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, SPRITE32, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
		if (tecla==ABAJO && personaje.y < 160 ){
			if(personaje.y > 33 && scrollY > 0) scrollY--;
			else personaje.y += 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa-=8;
			map1[personaje.posEnMapa].estaPersonaje = true;
			int res = personaje.x % 32;
			iprintf("\x1b[9;0H resto de %d y hay agua? %d", res, map1[personaje.posEnMapa].spriteID == AGUA_SUELO);
			if(personaje.enBarca &&  res != 0 && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) { // Si al salir de la barca,y el sprite no esta alineado con la tile (personaje.x mod spriteSize)
				iprintf("\x1b[10;0H Alineacion de %d a %d", personaje.x - res, personaje.x + (32 - res));
				if(personaje.x % 32 > 16){
					personaje.x = personaje.x + (32 - res/*para llegar a lo que queda del resto de 32*/) % 32;
				}
				else{
					personaje.x = personaje.x - res;
				}
			}
			if(personaje.enBarca && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) personaje.enBarca = false;
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
		iprintf("\x1b[7;0H Indice del mapa personaje: %d", personaje.posEnMapa);
		iprintf("\x1b[8;0H Está en zona caminable?: %d", map1[personaje.posEnMapa].caminable);
	}
	//iprintf("\x1b[23;0H Tecla %d", tecla);
	HabilitarInterrupciones();
}

float Lerp(float start, float end, float amount){ // No prestar atención
    float result = start + amount*(end - start);
    return result;
}

void RutAtencionTempo(){ // Para gestionar cada tick del temporizador, serán 20 ticks/s si estamos en el juego
	DeshabilitarInterrrupciones();
	moverEntidad -= 0.2f;
	//float alpha_range = (1.0f - moverEntidad) / 1.0f;
	if(moverEntidad==0.0f) moverEntidad=1.0f;
	switch(Estado){
		case MENU:
			break;
		case JUEGO:
			if(Estado==PAUSA) break;
			//enemigo.posx = Lerp(enemigo.posx, enemigo.posx + 32, alpha_range);
			movEnemigo();
			renderMapa(1);
			oamUpdate(&oamMain);
	}
	HabilitarInterrupciones();
}

void EstablecerVectorInt(){ // Para asignarle a cada tipo de interrupción su rutina de atención específica
	irqSet(IRQ_TIMER0, RutAtencionTempo);
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}


