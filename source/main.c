

#include <nds.h> 
#include <nds/arm9/console.h>		// Librerías de la NDS
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto

#include "graficos.h"
#include "definiciones.h"
#include "sprites.h"
#include "juego.h"


int main(void) {
 	consoleDemoInit();
	inicializarGraficosSprites();
	juego();

	return 0;

}


