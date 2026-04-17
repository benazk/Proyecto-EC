

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"


u16* gfxpersonaje;
u16* florSuelo;

/* Reservar memoria para cada sprite que se quiera mostrar en pantalla */
void memoriaReserva(){
	/* Por cada sprite que se quiera incluir en la pantalla principal hay que hacer algo equivalente a lo que sigue */
	gfxpersonaje= oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	florSuelo = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un píxel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES */
void EstablecerPaletaPrincipal(int spriteID) {
	switch(spriteID){
		case PERSONAJE:
			SPRITE_PALETTE[0] = RGB15(0,0,0);
			SPRITE_PALETTE[1] = RGB15(4,3,6);
			SPRITE_PALETTE[2] = RGB15(31,31,31);
			SPRITE_PALETTE[3] = RGB15(0,0,0);
			SPRITE_PALETTE[4] = RGB15(27,13,4);
			break;
		case FLOR_SUELO:
			SPRITE_PALETTE[0] = RGB15(12,23,5);
			SPRITE_PALETTE[1] = RGB15(30,29,6);
			SPRITE_PALETTE[2] = RGB15(17,17,0);
			SPRITE_PALETTE[3] = RGB15(18,27,9);
			break;
	}
}
void EstablecerPaletaSecundaria() {}
/* Definición de un sprite de 16x16 píxeles para dibujar un rombo */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho */

u8 personajeMap[1024] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,

	0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,3,2,3,0,0,2,2,2,3,3,3,

	0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,1,1,0,0,0,2,2,0,0,1,0,0,0,3,2,0,0,1,0,0,0,2,2,0,0,1,0,0,0,3,2,0,0,0,1,0,0,2,2,0,0,0,1,0,0,

	0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,4,4,0,0,0,1,0,4,4,4,0,0,1,4,4,4,4,4,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,

	0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,4,4,4,4,4,2,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,

	2,2,0,0,0,1,0,0,2,0,0,0,0,1,0,0,2,0,0,0,0,1,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,4,4,4,4,4,4,1,0,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,1,

	0,0,4,4,4,4,4,4,0,0,1,4,4,4,4,4,0,0,4,4,4,4,4,4,0,0,4,4,4,4,4,3,0,0,1,4,4,1,3,3,0,0,1,1,1,0,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,

	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,3,3,3,4,4,4,4,4,2,2,3,3,1,1,1,1,2,2,3,3,0,0,0,0,3,3,3,0,0,0,0,0,3,3,0,0,0,0,0,0,

	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,4,4,4,4,4,3,3,3,3,4,4,4,1,3,2,2,3,3,1,1,1,3,2,2,3,3,1,0,0,3,3,3,3,0,0,0,0,0,3,3,0,0,0,0,0,
};
u8 tileFlor[1024] = {
	1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,2,2,1,1,0,0,1,1,2,2,1,1,0,0,0,1,1,1,1,0,

	0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,1,1,2,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,2,2,1,1,0,

	2,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,

	0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	
	0,1,1,2,2,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
	0,0,1,1,1,1,0,0,0,1,1,2,2,1,1,0,0,1,1,2,2,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,2,2,
	
	0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	
	1,0,0,0,0,0,0,0,1,1,0,0,0,0,3,0,2,1,1,0,0,0,0,0,2,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
	0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,
	
	0,0,0,0,1,1,2,2,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,2,
	
	1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,2,0,0,0,0,0,1,1,2,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,2,1,1,0,0,0,0,0,
};


/* Carga en memoria cada uno de los sprites que hemos dibujado */

void GuardarSpritesMemoria(u16* gfxpoint, u8* bitMap, int spriteSize){ 
	int i;
	switch(spriteSize){
		case SPRITE32:
			for(i = 0; i < 32 * 32 / 2; i++) {	
				gfxpoint[i] = bitMap[i*2] | (bitMap[(i*2)+1]<<8);				
			}
			break;
	}
	
}

/* Esta función dibuja un personaje en la posición x, y de pantalla. A cada personaje que se quiera mostrar en pantalla se le debe asignar un índice distinto, un valor entre 0 y 126 */

void MostrarSprite(int indice, int x, int y, int spriteSize, u16* gfxpoint){ 
	switch(spriteSize){
		case SPRITE32:
			oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_32x32,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,   // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			false,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			);  
		break;
		case SPRITE16:
			oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,   // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			false,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			); 
		break;
		case SPRITE64:
			oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_64x64,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,   // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			false,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			);  
		break;

	}
}
void BorrarSprite(int indice, int x, int y, int spriteSize, u16* gfxpoint){
	switch(spriteSize){
		case SPRITE32:
		oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_32x32,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,  // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			true,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			); 
			break;
		case SPRITE16:
			oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,  // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			true,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			); 

			break;
		case SPRITE64: 
			oamSet(&oamMain, // main graphics engine context
			indice,           // oam index (0 to 127)  
			x, y,   // x and y pixel location of the sprite
			0,                    // priority, lower renders last (on top)
			0,			  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_64x64,     
			SpriteColorFormat_256Color, 
			gfxpoint,// +16*16/2,  // pointer to the loaded graphics
			-1,                  // sprite rotation data  
			false,               // double the size when rotating?
			true,			// hide the sprite?
			false, false, // vflip, hflip
			false	// apply mosaic
			); 
			
	}

}




