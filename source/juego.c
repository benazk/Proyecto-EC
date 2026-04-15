


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
Prota personaje;


void initStructs(){
	personaje.x = 96;
	personaje.y = 32;
}


int tiempo;
int tecla;
void juego(){
	initStructs();
	MostrarPersonaje(0,personaje.x, personaje.y);
	Estado=MENU;
	
        // LLAMADAS A REALIZAR (ORDEN RECOMENDADO):
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.


	ConfigurarTeclado(0x4000 | 0x03FF);
	int latch = (int)(65536 - (33554432/1024)*1/1);
	int timer_control = 0x00FF;
	ConfigurarTemporizador(latch, timer_control);

	while(1){
		switch(Estado){
			case MENU:
				if(TeclaDetectada()){
					tecla=TeclaPulsada();
					iprintf("\x1b[23;1H %d", tecla);	
				}
				else tecla = -1;
				break;
			case JUEGO:
				break;
			case STATS:
				break;
		}
	}
}


