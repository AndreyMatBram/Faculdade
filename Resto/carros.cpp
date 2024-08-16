#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//Definir o tamanho maximo da lista
#define Tam_lista 50

//Definir estrutura tema
struct car{
	char Nome[80];
	char Descricao[400];
};

//Criar variavel global para a contagem do tamanho da lista
int Tam = 0;


//Funcao Insere
//Entrada: Estrutura car, Ponteiro do tipo car para uma lista
//Saida: Vazia Insere um valor na lista
//1- 

void Add(car add, car *Lista){
	
	//Declarar Variaveis
	int Cont;
	
	//Verificar se a lista está cheia
	if(Tam == (Tam_lista - 1)){
		
		//Exibir mensagem de Lista Cheia
		cout << "\nErro: lista cheia!\n";
		
		return;
	}
	else{
		
		//Percorrer a lista, para encontrar a posicao para inserir o novo elemento
		for(Cont = Tam; Cont > 0; Cont--){
			
			//Verificar se o nome é menor que o contido na lista
			if((strcmp(add.Nome, Lista[Cont-1].Nome)) < 0){
				
				//Deslocar os elementos um passo para trás
				Lista[Cont] = Lista[Cont-1];
			}
			else{
				
				//Verificar se o nome é maior que o contido na lista
				if((strcmp(add.Nome, Lista[Cont-1].Nome)) > 0){
					
					//Interromper a Repeticao
					break;
				}
				else{
					
					//Elemento já cadastrado
					cout << "\nErro: Carro ja esta cadastrado!\n";
					cout << endl;
					system("pause");
					
					return;
				}
			}
		}
		
		//Inserir o elemento
		Lista[Cont] = add;
		
		//Incrementar a quantidade de itens na lista
		Tam++;
		
		//Exibir mensagem de elemento inserido com sucesso
		cout << "\nPlaca inserida com sucesso!\n";
	}
	
	cout << endl;
	system("pause");
}


//Funcao Remove
//Entrada:
//Saida:
//1-

void Remove(car *Lista, char Remove[]){
	
	//Declarar Variaveis
	int Cont1, Cont2, Cont_removido = 0;
	
	//Verificar se a lista está vazia
	if(Tam == 0){
		
		//Exibir mensagem de erro
		cout << "\n lista vazia.\n";
		cout << endl;
		system("pause");
		
		return;
	}
	else{
		
		//Localizar o elemento a ser removido
		for(Cont1 = 0; Cont1 < Tam; Cont1++){
			
			//Verificar se os nomes são iguais
			if((strcmp(Lista[Cont1].Nome, &Remove[Cont1])) == 0){
				
				//Repeticao para deslocar os outros elementos
				for(Cont2 = Cont1; Cont2 < Tam; Cont2++){
					
					//Deslocar os outros elementos
					Lista[Cont2] = Lista[Cont2 + 1];
				}
				
				//Decrementar a quantidade de itens na lista
				Tam--;
				
				//Incrementar Contador de itens removidos
				Cont_removido++;
			}
		}
		
		//Verificar se a quantidade de itens removidos é maior que 0
		if(Cont_removido > 0){
			
			//Exibir mensagem de Item removido com sucesso
			cout << "\nPlaca removida com sucesso!\n";
		}
		else{
			
			//Exibir mensagem de erro
			cout << "\nErro: Placa não encontrada!\n";
		}
	}
	cout << endl;
	system("pause");
}


//Funcao Busca
//Entrada:
//Saida:
//1-

void Busca(const car *Lista, const char Nome[]){
	
	//Declarar variaveis
	int Cont, Resultado = 0;
	
	//Verificar se a lista esta vazia
	if(Tam == 0){
		
		//Exibir mensagem de erro
		cout << "\n lista vazia.\n";
		cout << endl;
		system("pause");
		
		return;
	}
	else{
		
		//Percorrer a lista
		for(Cont = 0; Cont < Tam; Cont++){
			
			//Verificar se o nome é igual ao requesitado
			if(strcmp(Lista[Cont].Nome, &Nome[0]) == 0){
				
				//Exibir o carro requisitado
				
				cout << "\nNome: " << Lista[Cont].Nome;
				cout << "\nDescricao: " << Lista[Cont].Descricao;
				cout << endl;
				
				Resultado++;
			}
		}
		
		if(Resultado == 0){
			
			cout << "\nPlaca não encontrada!";
		}
		
		cout << endl;
		system("pause");
	}
}


int main(void){
	setlocale(LC_ALL,"Portuguese");
	
	//Declarar variaveis
	car Lista_carro[Tam_lista], Ins, *pcar, *pIns;
	int opc;
	char Nome[80];
	
	//Atribuir endereco ao ponteiro
	pcar = &Lista_carro[0];
	pIns = &Ins;
	
	//Repeticao para exibir o menu
	do{
		
		//Limpar tela
		system("cls");
		
		//Exibir menu
		cout << "		Menu";
		cout << "\n1- INCLUIR CARRO";
		cout << "\n2- REMOVER CARRO";
		cout << "\n3- PESQUISAR CARRO";
		cout << "\n4- SAIR\n";
		
		//Receber opcao
		cout << "\nDigite a opcao selecionada: ";
		cin >> opc;
		cin.ignore();
		
		//Verificar se opc e igual a 1
		if(opc == 1){
			
			//Limpar tela
			system("cls");
			
			//Receber as informações sobre o carro
			cout << "\nDigite a Placa do carro: ";
			cin.getline (pIns->Nome, 80);
			cin.ignore();
			
			cout << "Digite a Descricao do carro: ";
			cin.getline (pIns->Descricao, 400);
			cin.ignore();
			Add(Ins, pcar);
		}
		else{
			
			if(opc == 2){
				
				//Limpar tela
				system("cls");
				
				//Receber a placa do carro
				cout << "\nDigite o nome do carro que deseja remover: ";
				cin.getline(Nome, 80);
				cin.ignore();
				Remove(pcar, Nome);
			}
			else{
				
				if(opc == 3){
					
					//Limpar tela
					system("cls");
					
					//Receber a placa do carro
					cout << "\nQual o nome do carro que deseja buscar ? : ";
					cin.getline(Nome, 80);
					cin.ignore();
					
					Busca(pcar, Nome);
				}
			}
		}
		
	}while(opc !=4);
		
	return 0;
}
