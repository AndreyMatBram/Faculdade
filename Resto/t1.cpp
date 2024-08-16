#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/*

*/

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
 
int MergeMin(Dados L[MAX], int Inicio, int Fim){
    int Meio, Cont, ContA, ContB;
    Dados* Aux;
    
    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;    
        
        //Quebra em vetores menores (metade)
        MergeMin(L, Inicio, Meio); //VetorA
        MergeMin(L, Meio+1, Fim); //VetorB
        
        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
        //de forma ordenada
        ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (Dados *) malloc(sizeof(Dados) * (Fim - Inicio + 1));
        while (ContA <= Meio || ContB <= Fim){
            if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L[ContB];
                ContB++;
            }            
            else{
                if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L[ContA];
                    ContA++;
                }
                else{
                    if (L[ContA].Valor < L[ContB].Valor){ //meio do VetorA
                        Aux[Cont] = L[ContA];
                        ContA++;    
                    }
                    else{ //meio do VetorB
                        Aux[Cont] = L[ContB];
                        ContB++;                        
                    }
                }
            }            
            Cont++; //passa para a próxima posição do vetor com o merge            
        }
        //cout << endl << "Valor de Cont: " << Cont;
        //Copia o merge ordenado dos vetores para o vetor original    
        for(Cont=Inicio;Cont<=Fim;Cont++){
            L[Cont].Valor = Aux[Cont - Inicio].Valor;
            L[Cont].Ordem = Aux[Cont - Inicio].Ordem;
        }    
        
        free(Aux);    
	}
	return(L[Inicio].Valor);
}

void SelectionSort(Dados L[MAX]){
	int Cont1, Cont2, Min;
	 
	for(Cont1=0;Cont1<MAX;Cont1++){
	   Min = Cont1;
       
       //Procura o valor mínimo na lista não ordenada
		Min=MergeMin(L,Cont1,MAX);
       
		//Move o valor encontrado pra lista ordenada
		Swap(L, Cont1, Min);
   }                
}  

Dados Lista[MAX];
clock_t T;
main () {
    setlocale (LC_ALL,"Portuguese");
    
    CarregaLista(Lista,0); //QuickSort - Exemplo vídeo
    //CarregaLista(Lista,1); //Demais exemplos
    
    if (MAX <= 100){
        cout << endl << endl << "Lista original" << endl << endl;    
        ImprimeLista(Lista);        
    }
    
    T = clock();
    SelectionSort(Lista);
    //InsertionSort(Lista);
    //BubbleSort(Lista);
    //MergeSort(Lista, 0, MAX-1);
    //QuickSort(Lista, 0, MAX-1); //link abaixo do vídeo
    //QuickSortApr(Lista, 0, MAX-1); //apresentação
    cout << endl << "Quicksort " << 0 << " " << MAX -1;                            
    //QuickSortV(Lista, 0, MAX-1, 1); //vídeo
    
    T = clock() - T;//tempo decorrido!!
    
    if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(Lista);        
    }    
    
    cout << endl << endl << "Tempo de Ordenação: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

}
