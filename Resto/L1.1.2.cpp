#include <iostream>
#include <locale.h>

using namespace std;

void Altera(int *A, int *B){
	
	*A=*A+1;
	*B=*B-1;
	
	cout<<"Apos decrementar o primeiro e incrementar o segundo temos : "<<*A<<"   "<<*B;
	
}

int main (){
	
	int N1,N2;
	
	cout<<"Digite o Numero 1 : \n";
	cin>>N1;
	cout<<"Digite o Numero 2 : \n";
	cin>>N2;
	
	Altera(&N1,&N2);
	
	return(0);
}
