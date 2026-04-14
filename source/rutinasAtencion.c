

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
int Estado;
int seg3;   // Para ver si pasan tres segundos

void RutAtencionTeclado (){
	if (Estado == MENU){	
		if (TeclaPulsada()==A){
			MostrarPersonaje(1, 5, 5);
		}
	}
	iprintf("\x1b[0;5H Deberia de generarse el personaje");
}

void RutAtencionTempo(){
	static int tick=0;
	static int seg=0;

	if (Estado!=MENU){
		tick++; 
		if (tick==5)
		{
			seg++;
			iprintf("\x1b[13;5HSegundos que han pasado=%d", seg);
			tick=0;
			if (Estado == MENU)
			{
				seg3++;
				if (seg3==3)
				{
					seg3=0;
				}
			}
					
		}
	}
}

void EstablecerVectorInt(){
	irqSet(IRQ_TIMER0, RutAtencionTempo);
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}


