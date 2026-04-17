

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
int Estado;
static int tick=0;
static int seg=0;
Prota personaje;
void RutAtencionTeclado (){
	int tecla = TeclaPulsada();
	if (Estado == MENU){	
		if (tecla==DERECHA){
			EstablecerPaletaPrincipal(0);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			personaje.x += 32;
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje); //Esto es mayormente estático, ya que estoy mostrando siempre al personaje y siempre tiene el mismo id de sprite
			oamUpdate(&oamMain);
		}
		if (tecla==IZQUIERDA){
			EstablecerPaletaPrincipal(0);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			personaje.x -= 32;
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje);
			oamUpdate(&oamMain);
		}
		if (tecla==ARRIBA){
			EstablecerPaletaPrincipal(0);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			personaje.y -= 32;
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje);
			oamUpdate(&oamMain);
		}
		if (tecla==ABAJO){
			EstablecerPaletaPrincipal(0);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			personaje.y += 32;
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje);
			oamUpdate(&oamMain);
		}
	}
	//iprintf("\x1b[23;0H Tecla %d", tecla);
	
}

void RutAtencionTempo(){
	tick++; 
	if (tick==5){
		seg++;
		//iprintf("\x1b[5;5H %dseg(s)", seg);
		tick=0;
	}
}

void EstablecerVectorInt(){
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencionTempo);
}


