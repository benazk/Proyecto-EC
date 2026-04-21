

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "structs.h"
#include "maps.h"
int Estado;
static int tick=0;
static int seg=0;
Prota personaje;
void RutAtencionTeclado (){
	int tecla = TeclaPulsada();
	if (Estado == MENU){
		iprintf("\x1b[0;0H scroll vertical: %d", scrollY);
		if (tecla==DERECHA && personaje.x < 224){
			personaje.x += 32;
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje); //Esto es mayormente estático, ya que estoy mostrando siempre al personaje y siempre tiene el mismo id de sprite
			oamUpdate(&oamMain);
		}
		if (tecla==IZQUIERDA && personaje.x > 0){
			personaje.x -= 32;
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje);
			oamUpdate(&oamMain);
		}
		if (tecla==ARRIBA && personaje.y > 0){
			if(personaje.y < 159 && scrollY < 16) scrollY++;
			else personaje.y -= 32;
			renderMapa(1);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
			MostrarSprite(0,personaje.x, personaje.y, 1, gfxpersonaje);
			oamUpdate(&oamMain);
		}
		if (tecla==ABAJO && personaje.y < 160 ){
			if(personaje.y > 33 && scrollY > 0) scrollY--;
			else personaje.y += 32;
			renderMapa(1);
			GuardarSpritesMemoria(gfxpersonaje, personajeMap, 32);
			EstablecerPaletaPrincipal(0);
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


