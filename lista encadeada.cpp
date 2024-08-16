//LISTA ENCADEADA DE INTEIROS



#include <iostream>

#include <locale.h>

#include <stdlib.h>



using namespace std;



//struct "exemplo", dois elementos 

//representa��o de cada n� da lista

typedef struct exemplo{

	int v; 				 //inteiro

	struct exemplo *prox; //ponteiro para o pr�ximo elemento	

} t_exemplo;



//Defini��o ponteiros globais que guardam a refer�ncia para a cabe�a da lista

//e para o n� corrente cabe�a da lista encadeada 

t_exemplo *cabeca = NULL;

t_exemplo *corrente = NULL;



//FUN��O CRIAR LISTA

//recebe um valor "valor" inteiro e retorna um ponteiro do tipo t_exemplo

t_exemplo * criar_lista(int valor) {

	

	//alocar espa�o em mem�ria 

	t_exemplo * p = (t_exemplo*) malloc(sizeof(t_exemplo));

	

	//Verificar se houve falha na aloca��o da mem�ria



	if(p==NULL){

		cout<<"\nFalha ao alocar a mem�ria\n";

		return NULL;

	}



	//atribuir valor 

	p->v=valor;



	//atribuir valor ao pr�ximo

	p->prox = NULL;	



	//fazer a cabe�a da lista e o corrente e apontar para p

	cabeca = corrente = p;

	

	return p;

}



//FUN��O INSERIR ELEMENTOS NA LISTA

//recebe um valor "v" inteiro e retorna um ponteiro do tipo t_exemplo

t_exemplo* adicionar_lista(int v){



	//verificar se a cabe�a � NULL(lista vazia),

	//se for NULL, ent�o retornar a fun��o criar_lista

	if(cabeca==NULL){



		return criar_lista(v);

	}



	//se a cabe�a n�o for NULL

	//alocar espa�o em mem�ria

	t_exemplo * p = (t_exemplo*) malloc(sizeof(t_exemplo));

	

	//verificar se houve falha na aloca��o da mem�ria

	if(p==NULL){

		cout<<"\nFalha ao alocar a mem�ria\n";

		return NULL;

	}



	//atribuir valores 

	p->v=v;

	p->prox = NULL; //no final da lista



	//apontar n� corrente para p

	corrente->prox=p;



	//passar o valor de p para o corrente

	corrente = p;

	

	//retorna o ponteiro alocado

	return p;

}





//FUN��O IMPRIMIR

void imprimir_lista(){

	//inicialmente apontar para a cabe�a da lista

	t_exemplo *aux= cabeca;



	//enquanto "aux" for diferente de NULL

	while(aux!=NULL){

		cout<<"\n"<<aux->v;

		//aponta para o pr�ximo elemento da lista

		aux=aux->prox;	

	}	

}



//FUN��O PARA VERIFICAR SE A LISTA EST� VAZIA

//retornar 1 se estiver vazia e 0 zero conter elementos

int lista_vazia(){

	

	//Se a cabe�a for NULL, ent�o a lista est� vazia

	if(cabeca == NULL){

		return 1;

	}

	return 0;			

}



//FUN��O BUSCAR

//Essa fun��o recebe o valor a ser buscado

//e um ponteiro para o ponteiro "ant"

//o "ant" servir� para guardarmos o anterior do elemento encontrado,

//pois iremos utilizar na remo��o, assim fica mais otimizado para n�o ter que 

//percorrer a lista novamente pois precisa-se do elemento anterior ao elemento

//ir� ser removido para ajustar corretamente a lista.

//Retornar o ponteiro para o elemento encontrado ou NULL se n�o encontrar.

t_exemplo * buscar_elemento(int v, t_exemplo **ant){

	

	//se a lista estiver vazia, ent�o n�o possue elementos,

	//Portanto, retorna 0 indicando que n�o achou.

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

		

		//Se achou, ent�o retorna 1

		if(p->v == v){

			achou =1;

			break;

		}

		

		//atualizar a aux_ant

		aux_ant = p;

		

		//aponta para o pr�ximo

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



//FUN��O REMOVER

//retornar 1 se conseguir remover

//e 0 caso contr�rio

int remover_elemento(int v){

	

	//Guardar a referencia do elemento anterior

	//e do elemento que vai ser removido

	t_exemplo  *ant = NULL;

	

	//buscar pelo elemento a se removido

	//passar a refer�ncia para o "ant" (ponteiro para ponteiro)

	//"elem" � o elemento que vai ser removido

	

	t_exemplo *elem = buscar_elemento(v, &ant);

	

	//se for NULL, � porque n�o existe, ent�o retorna 0

	if (elem  == NULL){

		return 0;

	}

	

	//se existe o elemento

	//se o anterior for diferente de NUll, ent�o

	//fazer o pr�ximo do anterior apontar para o pr�ximo do elemento que ser� removido

	if (ant != NULL){

		ant->prox = elem->prox;

		

	}

	

	//se o elemento a ser removido � igual ao corrente, ou seja,

	//� o �timo elemento, ent�o fazer o corrente apontar para o anterior

	if (elem == corrente){

		corrente = ant;

	}

	

	//se elemento a ser removido � igual ao n� cabe�a, ou seja,

	//� o primeiro elemento, ent�o faz a cabe�a apontar para o pr�ximo do elemento

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



//FUN��O PRINCIPAL

int main ( int argc, char*argv[]){

	

	setlocale (LC_ALL, "Portuguese");

	//fun��o que verifica se a lista est� vazia

	if(lista_vazia()==0){

		cout<< "A lista n�o est� vazia\n";

	} else {

		cout<<"Lista vazia! \n";

	}

	

	//verificar o tamanho da lista

	cout << "\nTamanho da lista: "<<tamanho_lista()<<"\n\n";

		

	//criar uma lista passando o valor

	cout<< "\nCriando uma lista... \n\n";

	criar_lista(10);

	

	//adicionar outros elementos � lista

	cout << "\nAdicionando elementos na lista... \n\n";

	adicionar_lista(20);

	adicionar_lista(30);

	adicionar_lista(40);

	adicionar_lista(50);

	

	//Chamar a fun��o para imprimir a lista

	cout<<"Imprimindo os elementos da lista...";

	imprimir_lista();

	

	if(lista_vazia()==0){

		cout<<"\n\nA lista n�o est� vazia \n";

	}else{

		cout<<"\n\nA lista est� vazia";

	}

	

	cout<<"\nTamanho da lista: "<<tamanho_lista()<<"\n\n";

	

	//buscar um elemento na lista

	//retorna diferente de null se achou e null caso contr�rio

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

		cout<< "N�o foi poss�vel remover o elemento 30\n";

	}

	

	//imprimir lista

	cout<<"\nImprimindo lista...";

	imprimir_lista();

	

	cout<<"\n\nTamanho da lista: "<<tamanho_lista()<<"\n\n";	

		

	return 0;	

}
