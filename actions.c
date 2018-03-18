#include <stdio.h>
#include "helpers.h"
#include <time.h>
#include <stdlib.h>

int i,j;
int counter_player_1 = 0;
int counter_player_2 = 0;

extern int deployment_grid[GRID_SIZE][GRID_SIZE];

int attack_grid[GRID_SIZE][GRID_SIZE] = { {0} };
int forbidden_grid[GRID_SIZE][GRID_SIZE] = { {0} };
int current_grid[GRID_SIZE][GRID_SIZE] = { {0} };

void drawAttackGrid() {

    for (i = 0; i < GRID_SIZE; i++) {
        printf("\n");
        for (j = 0; j < GRID_SIZE; j++) {
            if (attack_grid[i][j] == 0)
                printf("X ");
            else if (attack_grid[i][j] > 0)
                printf("%d ", attack_grid[i][j]);
            else
                printf("~ ");
        }
    };
    printf("\n\n");
}

int checkHit(int row, int col, int playerID) {
    int deployment_value = deployment_grid[row][col];
    int actual_value = attack_grid[row][col];
    if (deployment_value == 1 && actual_value == 0){
        if (playerID % 2 == 0) {
            attack_grid[row][col] = 1;
            counter_player_1++;
            return 0;
        }
        else {
            attack_grid[row][col] = 2;
            counter_player_2++;
            return 0;
        }
    }
    if (deployment_value == 0 && actual_value == 0){
        if (playerID % 2 == 0) {
            attack_grid[row][col] = -1;
            return 1;
        }
        else {
            attack_grid[row][col] = -2;
            return 1;
        }
    }
    return 0;
}

void clear_grid() {
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            deployment_grid[i][j] = 0;
        }
    }
}

int random_10() {
    int result = rand() % 10;
    return result;
}

int horizontal_or_vertical() {
    int result = rand() % 2;
    return result;
}

void spawn(int typ_lode) {
    int x = random_10();
    int y = random_10();
    int horiz_vertic = horizontal_or_vertical();
    switch(horiz_vertic) {
        case 0:
            if ((GRID_SIZE - x) >= (GRID_SIZE - typ_lode)){
                for(i = 0; i < typ_lode; i++)
                    current_grid[x+i][y] = 1;
                break;
            }
            else{
                for(i = 0; i < typ_lode; i++)
                    current_grid[x-i][y] = 1;
                break;
            }
        case 1:
            if ((GRID_SIZE - y) >= (GRID_SIZE - typ_lode)){
                for(i = 0; i < typ_lode; i++)
                    current_grid[x][y+i] = 1;
                break;
            }
            else{
                for(i = 0; i < typ_lode; i++)
                    current_grid[x][y-i] = 1;
                break;
            }
    }
}

void deployment_grid_check() {
    for (i = 0; i < GRID_SIZE; i++) {
        printf("\n");
        for (j = 0; j < GRID_SIZE; j++)
            printf("%d", deployment_grid[i][j]);
    }
}

void add_forbidden() {
    for (i = 0; i < GRID_SIZE; i++){
        for(j = 0; j < GRID_SIZE; j++){
            if(deployment_grid[i][j] == 1){
                forbidden_grid[i+1][j] = 2;
                forbidden_grid[i][j+1] = 2;
                forbidden_grid[i+1][j+1] = 2;
                forbidden_grid[i-1][j] = 2;
                forbidden_grid[i][j-1] = 2;
                forbidden_grid[i-1][j-1] = 2;
                forbidden_grid[i+1][j-1] = 2;
                forbidden_grid[i-1][j+1]= 2;
                forbidden_grid[i][j] = 2;
            }
        }
    }
}

void forbidden_grid_check() {
    for (i = 0; i < GRID_SIZE; i++) {
        printf("\n");
        for(j = 0; j < GRID_SIZE; j++)
            printf("%d", forbidden_grid[i][j]);
    }
}

void generated_deployment_grid(){
    clear_grid();
    spawn(5);
    add_forbidden();
}


void old_spawn(int typ_lode) {
    int x = random_10();
    int y = random_10();
    int horiz_vertic = horizontal_or_vertical();
    switch(horiz_vertic) {
        case 0:
            if ((GRID_SIZE - x) >= (GRID_SIZE - typ_lode)){
                for(i = 0; i < typ_lode; i++)
                    deployment_grid[x+i][y] = 1;
                break;
            }
            else{
                for(i = 0; i < typ_lode; i++)
                    deployment_grid[x-i][y] = 1;
                break;
            }
        case 1:
            if ((GRID_SIZE - y) >= (GRID_SIZE - typ_lode)){
                for(i = 0; i < typ_lode; i++)
                    deployment_grid[x][y+i] = 1;
                break;
            }
            else{
                for(i = 0; i < typ_lode; i++)
                    deployment_grid[x][y-i] = 1;
                break;
            }
    }
}

void current_grid_check(){
    for(i = 0; i < GRID_SIZE; i++){
        printf("\n");
        for(j = 0; j < GRID_SIZE; j++)
            printf("%d", current_grid[i][j]);
    }
}

int check_current_forbidden(){
    add_forbidden();
    for(i = 0; i < GRID_SIZE; i++)
        for(j = 0; j < GRID_SIZE; j++){
            if (current_grid[i][j] == 1) {
                if (forbidden_grid[i][j] == 2)
                    return 1;
            }
            else
                return 0;
        }
}

void deployment_spawn(){
    int lod, stav;
    scanf("%d", &lod);
    spawn(lod);
    stav = check_current_forbidden();
    while(stav == 1){
        for(i = 0; i < GRID_SIZE; i++)
            for(j = 0; j < GRID_SIZE; j++){
                current_grid[i][j] = 0;
            }
        spawn(lod);
        stav = check_current_forbidden();
    }
    for (i = 0; i < GRID_SIZE; i++)
        for(j = 0; j < GRID_SIZE; j++){
            if (current_grid[i][j] == 1)
                deployment_grid[i][j] = 1;
        }
}