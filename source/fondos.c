// Curso 2025-2026

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "fondoMuerte.h" //Generado con grit
#include "fondoVictoria.h" //Generado con grit


/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

void visualizarFondoMuerte() {
    //dmaCopyHalfWords(3, fondoMuertePal, BG_PALETTE, fondoMuertePalLen);
	dmaCopyHalfWords(DMA_CHANNEL,
                     fondoMuerteBitmap, // Variable que se genera automáticamente 
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
                     fondoMuerteBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarFondoVictoria() {
    //dmaCopyHalfWords(3, fondoVictoriaPal, BG_PALETTE, fondoVictoriaPalLen);
	dmaCopyHalfWords(DMA_CHANNEL,
                     fondoVictoriaBitmap, // Variable que se genera automáticamente 
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
                     fondoVictoriaBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void initBackgrounds() {
    /*  Set up affine background 3 on main as a 16-bit color background. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // The starting place in memory
                 BG_PRIORITY(0); // A low priority

    /*  Set the affine transformation matrix for the main screen background 3
     *  to be the identity matrix.
     */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

    /*  Place main screen background 3 at the origin (upper left of the
     *  screen).
     */
    REG_BG3X = 0;
    REG_BG3Y = 0;




    /*  Set up affine background 2 on main as a 16-bit color background. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // The starting place in memory
                 BG_PRIORITY(2);  // A higher priority
    /*  Set the affine transformation matrix for the main screen background 2
     *  to be the identity matrix.
     */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;
    /*  Place main screen background 2 in an interesting place. */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;



    /*  Set up affine background 3 on the sub screen as a 16-bit color
     *  background.
     */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // The starting place in memory
                     BG_PRIORITY(3); // A low priority
    /*  Set the affine transformation matrix for the sub screen background 3
     *  to be the identity matrix.
     */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;
    /*
     *  Place main screen background 3 at the origin (upper left of the screen)
     */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
}
            