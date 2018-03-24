#include <stdio.h>
#include "helpers.h"
#include <time.h>
#include <stdlib.h>

int i,j;
int counter_player_1 = 0;
int counter_player_2 = 0;
int new_x = -1;
int new_y = -1;
int new_orientation = -1;

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


void kokot() {
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            deployment_grid[i][j] = current_grid[i][j];
        }
    }
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

void current_grid_check(){
    for(i = 0; i < GRID_SIZE; i++){
        printf("\n");
        for(j = 0; j < GRID_SIZE; j++)
            printf("%d", current_grid[i][j]);
    }
}


int check_current_forbidden(int x, int y, int length, int orientation) {
    switch (orientation) {
        case 0:
            if ((GRID_SIZE - x) >= (GRID_SIZE - length)) {
                for(i = 0; i >= length; i++)
                    if(forbidden_grid[x+i][y] == 2)
                        return 1;
            }
            else {
                for (i = 0; i < length; i++)
                    if(forbidden_grid[x-i][y] == 2)
                        return 1;
            }
            break;
        case 1:
            if ((GRID_SIZE - y) >= (GRID_SIZE - length)) {
                for (i = 0; i < length; i++)
                    if(forbidden_grid[x][y+1] == 2)
                        return 1;
            }
            else {
                     for (i = 0; i < length; i++)
                    if(forbidden_grid[x][y-1] == 2)
                        return 1;
            }
            break;
    }
    return 0;
}

void spawn(int typ_lode) {
    int result = 1;
    while(result == 1) {
        new_x = random_10();
        new_y = random_10();
        new_orientation = horizontal_or_vertical();
        result = check_current_forbidden(new_x, new_y, new_orientation, typ_lode);
    }
    switch(new_orientation) {
        case 0:
            if ((GRID_SIZE - new_x) >= (GRID_SIZE - typ_lode)) {
                for (i = 0; i < typ_lode; i++) {
                    current_grid[new_x + i][new_y] = 1;
                    kokot();
                }
            }
            else {
                for (i = 0; i < typ_lode; i++) {
                    current_grid[new_x - i][new_y] = 1;
                    kokot();
                }
            }
            break;
        case 1:
            if ((GRID_SIZE - new_y) >= (GRID_SIZE - typ_lode)){
                for(i = 0; i < typ_lode; i++) {
                    current_grid[new_x][new_y + i] = 1;
                    kokot();
                }
            }
            else {
                for (i = 0; i < typ_lode; i++) {
                    current_grid[new_x][new_y - i] = 1;
                    kokot();
                }
            }
            break;
    }
    add_forbidden();
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
            if(current_grid[i][j] == 1){
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

