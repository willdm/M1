// teste.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"
#include "WbubbleSort.h"
#include "WmaiorValorEmVetor.h"
#include "WmenorValorEmVetor.h"
#include "WPrintVetor.h"
#include "WmaiorValorEmMatriz.h"
#include "WmenorValorEmMatriz.h"

#pragma region Inicio funções
#define TAMANHO_MATRIZ 5
using namespace std;
void Start();
#pragma endregion	

int main() {
	Start();
	return 0;
}

void Start() {
	
	//Utilizar como parâmetro nas funções de busca 
	#define ESCOPO_BUSCA_MATRIZ_DIAGONALPRINCIPAL 1		//ok
	#define ESCOPO_BUSCA_MATRIZ_DIAGONALSECUNDARIA 2	 //ok
	#define ESCOPO_BUSCA_MATRIZ_DIAGONAIS 3				 //ok
	#define ESCOPO_BUSCA_MATRIZ_COMPLETA 4				  //ok
	
	int mvev = 0,mvem = 0,tamanho = TAMANHO_MATRIZ,vetor[TAMANHO_MATRIZ], matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ];
	int dp[TAMANHO_MATRIZ],ds[TAMANHO_MATRIZ];
	bool ordenacaoCrescente = true;
	char opcao;
	int escopoBusca = 4;
	srand(time(NULL));

	cout << "Digite opção (1) para Matriz e vetor Manual," << endl;
	cout << "Digite qualquer numero (X) para matriz sorteada" << endl;
	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			cin >> opcao;
			if (opcao == '1') {
				matriz[line][colun] = rand() % 100;
			} 
			else {
				cin >> matriz[line][colun];
			}			
			//cout << matriz[line][colun] << "|";
			if (line == colun) {					//diagonal principal para vetor
				vetor[line] = matriz[line][colun];
				dp[line] = matriz[line][colun];
			}
			if (line == TAMANHO_MATRIZ - 1 - colun)	{
				ds[line] = matriz[line][colun];		//diagonal secundaria para vetor
			}
		}
		cout << endl;
	}
	cout << endl;

	for (int cont = 0; cont < tamanho; cont++) {
		cin >> vetor[cont];
		cout << dp[cont] << "	";
	}
		cout << endl;
		for (int cont = 0; cont < tamanho; cont++) {
			cout << ds[cont] << "	";
		}
		cout << endl;

	/*

	
	/*mvev = menorValorEmVetor(vetor, tamanho);
	mvev = menorValorEmVetor(vetor, tamanho);
	mvem = maiorValorEmMatriz(matriz, escopoBusca);
	mvem = menorValorEmMatriz(matriz, escopoBusca);*/

	cout << endl << mvev << endl;
	//cout << endl << mvem << endl;
		return;	
}		







