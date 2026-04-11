
#include <nds.h>
#include <stdio.h>
#include "definiciones.h"


int tecla; // Variable para guardar la tecla pulsada; valorar si es necesaria



int TeclaDetectada() {
	if ((~TECLAS_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int TeclaPulsada(){
	int i;
	for(i = 0; i<10;i++){
	    if(!(TECLAS_DAT & (2^i))) return i;
	}
}

void ConfigurarTeclado(int Conf_Tec){
	// Configuración del teclado. Modificar su registro de control en base a los bits
	TECLAS_CNT=Conf_Tec;
        // activados en el parametro Conf_Tec
	
}

void ConfigurarTemporizador(int Latch, int Conf_Tempo){
	TIMER0_DAT = Latch;      
    TIMER0_CNT = Conf_Tempo;
}

void HabilitarIntTeclado(){
	DeshabilitarInterrrupciones();
    IE |= (1 << 12);
    HabilitarInterrupciones();
}

void InhibirIntTeclado()
{
	DeshabilitarInterrrupciones();
    IE &= ~(1 << 12);
    HabilitarInterrupciones();
}  

void HabilitarIntTempo(){

	DeshabilitarInterrrupciones();
    IE |= (1 << 3);  // Poner a 1 el bit 3
    HabilitarInterrupciones();	
}
void InhibirIntTempo(){
	// Deshabilitar las interrupciones del temporizador (timer0)
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación, 
	// y después volver a habilitar las interrupciones de forma general 
	DeshabilitarInterrrupciones(); // IME=0;
	IE &= ~(1 << 3);
	HabilitarInterrupciones(); // IME=1;

}

void PonerEnMarchaTempo(){	
	DeshabilitarInterrrupciones();
    TIMER0_CNT |= (1 << 7);  // Poner a 1 el bit 7
    HabilitarInterrupciones();	
}

void PararTempo(){
	DeshabilitarInterrrupciones();
    TIMER0_CNT &= ~(1 << 7);  // Poner a 1 el bit 7
    HabilitarInterrupciones();	
	
}


