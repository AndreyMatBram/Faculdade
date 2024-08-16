//LISTA ENCADEADA DE INTEIROS



#include <iostream>

#include <locale.h>

#include <stdlib.h>



using namespace std;



//struct "exemplo", dois elementos 

//representação de cada nó da lista

typedef struct exemplo{

	int v; 				 //inteiro

	struct exemplo *prox; //ponteiro para o próximo elemento	

} t_exemplo;



//Definição ponteiros globais que guardam a referência para a cabeça da lista

//e para o nó corrente cabeça da lista encadeada 

t_exemplo *cabeca = NULL;

t_exemplo *corrente = NULL;



//FUNÇÃO CRIAR LISTA

//recebe um valor "valor" inteiro e retorna um ponteiro do tipo t_exemplo

t_exemplo * criar_lista(int valor) {

	

	//alocar espaço em memória 

	t_exemplo * p = (t_exemplo*) malloc(sizeof(t_exemplo));

	

	//Verificar se houve falha na alocação da memória



	if(p==NULL){

		cout<<"\nFalha ao alocar a memória\n";

		return NULL;

	}



	//atribuir valor 

	p->v=valor;



	//atribuir valor ao próximo

	p->prox = NULL;	



	//fazer a cabeça da lista e o corrente e apontar para p

	cabeca = corrente = p;

	

	return p;

}



//FUNÇÃO INSERIR ELEMENTOS NA LISTA

//recebe um valor "v" inteiro e retorna um ponteiro do tipo t_exemplo

t_exemplo* adicionar_lista(int v){



	//verificar se a cabeça é NULL(lista vazia),

	//se for NULL, então retornar a função criar_lista

	if(cabeca==NULL){



		return criar_lista(v);

	}



	//se a cabeça não for NULL

	//alocar espaço em memória

	t_exemplo * p = (t_exemplo*) malloc(sizeof(t_exemplo));

	

	//verificar se houve falha na alocação da memória

	if(p==NULL){

		cout<<"\nFalha ao alocar a memória\n";

		return NULL;

	}



	//atribuir valores 

	p->v=v;

	p->prox = NULL; //no final da lista



	//apontar nó corrente para p

	corrente->prox=p;



	//passar o valor de p para o corrente

	corrente = p;

	

	//retorna o ponteiro alocado

	return p;

}





//FUNÇÃO IMPRIMIR

void imprimir_lista(){

	//inicialmente apontar para a cabeça da lista

	t_exemplo *aux= cabeca;



	//enquanto "aux" for diferente de NULL

	while(aux!=NULL){

		cout<<"\n"<<aux->v;

		//aponta para o próximo elemento da lista

		aux=aux->prox;	

	}	

}



//FUNÇÃO PARA VERIFICAR SE A LISTA ESTÁ VAZIA

//retornar 1 se estiver vazia e 0 zero conter elementos

int lista_vazia(){

	

	//Se a cabeça for NULL, então a lista está vazia

	if(cabeca == NULL){

		return 1;

	}

	return 0;			

}



//FUNÇÃO BUSCAR

//Essa função recebe o valor a ser buscado

//e um ponteiro para o ponteiro "ant"

//o "ant" servirá para guardarmos o anterior do elemento encontrado,

//pois iremos utilizar na remoção, assim fica mais otimizado para não ter que 

//percorrer a lista novamente pois precisa-se do elemento anterior ao elemento

//irá ser removido para ajustar corretamente a lista.

//Retornar o ponteiro para o elemento encontrado ou NULL se não encontrar.

t_exemplo * buscar_elemento(int v, t_exemplo **ant){

	

	//se a lista estiver vazia, então não possue elementos,

	//Portanto, retorna 0 indicando que não achou.

	if(lista_vazia()==1){

		return NULL;

	}

	

	//p para percorrer a lista

	t_exemplo  *p = cabeca;

	

	//para guardar o anterior

	t_exemplo  *aux_ant = NULL;

	

	//indica se achou o elemento

	int achou =0;

	

	//percorrer a lista

	while (p != NULL){

		

		//Se achou, então retorna 1

		if(p->v == v){

			achou =1;

			break;

		}

		

		//atualizar a aux_ant

		aux_ant = p;

		

		//aponta para o próximo

		p = p->prox;

	}

	

	//Verificar se achou

	if (achou == 1){

		

		if(ant){

			*ant =aux_ant;	

			//guardar aux_ant

			 return p;

		}	

	}

	

	return NULL;		

}



//FUNÇÃO REMOVER

//retornar 1 se conseguir remover

//e 0 caso contrário

int remover_elemento(int v){

	

	//Guardar a referencia do elemento anterior

	//e do elemento que vai ser removido

	t_exemplo  *ant = NULL;

	

	//buscar pelo elemento a se removido

	//passar a referência para o "ant" (ponteiro para ponteiro)

	//"elem" é o elemento que vai ser removido

	

	t_exemplo *elem = buscar_elemento(v, &ant);

	

	//se for NULL, é porque não existe, então retorna 0

	if (elem  == NULL){

		return 0;

	}

	

	//se existe o elemento

	//se o anterior for diferente de NUll, então

	//fazer o próximo do anterior apontar para o próximo do elemento que será removido

	if (ant != NULL){

		ant->prox = elem->prox;

		

	}

	

	//se o elemento a ser removido é igual ao corrente, ou seja,

	//é o útimo elemento, então fazer o corrente apontar para o anterior

	if (elem == corrente){

		corrente = ant;

	}

	

	//se elemento a ser removido é igual ao nó cabeça, ou seja,

	//é o primeiro elemento, então faz a cabeça apontar para o próximo do elemento

	//a ser removido

	if (elem == cabeca){

		cabeca  = elem->prox;	

	}

	

	free (elem);

	elem = NULL;

	

	return 1;	

}



//TAMANHO DA LISTA

int tamanho_lista( ){

	

	if (lista_vazia()){

		return 0;

	}

	

	t_exemplo *aux = cabeca;

	int tam =0;

	

	while (aux != NULL){

		tam ++;

		aux = aux->prox;

	}

	

	return tam;	

}



//FUNÇÃO PRINCIPAL

int main ( int argc, char*argv[]){

	

	setlocale (LC_ALL, "Portuguese");

	//função que verifica se a lista está vazia

	if(lista_vazia()==0){

		cout<< "A lista não está vazia\n";

	} else {

		cout<<"Lista vazia! \n";

	}

	

	//verificar o tamanho da lista

	cout << "\nTamanho da lista: "<<tamanho_lista()<<"\n\n";

		

	//criar uma lista passando o valor

	cout<< "\nCriando uma lista... \n\n";

	criar_lista(10);

	

	//adicionar outros elementos à lista

	cout << "\nAdicionando elementos na lista... \n\n";

	adicionar_lista(20);

	adicionar_lista(30);

	adicionar_lista(40);

	adicionar_lista(50);

	

	//Chamar a função para imprimir a lista

	cout<<"Imprimindo os elementos da lista...";

	imprimir_lista();

	

	if(lista_vazia()==0){

		cout<<"\n\nA lista não está vazia \n";

	}else{

		cout<<"\n\nA lista está vazia";

	}

	

	cout<<"\nTamanho da lista: "<<tamanho_lista()<<"\n\n";

	

	//buscar um elemento na lista

	//retorna diferente de null se achou e null caso contrário

	if (buscar_elemento(10, NULL) != NULL){

		cout<<"Elemento 10 encontrado";	

	} else{

		cout<<"Elemento 10 encontrado\n";

	}

	

	if (buscar_elemento(100, NULL) != NULL){

		cout<<"Elemento 100 encontrado";	

	} else{

		cout<<"Elemento 100 encontrado\n";

	}

	

	//Remover o elemento 30 da lista

	

	if (remover_elemento(30)){

		cout<<"\nElemento 30 removido com sucesso!\n";

	} else{

		cout<< "Não foi possível remover o elemento 30\n";

	}

	

	//imprimir lista

	cout<<"\nImprimindo lista...";

	imprimir_lista();

	

	cout<<"\n\nTamanho da lista: "<<tamanho_lista()<<"\n\n";	

		

	return 0;	

}
