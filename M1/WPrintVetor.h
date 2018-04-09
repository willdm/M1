#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

//Impressão de Vetores
void PrintVetor(int vetor[], int tamanho) {
	cout << endl;
	for (int cont = 0; cont < tamanho; cont++) {
		cout << vetor[cont] << "|";
	}cout << endl;
}

