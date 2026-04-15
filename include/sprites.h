

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaReserva();

extern void EstablecerPaletaPrincipal();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */


extern void EstablecerPaletaSecundaria();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */


extern void GuardarSpritesMemoria();
/* Carga en memoria los Sprites dibujados */



extern void MostrarPersonaje(int indice, int x, int y);

extern void BorrarPersonaje(int indice, int x, int y);



