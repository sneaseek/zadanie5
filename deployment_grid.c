#include "helpers.h"

// Popis:
// Subor obsahujuci "deployment_grid" - mriezku s rozmiestnenymi lodami

// Pocty jednotlivych typov lodi v mriezke

//  # 	Typ	            Dlzka
//  ............................
//  1 	Lietadlova lod 	5
//  2 	Bitevna lod 	4
//  3 	Kriznik 	    3
//  2 	Torpedoborec 	2
//  1 	Ponorka	        1


// celkovy pocet policok v mriezke obsadenych lodami
int shipsTotal = 27; // 5*1 + 4*2 + 3*3 + 2*2 + 1*1 = 27

// 2D pole reprezentujuce mriezku s lodami (budeme ju oznacovat "deployment_grid")
// Vysvetlivky:
//		0 - voda
//		1 - lod



// lode sa v mriezke nesmu navzajom dotykat
int deployment_grid[GRID_SIZE][GRID_SIZE] = {
        { 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        { 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
};