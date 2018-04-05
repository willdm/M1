// teste.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "time.h"

#define TAMANHO_MATRIZ 5
using namespace std;
void Start();
void bubbleSort(int vetor[], int tamanho, bool ordenacaoCrescente);
int maiorValorEmVetor(int vetor[], int tamanho);
int menorValorEmVetor(int vetor[], int tamanho);
int maiorValorEmMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int escopoBusca);
int menorValorEmMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int escopoBusca);
void PrintVetor(int vetor[], int tamanho);

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
	
	int tamanho = TAMANHO_MATRIZ, escopoBusca = 0, vetor[TAMANHO_MATRIZ], matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ];
	int dp[TAMANHO_MATRIZ],ds[TAMANHO_MATRIZ];
	bool ordenacaoCrescente = false;
	srand(time(NULL));

	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			matriz[line][colun] = rand() % 100;
			cout << matriz[line][colun] << "|";
			if (line == colun) {					//diagonal principal para vetor
				vetor[line] = matriz[line][colun];
				dp[line] = matriz[line][colun];
			}
			if (line == TAMANHO_MATRIZ - 1 - colun)
			{
				ds[line] = matriz[line][colun];
			}
		}cout << endl;
	}cout << endl;
		for (int cont = 0; cont < tamanho; cont++) {
			cout << dp[cont] << "|";
		}cout << endl;
		for (int cont = 0; cont < tamanho; cont++) {
			cout << ds[cont] << "|";
		}cout << endl;
	bubbleSort(vetor, tamanho, ordenacaoCrescente);


/*
	maiorValorEmVetor(vetor, tamanho);
	menorValorEmVetor(vetor, tamanho);
	bubbleSort(vetor, tamanho, ordenacaoCrescente);
	maiorValorEmMatriz(matriz, escopoBusca);
	menorValorEmMatriz(matriz, escopoBusca);
*/
		return;	
}

//Esta função deverá implementar o bubble sort, considerando que quando ordenacaoCrescente for true 
//sua ordenação será crescente, ao contrário implemente ordenação decrescente 
void bubbleSort(int vetor[], int tamanho, bool ordenacaoCrescente) {
	int aux;
	if (ordenacaoCrescente) {
		for (int repeat = 0; repeat < tamanho; repeat++) {
			for (int cont = 0; cont < tamanho - 1; cont++) {
				if (vetor[cont] > vetor[cont + 1]) {
					aux = vetor[cont];
					vetor[cont] = vetor[cont + 1];
					vetor[cont + 1] = aux;
					aux = 0;
				}
			}
		}PrintVetor(vetor, tamanho);
	}
	
	else
	{
		for (int repeat = 0; repeat < tamanho; repeat++) {
			for (int cont = 0; cont < tamanho - 1; cont++) {
				if (vetor[cont] < vetor[cont + 1]) {
					aux = vetor[cont];
					vetor[cont] = vetor[cont + 1];
					vetor[cont + 1] = aux;
					aux = 0;
				}
			}
		}PrintVetor(vetor, tamanho);
	}

	return;
}

//Esta função deve retornar o maior elemento do vetor
int maiorValorEmVetor(int vetor[], int tamanho) {
	int mvev;;
	for (int cont = 0; cont < tamanho; cont++) {
		vetor[cont] = vetor[cont];
		if (cont == 0) {
			mvev = vetor[cont];
		}
		if (vetor[cont] > mvev) {
			mvev = vetor[cont];
		}
	}
	return mvev;
}

//Esta função deve retornar o menor elemento do vetor
int menorValorEmVetor(int vetor[], int tamanho) {
	int mvev;
	for (int cont = 0; cont < tamanho; cont++) {
		vetor[cont] = vetor[cont];
		if (cont == 0) {
			mvev = vetor[cont];
		}
		if (vetor[cont] < mvev) {
			mvev = vetor[cont];
		}
	}
	return mvev;
}

//Esta função deve retornar o maior elemento da matriz, levando em consideração as constantes da biblioteca
int maiorValorEmMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int escopoBusca) {
	int mvem;
	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			matriz[line][colun] = matriz[line][colun];
			if (line == 0 && colun == 0) {
				mvem = matriz[line][colun];
			}
			if (matriz[line][colun] > mvem) {
				mvem = matriz[line][colun];
			}
		}
	}

	return mvem;

}

//Esta função deve retornar o menor elemento da matriz,levando em consideração as constantes da biblioteca 
int menorValorEmMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int escopoBusca) {
	int mvem;
	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			matriz[line][colun] = matriz[line][colun];
			if (line == 0 && colun == 0) {
				mvem = matriz[line][colun];
			}
			if (matriz[line][colun] < mvem) {
				mvem = matriz[line][colun];
			}
		}
	}

	return mvem;
}

//Impressão de Vetores
void PrintVetor(int vetor[],int tamanho) {
	cout << endl;
	for (int cont = 0; cont < tamanho; cont++) {
		cout << vetor[cont] << "|";
	}cout << endl;
}




