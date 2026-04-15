

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
int Estado;
static int tick=0;
static int seg=0;
Prota personaje;
void RutAtencionTeclado (){
	int tecla = TeclaPulsada();
	if (Estado == MENU){	
		if (tecla==DERECHA){
			personaje.x += 32;
			MostrarPersonaje(0,personaje.x, personaje.y);
		}
		if (tecla==IZQUIERDA){
			personaje.x -= 32;
			MostrarPersonaje(0,personaje.x, personaje.y);
		}
		if (tecla==ARRIBA){
			personaje.y -= 32;
			MostrarPersonaje(0,personaje.x, personaje.y);
		}
		if (tecla==ABAJO){
			personaje.y += 32;
			MostrarPersonaje(0,personaje.x, personaje.y);
		}
	}
	
}

void RutAtencionTempo(){
	tick++; 
	if (tick==5){
		seg++;
		iprintf("\x1b[13;5HSegundos que han pasado=%d", seg);
		tick=0;
	}
}

void EstablecerVectorInt(){
	irqSet(IRQ_TIMER0, RutAtencionTempo);
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}


