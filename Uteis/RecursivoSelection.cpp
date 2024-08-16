#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

#define MAX 10

struct Dados{
    int Valor;
    int Ordem;
};

//Carrega o vetor com valores aleatórios
void CarregaLista(Dados L[MAX], int GeraDados){
    int Cont;
    
    if (GeraDados){
        for(Cont=0;Cont<MAX;Cont++){
            L[Cont].Valor = rand()%100;
            L[Cont].Ordem = Cont;
        }        
    }
    else{
        L[0].Valor = 3; L[1].Valor = 0; L[2].Valor = 1; L[3].Valor = 8; L[4].Valor = 7;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        L[5].Valor = 2; L[6].Valor = 5; L[7].Valor = 4; L[8].Valor = 9; L[9].Valor = 6;
        L[5].Ordem = 5; L[6].Ordem = 6; L[7].Ordem = 7; L[8].Ordem = 8; L[9].Ordem = 9;
    }    
}

void ImprimeLista(Dados L[MAX]){
    int Cont;
    
    for(Cont=0;Cont<MAX;Cont++){
        cout <<    "[" << L[Cont].Ordem << "] " << L[Cont].Valor << ", ";
    }        
}

void Swap(Dados L[MAX], int PosA, int PosB){
    Dados Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

int Minimo(Dados L[MAX], int i, int j)
{	
	int Min;
	
    if (i == j)
        return i;
  
   	//analizar todo o vetor
	Min = Minimo(L, i + 1, j);
  
  	//ver qual o menor e retornalo
    if(L[i].Valor<L[Min].Valor){
    	return i;
	}else{
		return Min;
	}
}
  

void SelectionSort(Dados L[MAX], int Aux = 0)
{
    // Parar quando o Auxiliar for igual a o MAX
    if (Aux == MAX)
       return;
  
    // Chamar função minimo para comparar os valores
    int Min;
	Min = Minimo(L, Aux, MAX-1);
  
    // trocar o Min pelo Aux caso eles não sejam  iguais
    if (Min != Aux)
       Swap(L, Min, Aux);
  
    // Recursividade
    SelectionSort(L, Aux + 1);
}


Dados Lista[MAX];
clock_t T;
main () {
    setlocale (LC_ALL,"Portuguese");
    
    CarregaLista(Lista,1);
    
    if (MAX <= 100){
        cout << endl << endl << "Lista original" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    T = clock();
    SelectionSort(Lista,0);
    //InsertionSort(Lista);
    //BubbleSort(Lista);
    //MergeSort(Lista, 0, MAX-1);
    //QuickSort(Lista, 0, MAX-1);
    T = clock() - T;//tempo decorrido!!
    
    if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(Lista);        
    }    
    
    cout << endl << endl << "Tempo de Ordenação: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

}
