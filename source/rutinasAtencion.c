// Curso 2025-2026

/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

int ESTADO; // Para controlar el estado del autómata en que esté
int seg3;   // Para ver si pasan tres segundos

void RutAtencionTeclado (){
	if (ESTADO == CERRADA){	
		if (TeclaPulsada()==A)
		{
			ESTADO=ABIERTA;
			visualizarPuertaAbierta();
			seg3=0;
			MostrarRombo(1, 5, 5);
			MostrarRomboGrande(2, 100, 100);
		}
	}
}

void RutAtencionTempo(){
	static int tick=0;
	static int seg=0;

	if (ESTADO!=ESPERA){
		tick++; 
		if (tick==5)
		{
			seg++;
			iprintf("\x1b[13;5HSegundos que han pasado=%d", seg);
			tick=0;
			if (ESTADO == ABIERTA)
			{
				seg3++;
				if (seg3==3)
				{
					visualizarPuerta();
					seg3=0;
					ESTADO=CERRADA;
					BorrarRombo(1, 5, 5);
					BorrarRomboGrande(2, 100, 100);
				}
			}
					
		}
	}
}

void EstablecerVectorInt(){
	// Para el Timer 0
	irqSet(IRQ_TIMER0, RutAtencionTempo);
	// Para el Teclado
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}

/***********************2025-2026*******************************/

