#ifndef HELPERS_H
#define HELPERS_H

// konstanta definujuca rozmer mriezky s lodami
#define GRID_SIZE 10

// pomocna premenna reprezentujuca celkovy pocet policok v mriezke obsadenych lodami
extern int shipsTotal;
extern int deployment_grid[GRID_SIZE][GRID_SIZE];
void clear_grid();
// funkcia na vykreslenie aktualneho stavu herneho pola
void drawAttackGrid();

// funkcia, ktora zaznamena strelu hraca do herneho pola a vrati, ci doslo k zasahu (0 - "miss", 1 - "hit")
int checkHit(int row, int col, int playerID);



// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na vycistenie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

// TODO: deklaracie vasich vlastnych funkcii resp. premennych

int random_10();
void old_spawn(int typ_lode);
void deployment_grid_check();
void forbidden_grid_check();
void current_grid_check();
void add_forbidden();
void spawn(int typ_lode);
void deployment_spawn();
#endif /* HELPERS_H */