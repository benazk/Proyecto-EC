


#include <nds.h> 		// Librería de la NDS
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

Prota personaje;

void initStructs(){
	personaje.x = 96;
	personaje.y = 32;
}


int tiempo;
int tecla;
int spriteIndice;
void juego(){
	
	initStructs();
	Estado=MENU;
	
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	ConfigurarTeclado(0x4000 | 0x03FF);

	int latch = 58982;//(int)(65536 - (33554432/1024)*1/5);
	int timer_control = 0x0043;
	ConfigurarTemporizador(latch, timer_control);

	EstablecerVectorInt();

	HabilitarIntTeclado();

	HabilitarIntTempo();

	PonerEnMarchaTempo();

	HabilitarInterrupciones();

	
	// Con esta configuración muestra al personaje
	renderMapa(1);
	EstablecerPaletaPrincipal(0);
	GuardarSpritesMemoria(gfxpersonaje, personajeMap, SPRITE32);
	MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje); 
	oamUpdate(&oamMain);
	
	while(1){
		switch(Estado){
			case MENU:
				tecla = -1;
				break;
			case JUEGO:
				break;
			case STATS:
				break;
		}
		
	}
}


