// M1.cpp : Defines the entry point for the console application.
// Evoluções Em:
// https://github.com/willdm/M1
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

#pragma region	ESCOPOS
	//Utilizar como parâmetro nas funções de busca 
	#define ESCOPO_BUSCA_MATRIZ_DIAGONALPRINCIPAL 1		
	#define ESCOPO_BUSCA_MATRIZ_DIAGONALSECUNDARIA 2	 
	#define ESCOPO_BUSCA_MATRIZ_DIAGONAIS 3				 
	#define ESCOPO_BUSCA_MATRIZ_COMPLETA 4		
#pragma endregion

#pragma region Variaveis
	int mvev = 0,mvem = 0,tamanho = TAMANHO_MATRIZ,vetor[TAMANHO_MATRIZ], matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ];
	int dp[TAMANHO_MATRIZ],ds[TAMANHO_MATRIZ];
	bool ordenacaoCrescente = true;
	char maiormenor, crescdecrec, opcao;
	int escopoBusca = 1;
	srand(time(NULL));
#pragma endregion

	cout << "Digite opção (1) para Matriz e vetor Automaticos" << endl;
	cout << "Digite qualquer numero ('X') para matriz e vetor manual" << endl;
	cin >> opcao;

	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			if (opcao == '1') {
				matriz[line][colun] = rand() % 100;
			} 
			else {
				cin >> matriz[line][colun];
			}			
		}cout << endl;
	}

	if (opcao != '1') {
		cout << "Digite o tamnho de seu vetor: " << endl;
		cin >> tamanho;
		cout << endl;
	}

	for (int cont = 0; cont < tamanho; cont++) {
		if (opcao != '1') {
			cin >> vetor[cont];
		}
		else{
			vetor[cont] = rand() % 100;
		}
	}
	
#pragma region Menu Usuario
	cout << "Digite Escopo de busca (1)(2)(3)(4)" << endl;
	cin >> escopoBusca;
	cout << "Digite (+) ou (-) " << endl;
	cin >> maiormenor;

	if (maiormenor == '+') {
		mvev = maiorValorEmVetor(vetor, tamanho);
		cout << "maior valor em vetor é " << mvev << endl;



		mvem = maiorValorEmMatriz(matriz, escopoBusca);
		cout << "maior valor em matriz é " << mvem << endl;
	}
	else if(maiormenor == '-') {
		mvev = menorValorEmVetor(vetor, tamanho);
		cout << "menor valor em vetor é " << mvev << endl;


		mvem = menorValorEmMatriz(matriz, escopoBusca);
		cout << "menor valor em matriz é " << mvem << endl;
	}
	else
	{
		cout << "Esta opção não existe" << endl;
	}

	cout << endl << "Digite (<) ou (>) Para Ordenação de Vetor" << endl;
	cin >> crescdecrec;

	if (crescdecrec == '>') {
		ordenacaoCrescente = true;
		bubbleSort(vetor, tamanho,ordenacaoCrescente);
	}
	else if (crescdecrec == '<') {
		ordenacaoCrescente = false;
		bubbleSort(vetor, tamanho, ordenacaoCrescente);
	}
	else
	{
		cout << "Esta opção não existe" << endl;
	}
#pragma endregion 	

#pragma region Print de matriz vetores e diagonais
	for (int line = 0; line < TAMANHO_MATRIZ; line++) {
		for (int colun = 0; colun < TAMANHO_MATRIZ; colun++) {
			cout << matriz[line][colun] << "|";
			if (line == colun){
				dp[line] = matriz[line][colun];
			}
			if (line ==  TAMANHO_MATRIZ - 1 - colun){
				ds[line] = matriz[line][colun];
			}
		}
		cout << endl;
	}
	cout << endl;

	for (int cont = 0; cont < TAMANHO_MATRIZ; cont++) {
		cout << ds[cont] << "|";
	}
	cout << "	Diag Secund" << endl << endl;

	for (int cont = 0; cont < TAMANHO_MATRIZ; cont++) {
		cout << dp[cont] << "|";
	}
	cout << "	Diag Prim" << endl << endl;
#pragma endregion
			
	return;	
}		
