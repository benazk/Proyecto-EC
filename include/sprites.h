
#ifndef SPRITES_H
#define SPRITES_H
#include <nds.h>

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern u16* gfxpersonaje;
extern u16* gfxCoche;
extern u16* florSuelo;
extern u16* aguaSuelo;

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
#endif
