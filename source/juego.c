


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
#include "gestionEntidades.h"

Prota personaje;

Enemigo enemigos[MAX_ENEMIGOS];
int numEnemigos = 0;


int tiempo;
int tecla;
extern int spriteIndice;
extern int scrollY;

void initStructs(){ //Esto pone valores por defecto a structs estaticos con una sola instancia y a algunas variables
	personaje.x = 96;
	personaje.y = 160;
	scrollY = 0;
}




void juego(){
	spriteIndice = 1; // No está en 0 ya que el personaje es el indice 0
	initStructs();
	Estado=JUEGO;
	
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	ConfigurarTeclado(0x4000 | 0x03FF);

	int latch = 58982;//(int)(65536 - (33554432/1024)*1/5); 5 interrupciones por segundo, 5 ticks/s
	int timer_control = 0x0043;

	ConfigurarTemporizador(latch, timer_control);

	EstablecerVectorInt();

	HabilitarIntTeclado();

	HabilitarIntTempo();

	PonerEnMarchaTempo();

	HabilitarInterrupciones();

	
	// Con esta configuración muestra al personaje y el mapa
	renderMapa(1);
	EstablecerPaletaPrincipal(0);
	GuardarSpritesMemoria(gfxpersonaje, personajeMap, SPRITE32);
	MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0); 
	oamUpdate(&oamMain);
	
	while(1){ //Bucle del juego
		switch(Estado){
			case MENU:
				break;
			case JUEGO:
				break;
			case STATS:
				break;
		}
		
	}
}

bool VerificarColision(int x1, int x2, int y1, int y2, int width1, int width2, int height1, int height2){ // Sirve para saber si ha habido una colisión entre dos entidades
    bool collision = false;
    if ((x1 < (x2 + width2) && (x1 + width1) > x2) &&
        (y1 < (y2 + height2) && (y1 + height1) > y2)) collision = true;
    return collision;
}




void spawnEnemigo(int x, int y, int tipoEnemigo, int dir) { // Pone un enemigo en el array de enemigos 
	
    if (numEnemigos >= MAX_ENEMIGOS) return;
    Enemigo *e = &enemigos[numEnemigos++];
    e->posx = x;
    e->posy = y;
	e->spriteID = tipoEnemigo;
    e->gestorEnemigo = GM;
	e->direccion = dir;
	switch(tipoEnemigo){
		case COCHE_SPRITE:
			e->gfxpoint = gfxCoche;
			e->spriteBitMap = cocheMap;
			e->spriteSize = SPRITE32;
			break;
	}
	EstablecerPaletaPrincipal(tipoEnemigo);
	e->spriteIndice = spriteIndice;
	MostrarSprite(spriteIndice, e->posx, e->posy + scrollY*32, e->spriteSize, e->gfxpoint, 1);
	spriteIndice++; 
}