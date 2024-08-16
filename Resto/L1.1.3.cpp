#include <iostream>
#include <locale.h>

using namespace std;


void devolve(int *R,int *P,int *A){
	*A=(3.14)*(*R)*(*R);
	*P=(3.14)*(*R)*2;
	
}

int main(){
	setlocale (LC_ALL,"Portuguese");
	
	int Raio,Perimetro,Area;
	
	cout<<"Digite o ";
	cout<<"Raio : ";
	cin>>Raio;
	
	devolve(&Raio,&Perimetro,&Area);
	
	cout<<"Area= "<<Area<<"\nPerimetro= "<<Perimetro;
	return(0);
	
	// professor proxima vez que desejar algo assim favor escrever de maneira mais compreensivel 
	
}
