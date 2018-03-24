#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include <time.h>

int main() {
    int row = 0, col = 0;
    int playerID = 1;
    int playerID2 = 1;
    extern int counter_player_1;
    extern int counter_player_2;
    int velkost_lode;

    srand(time(NULL));
    clear_grid();

    printf("Zaciatok hry\n");
    while(shipsTotal > 0) {
        playerID++;
        if(playerID % 2 == 0){
            printf("Na tahu je HRAC 1\n");
            playerID2 = 1;
        }
        else{
            printf("Na tahu je HRAC 2\n");
            playerID2 = 2;
        }
        printf("Hracie pole pred strelou:\n");
        drawAttackGrid(); // funkcia vypise herne pole ("attack_grid")
        spawn(5);
        spawn(4);
        spawn(4);
        spawn(3);
        spawn(3);
        spawn(3);
        spawn(2);
        spawn(2);
        spawn(1);
        deployment_grid_check();
        printf("\n\n");
        forbidden_grid_check();
        printf("\n\n");
        current_grid_check();
        printf("Zadaj riadok a stlpec\n");
        scanf("%d%d", &row, &col);
        // hrac 1 strelil na suradnicu (row,col) a funkcia checkHit() skontroluje, ci doslo k zasahu a aktualizuje herne pole
        if (checkHit(row, col, playerID) == 0) {
            printf("Hrac %i zasiahol lod na suradnici (%i, %i)\n", playerID2, row, col);
            printf("HRAC 1 ma na konte %i bodov.\nHRAC 2 ma na konte %i bodov.\n", counter_player_1, counter_player_2);
            shipsTotal--;
        }
        else
            printf("Hrac %i zasiahol vodu\n\n", playerID2);
        printf("Hracie pole po strele:\n\n");
        drawAttackGrid();
    }
    if(counter_player_1 > counter_player_2){
        printf("Vitazom sa stal HRAC 1 s poctom bodov %i\n", counter_player_1);
        return 0;
    }
    else{
        printf("Vitazom sa stal HRAC 2 s poctom bodov %i\n", counter_player_2);
        return 0;
    }
}
