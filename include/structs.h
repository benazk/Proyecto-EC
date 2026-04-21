
#ifndef STRUCTS_H
#define STRUCTS_H
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>	

typedef struct {
    int x;
    int y;
    bool vivo;
}Prota;

typedef struct {
    int altura;
    float tiempo;
}Nivel;

typedef struct{
    u8* spriteBitMap;
    u16* gfxpoint;
    int spriteID;
    int x;
    int y;
    int spriteSize;
}Tile;

typedef struct{
    int posx;
    int posy;
    u8* spriteBitMap;
    u16* gfxpoint;
    int spriteID;
    int spriteSize;
    void (*GestionPosicion)(int *posx,int *posy);
}Enemigo;


/*typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;
}Stats;*/
#endif