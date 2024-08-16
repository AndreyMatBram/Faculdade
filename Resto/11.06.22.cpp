#include <cstdio>
#include <locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");

	//Declarando variaveis com os valores da população e taxa de natalidade de cada pais e uma variavel para salvar o numero de anos passados
    double novaTerra_Hab, novaTerra_Nat, novosMontes_Hab, novosMontes_Nat;
	int years = 0; 
	
	novaTerra_Hab = 5000000;
	novaTerra_Nat = 0.03;
	novosMontes_Hab = 7000000;
	novosMontes_Nat = 0.02;

    while(novaTerra_Hab <= novosMontes_Hab ){// inicio da repetição para passagem dos anos com condição da repetição
        years++; //almenta o numero de anos passados em 1

        novaTerra_Hab=(novaTerra_Hab+(novaTerra_Hab*novaTerra_Nat)); //atualiza o numero de habitantes com base na taxa de natalidade 
        novosMontes_Hab=(novosMontes_Hab+(novosMontes_Hab*novosMontes_Nat));
		
		printf("\nANO %d\n\nNT %f \nNM %f\n=======================\n",years,novaTerra_Hab, novosMontes_Hab);
    }

    printf("\n\nA população de Nova Terra se torna superior à de Novos Montes em %d anos\n\n", years);


	return 0;
}
