#include <nds.h> 		// Librería de la NDS
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos


#define IME		(*(vuint32*)0x04000208) // Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) // Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) // Interrupt Flag -- Registro de solicitud de interrupción

// Funciones para el tratamiento general de las interrupciones
#define HabilitarInterrupciones() IME=1 // Habilitar todas las interrupciones
#define DeshabilitarInterrrupciones() IME=0 // Deshabilitar todas las interrupciones

// Registros del teclado
#define TECLAS_DAT	(*(vu16*)0x4000130) // Registro de datos del teclado
#define TECLAS_CNT	(*(vu16*)0x4000132) // Registro de control del teclado

// Registros del temporizador Timer0
#define TIMER0_CNT   (*(vuint16*)0x04000102) // Registro de control del temporizador
#define TIMER0_DAT    (*(vuint16*)0x04000100) // Registro de datos del temporizador

extern int tecla;

// Acceso a los registros de la pantalla táctil
extern touchPosition PANT_DAT;

// Nombres asignados a las teclas para facilitar la comprensión de nuestro código
extern const enum teclas{
    A=0, 
    B=1,
    SELECT=2,
    START=3,
    DERECHA=4, 
    IZQUIERDA=5,
    ARRIBA=6, 
    ABAJO=7,
    R=8,
    L=9
}teclas;

extern const enum direccion{NORTE=0, ESTE=1, SUR=2, OESTE=3} direc;


// Enums asignados a los estados y subestados (Automatas)
extern const enum estadosJuego{ MENU=0, JUEGO=1, STATS=2} estadosJuego;
extern const enum subEstadosJuego{ IDLE=0, MOVIENDO=1, HIT=2, PAUSA=3} subEstadosJuego;

extern const enum spritesId{ 
    PERSONAJE=0,
    FLOR_SUELO=1,
    AGUA_SUELO=2,
    COCHE_SPRITE=3,
} spritesId; // Para asignar cada sprite con un switch-case dependiendo del sprite necesario.

extern const enum spriteSizes{ SPRITE_CUSTOM=0, SPRITE32=1, SPRITE16=2, SPRITE64=3}spriteSizes; // Para asignar tamaños de sprites tambien con un switch-case
int Estado; // Este es el estado de la partida
int subEstado; // Este es el sub estado de la partida
int scrollY;
int spriteIndice;
#define MAX_ENEMIGOS 12
