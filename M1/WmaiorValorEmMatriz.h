#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
#define TAMANHO_MATRIZ 5

//Esta função deve retornar o maior elemento da matriz, levando em consideração as constantes da biblioteca
int maiorValorEmMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int escopoBusca) {
	int mvem = 0, dp[TAMANHO_MATRIZ], ds[TAMANHO_MATRIZ];

	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			switch (escopoBusca) {
			case 1:										// consid diagonal principal
				matriz[line][colun] = matriz[line][colun];
				if (line == colun) {
					dp[line] = matriz[line][colun];
					if (line == 0 && colun == 0) {
						mvem = dp[line];
					}
					if (dp[line] > mvem) {
						mvem = dp[line];
					}
				}
				break;
			case 2:											// consid diagonal secundaria
				matriz[line][colun] = matriz[line][colun];
				if (line == 0 && colun == TAMANHO_MATRIZ - 1) {
					ds[line] = matriz[line][colun];
					mvem = ds[line];
				}
				if (line == TAMANHO_MATRIZ - 1 - colun) {
					ds[line] = matriz[line][colun];
					
				}
				if (ds[line] > mvem) {
					mvem = ds[line];
				}
				break;
			case 3:											// consid ambas diagonais
				matriz[line][colun] = matriz[line][colun];
				if (line == colun) {
					dp[line] = matriz[line][colun];
					if (line == 0 && colun == 0) {
						mvem = dp[line];
					}
					if (dp[line] > mvem) {
						mvem = dp[line];
					}
				}
				if (line == TAMANHO_MATRIZ - 1 - colun) {
					ds[line] = matriz[line][colun];
					if (ds[line] > mvem) {
						mvem = ds[line];
					}
				}
				break;

			default:											// toda Matriz
				matriz[line][colun] = matriz[line][colun];
				if (line == 0 && colun == 0) {
					mvem = matriz[line][colun];
				}
				if (matriz[line][colun] > mvem) {
					mvem = matriz[line][colun];
				}
				break;
			}

		}
	}

	return mvem;

}
