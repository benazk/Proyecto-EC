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
    u16* palette;
    int x;
    int y;
}Tile;

/*typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;
}Stats;*/