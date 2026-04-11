


#include <nds.h> 		// Librería de la NDS
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"

int tiempo;

void juego()
{

	Estado=MENU;
	// Escribe en la fila 22 columna 5 de la pantalla
	iprintf("\x1b[22;5HPrueba de escritura");

	
        // LLAMADAS A REALIZAR (ORDEN RECOMENDADO):
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.


	ConfigurarTeclado(0x4000 | (1 << 3));
	int seg;
	int latch = (int)(65536 - (33554432/1024)/5);
	int timer_control = 0x0060;
	ConfigurarTemporizador(latch, timer_control);
	int tecla = 0;
	while(1){
		switch(Estado){
			case MENU:
				tecla=TeclaPulsada();
				if(tecla==START){

					visualizarPuerta();
					seg=0;
					PonerEnMarchaTempo();
				}
				else{
				iprintf("\x1b[23;5H Se pulsa %d", tecla);
				}
				break;
			case JUEGO:
				break;
			case STATS:
				break;
		}
		DeshabilitarInterrrupciones();
	}
}


