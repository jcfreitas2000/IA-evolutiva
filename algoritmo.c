#include <stdio.h>

#define TAMANHO_POPULACAO 10

float populacao[TAMANHO_POPULACAO];
int numeroGeracoes = 0;
float notaDoMelhor;
int indiceDoMelhor;

void iniciaPopulacao();
float problema(float x);
float novaGeracao();
void print();
float novoIndividuo();

int main (int argc, char** argv)
{
	iniciaPopulacao();
	print();

	int i;
	for(i = 0; i<100; i++) {
		novaGeracao();
	}
}

float novoIndividuo(){
	return rand() % 100;
}

void iniciaPopulacao(){
	int i;
	srand(time(NULL));

	numeroGeracoes++;

	for(i = 0; i < TAMANHO_POPULACAO; i++) {
		populacao[i] = novoIndividuo();
	}
}

float problema(float x){
	if(x <= 10){
		return x;
	}
	if(x >= 35 && x <= 36){
		return 100;
	}

	return 20-x;
}

float novaGeracao(){
	notaDoMelhor = problema(populacao[0]);
	indiceDoMelhor = 0;
	
	int i;
	for(i = 1; i < TAMANHO_POPULACAO; i++) {
		if(notaDoMelhor < problema(populacao[i])){
			notaDoMelhor = problema(populacao[i]);
			indiceDoMelhor = i;
		}
	}

	numeroGeracoes++;

	for(i = 0; i < TAMANHO_POPULACAO; i++) {
		if(indiceDoMelhor == i)
			continue;

		populacao[i] = (populacao[i] + populacao[indiceDoMelhor]) / 2.0;

		if(rand() % 100 < 10){
			populacao[i] = novoIndividuo();
			printf("\n\nmutacao em %d\n\n", i);
		}
	}

	print();
}

void print(){
	int i;

	printf("GERACAO %d: melhor = f(%f) = %f\n", numeroGeracoes, populacao[indiceDoMelhor], notaDoMelhor);
	for(i = 0; i < TAMANHO_POPULACAO; i++) {
		printf("f(%f) = %f, ", populacao[i], problema(populacao[i]));
	}
	printf("\n");
	printf("\n");
}
