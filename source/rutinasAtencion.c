

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
#include "maps.h"
#include "gestionEntidades.h"
int Estado;
static int tick=0;
static int seg=0;
static float moverEntidad=1.0f;
extern Prota personaje;

void RutAtencionTeclado (){
	int tecla = TeclaPulsada(); //Función de perifericos.c que mira que bit de TECLAS_DAT está activo
	if (Estado == JUEGO){ //Las variables en mayúsculas van a ser elementos de enums
		iprintf("\x1b[0;0H scroll vertical: %d", scrollY);
		if (tecla==DERECHA && personaje.x < 224){ // Gestiona cuando el usuario pulsa DERECHA
			personaje.x += 32; 
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0); //Esto es mayormente estático, ya que estoy mostrando siempre al personaje y siempre tiene el mismo id de sprite
			oamUpdate(&oamMain);
		}
		if (tecla==IZQUIERDA && personaje.x > 0){
			personaje.x -= 32;
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
		if (tecla==ARRIBA && personaje.y > 0){
			if(personaje.y < 159 && scrollY < 16) scrollY++;
			else personaje.y -= 32;
			renderMapa(1);
			
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, SPRITE32, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
		if (tecla==ABAJO && personaje.y < 160 ){
			if(personaje.y > 33 && scrollY > 0) scrollY--;
			else personaje.y += 32;
			renderMapa(1);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje, 0);
			oamUpdate(&oamMain);
		}
	}
	//iprintf("\x1b[23;0H Tecla %d", tecla);
	
}

float Lerp(float start, float end, float amount){ // No prestar atención
    float result = start + amount*(end - start);
    return result;
}

void RutAtencionTempo(){ // Para gestionar cada tick del temporizador
	moverEntidad -= 0.2f;
	//float alpha_range = (1.0f - moverEntidad) / 1.0f;
	if(moverEntidad==0.0f) moverEntidad=1.0f;
	switch(Estado){
		case MENU:
			break;
		case JUEGO:
			if(Estado==PAUSA) break;
			//enemigo.posx = Lerp(enemigo.posx, enemigo.posx + 32, alpha_range);
			movEnemigo();
			//renderMapa(1);
			oamUpdate(&oamMain);
	}
}

void EstablecerVectorInt(){ // Para asignarle a cada tipo de interrupción su rutina de atención específica
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencionTempo);
}


