
#ifndef SPRITES_H
#define SPRITES_H

#include <nds.h>

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

// Estas variables son punteros a espacios de memoria que guardarán los sprites
u16* gfxpersonaje;
u16* gfxCoche;
u16* florSuelo;
u16* aguaSuelo;
u16* metaSuelo;
u16* monedaSuelo;
u16* gfxCoche2;
u16* sueloSuelo;
u16* aguaSuelo2;
extern void memoriaReserva();

extern void EstablecerPaletaPrincipal(int spriteID);
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */


extern void EstablecerPaletaSecundaria();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */


extern void GuardarSpritesMemoria(u16* gfxpoint, u8* bitMap, int spriteSize);
/* Carga en memoria los Sprites dibujados */

extern void MostrarSprite(int indice, int x, int y, int spriteSize, u16* gfxpoint, int zIndex);

extern void BorrarSprite(int indice, int x, int y, int spriteSize, u16* gfxpoint, int zIndex);

extern u8 personajeMap[1024];
extern u8 cocheMap[1024];
extern u8 tileFlor[1024];
extern u8 tileAgua[1024];
extern u8 metaTile[1024];
extern u8 monedaTile[1024];
extern u8 tileAgua2[1024];
extern u8 tileSuelo[1024];
extern u8 tileFlor2[1024];

#endif
