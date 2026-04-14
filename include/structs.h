#include <nds.h>
#include <stdio.h
#include <stdlib.h>	
#include <unistd.h>	

typedef struct {
    NDS sprite;
    int x;
    int y;
    bool vida;
}Prota;

typedef struct {

}Sprite32;

typedef struct {
    int monedas;
    int nivelNum;
    Nivel *nivActual;

}Stats;

typedef struct {
    int altura;
    float tiempo;
    
}Nivel;