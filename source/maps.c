#include <nds.h>
#include "sprites.h"
u16* florSuelo;
u8* tileFlor;
Tile tileflor

Tile map1[48] = {
    (Tile){tileFlor, florSuelo, 1, 0, 0}, (Tile){tileFlor, florSuelo, 1, 0, 32}, (Tile){tileFlor, florSuelo, 1, 0, 64}, 
    (Tile){tileFlor, florSuelo, 1, 0, 96}, (Tile){tileFlor, florSuelo, 1, 0, 128}, (Tile){tileFlor, florSuelo, 1, 0, 160},

    (Tile){tileFlor, florSuelo, 1, 32, 0}, (Tile){tileFlor, florSuelo, 1, 32, 32}, (Tile){tileFlor, florSuelo, 1, 32, 64}, 
    (Tile){tileFlor, florSuelo, 1, 32, 96}, (Tile){tileFlor, florSuelo, 1, 32, 128}, (Tile){tileFlor, florSuelo, 1, 32, 160},
    
    (Tile){tileFlor, florSuelo, 1, 64, 0}, (Tile){tileFlor, florSuelo, 1, 64, 32}, (Tile){tileFlor, florSuelo, 1, 64, 64}, 
    (Tile){tileFlor, florSuelo, 1, 64, 96}, (Tile){tileFlor, florSuelo, 1, 64, 128}, (Tile){tileFlor, florSuelo, 1, 64, 160},
    
    (Tile){tileFlor, florSuelo, 1, 96, 0}, (Tile){tileFlor, florSuelo, 1, 96, 32}, (Tile){tileFlor, florSuelo, 1, 96, 64}, 
    (Tile){tileFlor, florSuelo, 1, 96, 96}, (Tile){tileFlor, florSuelo, 1, 96, 128}, (Tile){tileFlor, florSuelo, 1, 96, 160},
    
    (Tile){tileFlor, florSuelo, 1, 128, 0}, (Tile){tileFlor, florSuelo, 1, 128, 32}, (Tile){tileFlor, florSuelo, 1, 128, 64}, 
    (Tile){tileFlor, florSuelo, 1, 128, 96}, (Tile){tileFlor, florSuelo, 1, 128, 128}, (Tile){tileFlor, florSuelo, 1, 128, 160},
    
    (Tile){tileFlor, florSuelo, 1, 160, 0}, (Tile){tileFlor, florSuelo, 1, 160, 32}, (Tile){tileFlor, florSuelo, 1, 160, 64},
    (Tile){tileFlor, florSuelo, 1, 160, 96}, (Tile){tileFlor, florSuelo, 1, 160, 128}, (Tile){tileFlor, florSuelo, 1, 160, 160},
    
    (Tile){tileFlor, florSuelo, 1, 192, 0}, (Tile){tileFlor, florSuelo, 1, 192, 32}, (Tile){tileFlor, florSuelo, 1, 192, 64},
    (Tile){tileFlor, florSuelo, 1, 192, 96}, (Tile){tileFlor, florSuelo, 1, 192, 128}, (Tile){tileFlor, florSuelo, 1, 192, 160},
    
    (Tile){tileFlor, florSuelo, 1, 224, 0}, (Tile){tileFlor, florSuelo, 1, 224, 32}, (Tile){tileFlor, florSuelo, 1, 224, 64},
    (Tile){tileFlor, florSuelo, 1, 224, 96}, (Tile){tileFlor, florSuelo, 1, 224, 128}, (Tile){tileFlor, florSuelo, 1, 224, 160},
}
memoriaReserva() u16* gfx;
EstablecerPaletaPrincipal(int spriteID)
GuardarSpritesMemoria() u8 personaje[1024]
MostrarPersonaje(int indice, int x, int y, u16* gfxpoint) u16* gfx;