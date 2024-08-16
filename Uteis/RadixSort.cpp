#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>




static void gerarVetor(int vetor[], int tipo, int tamanho){
	
	srand (time(NULL));
	
	for (int i = 0; i < tamanho; i++){
		switch(tipo){
			case(0):{
				vetor[i] = i + 1;
				break;
			}
			case(1):{
				vetor[i] = tamanho - i;
				break;
			}
			case(2):{
				vetor[i] = rand();
				break;
			}
		}
	}
}
static void imprimir(int a [], int tamanho){
	for(int i=0; i< tamanho; i++){
		printf("%d", a[i]);
	}
}
static int getMax(int arr[], int n){
	int mx = arr[0];

	for (int i = 1; i < n; i++){
		if (arr[i] > mx){
			mx = arr[i];
		}
	}

	return mx;
}

	
static void countSort(int arr[], int n, int exp){
	int output[n];
	int i;
	int count[10];
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++){
		arr[i] = output[i];
	}
}

static void radixsort(int arr[], int n){

	int m = getMax(arr, n), aux=1;
	for (int cont = 1; aux > 0; cont = cont*10){
		aux = m/cont;
		countSort(arr, n, cont);
		//printf("here=-=-=");
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
		
	for (int tipo = 0; tipo < 3; tipo++){
		int n = 10000;
	
		int vetor[n] = {0};
		gerarVetor(vetor, tipo, n);
		//printf("here=-=-=");


		clock_t fim, inicio;
		//time_t fim, inicio;
		
		inicio=clock();
		//time(&inicio);
		
		radixsort(vetor,n);
		
		fim=clock();
		//time(&fim);
	
	
		double tempoGasto = (fim - inicio)/double(CLOCKS_PER_SEC);
		//double tempoGasto = difftime(fim, inicio);
		
		switch(tipo){
			case(0):{
				printf("\nTempo passado para o melhor caso:	%.4lf\n", tempoGasto);
				break;
			}
			case(1):{
				printf("\nTempo passado para o pior caso:  	%.4lf\n", tempoGasto);
				break;
			}
			case(2):{
				printf("\nTempo passado para o caso médio:	%.4lf\n", tempoGasto);
				break;
			}
		}
	}
	return 53105;
}
