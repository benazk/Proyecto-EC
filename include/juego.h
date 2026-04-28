
void juego();
bool outOfBounds(); //Si una entidad con stats, movimiento etc se sale de la pantalla, despawnea (para no gastar recursos)
void spawnEnemigo(int x, int y, int tipoEnemigo, int dir);  // Como el nombre indica, se ocupa de spawnear el enemigo
bool VerificarColision(int x1, int x2, int y1, int y2, int width1, int width2, int height1, int height2, int a);
