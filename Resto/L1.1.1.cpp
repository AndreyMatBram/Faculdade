#include <iostream>
#include <locale.h>

using namespace std;

void troca(int *A, int*B){
	
	int p;
	p=*B;
	*B=*A;
	*A=p;
	
	cout<<"Numero 1 : "<<*A<<"\nNumero 2 : "<<*B;	
}

int main (){
	
	int N1,N2;
	
	cout<<"Digite o Numero 1 : "<<endl;
	cin>> N1;
	cout<<"Digite o Numero 2 : "<<endl;
	cin>> N2;
	
	cout<<"Apos troca-los fica:"<<endl;
	troca(&N1,&N2);
	 
	return(0);
}

