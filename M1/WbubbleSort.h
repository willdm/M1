#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
void PrintVetor(int vetor[], int tamanho);

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

