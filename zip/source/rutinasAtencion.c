

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
extern Prota personaje;

void RutAtencionTeclado (){
	InhibirIntTempo();
	ActualizarTeclado();
	int tecla = TeclaPulsada(); //Función de perifericos.c que mira que bit de TECLAS_DAT está activo
	switch(Estado){ //Las variables en mayúsculas van a ser elementos de enums
		case MENU: // Las teclas que se usan en el menú son todas por encuesta (No haremos la B, START y SELECT por interrupción)
			break;

		case JUEGO:
		if(subEstado==PAUSA || subEstado==MUERTE) break;
		if (tecla==DERECHA && personaje.x < 224){ // Gestiona cuando el usuario pulsa DERECHA
			personaje.x += 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa++;
			map1[personaje.posEnMapa].estaPersonaje = true;
			estaPersonaje();
			if(!subirBarca && map1[personaje.posEnMapa].spriteID != AGUA_SUELO)
				subirBarca = false;

		}
		else if (tecla==IZQUIERDA && personaje.x > 0){
			personaje.x -= 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa--;
			map1[personaje.posEnMapa].estaPersonaje = true;
			estaPersonaje();
		}
		else if (tecla==ARRIBA && personaje.y > 0){
			if(personaje.y < 159 && scrollY < personaje.estadisticas->nivActual->altura) scrollY++;
			else personaje.y -= 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa+=8;
			map1[personaje.posEnMapa].estaPersonaje = true;
			
			int res = personaje.x % 32;
			if(subirBarca &&  res != 0 && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) { // Si al salir de la barca,y el sprite no esta alineado con la tile (personaje.x mod spriteSize)
				if(personaje.x % 32 > 16){ // Con respecto a la izquierda de la tile
					personaje.posEnMapa++;
					personaje.x = personaje.x  + (32 - res/*para llegar a lo que queda del resto de 32*/) % 32; // Esto alinea el personaje con una tile (la más cercana)
				}
				else{
					personaje.posEnMapa--; //En caso de que la tile más cercana esté a la "izquierda"
					personaje.x = personaje.x - res;
				}
			} 
			estaPersonaje();
		}
		else if (tecla==ABAJO && personaje.y < 160 ){
			if(personaje.y > 33 && scrollY > 0) scrollY--;
			else personaje.y += 32;
			map1[personaje.posEnMapa].estaPersonaje = false;
			personaje.posEnMapa-=8;
			map1[personaje.posEnMapa].estaPersonaje = true;
			int res = personaje.x % 32;
			if(subirBarca &&  res != 0 && map1[personaje.posEnMapa].spriteID != AGUA_SUELO) { // Si al salir de la barca,y el sprite no esta alineado con la tile (personaje.x mod spriteSize)
				if(personaje.x % 32 > 16){
					personaje.x = personaje.x + (32 - res/*para llegar a lo que queda del resto de 32*/) % 32;
				}
				else{
					personaje.x = personaje.x - res;
				}
			}
			estaPersonaje();
		}
		//iprintf("\x1b[7;0H Indice del mapa personaje: %d", personaje.posEnMapa);
		//iprintf("\x1b[8;0H Posicion Personaje: (%d,%d)", personaje.x, personaje.y);
		break;
	}
	HabilitarIntTempo();
}

float Lerp(float start, float end, float amount){ // No prestar atención
    float result = start + amount*(end - start);
    return result;
}

void RutAtencionTempo(){ // Para gestionar cada tick del temporizador, serán 20 ticks/s si estamos en el juego
	InhibirIntTeclado();
	switch(Estado){
		case MENU:
			break;
		case JUEGO:
			if(subEstado==PAUSA || subEstado==MUERTE) break;
			movEnemigo();
			renderMapa(personaje.estadisticas->nivelNum);
			oamUpdate(&oamMain);
	}
	HabilitarIntTeclado();
	
}

void EstablecerVectorInt(){ // Para asignarle a cada tipo de interrupción su rutina de atención específica
	irqSet(IRQ_TIMER0, RutAtencionTempo);
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}


