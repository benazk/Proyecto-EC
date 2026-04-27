#include <nds.h>
#include "gestionEntidades.h"
#include "definiciones.h"
#include "structs.h"
#include "sprites.h"
extern Enemigo *enemigos;

void movEnemigo(){
    int i;
    for(i = 0; i < numEnemigos; i++){
        if(enemigos[i].gestorEnemigo != NULL) {
            iprintf("\x1b[23;0H moviendo enemigo (creo)");
            enemigos[i].gestorEnemigo(&enemigos[i]);
        }
    }
    i = 0;
}
void GM(Enemigo *self){ // Como se mueve de izquierda a derecha y viceversa, tengo una variable dirección y vuelvo a dibujar el sprite cada vez que lo muevo
    if(self->direccion==OESTE) self->posx-=3;
    else if(self->direccion==ESTE) self->posx+=3;
    EstablecerPaletaPrincipal(self->spriteID);
	MostrarSprite(self->spriteIndice, self->posx, self->posy + scrollY*32, self->spriteSize, self->gfxpoint, 1);
}
