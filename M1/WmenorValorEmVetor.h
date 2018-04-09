#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

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
