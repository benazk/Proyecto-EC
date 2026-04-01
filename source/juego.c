// Curso 2025-2026

/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


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

	ESTADO=ESPERA;
	// Escribe en la fila 22 columna 5 de la pantalla
	iprintf("\x1b[22;5HPrueba de escritura");

	//******************************* EN LA 2.ACTIVIDAD ********************************//
        // LLAMADAS A REALIZAR (ORDEN RECOMENDADO):
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	//******************************************************************************//

	ConfigurarTeclado(0x4000 | (1 << 3));
	int seg;
	int latch = (int)(65536 - (33554432/1024)/5);
	int timer_control = 0x0060;
	ConfigurarTemporizador(latch, timer_control);
	int tecla = 0;
	while(1)
	{

      /*******************************EN LA 1.ACTIVIDAD *****************************************/
		/* Si el estado es ESPERA: codificar aquí la encuesta del teclado, sacar por pantalla la tecla que se ha pulsado, y si se pulsa la tecla START cambiar de estado */
	if(ESTADO==ESPERA)
	    tecla=TeclaPulsada();
	    if(tecla==START){

			visualizarPuerta();
			seg=0;
	        ESTADO=CERRADA;
			PonerEnMarchaTempo();
	    }
	    else{
		iprintf("\x1b[23;5H Se pulsa %d", tecla);
	    }
	}
	DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
}

/***********************2025-2026*******************************/


