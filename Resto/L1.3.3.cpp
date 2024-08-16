#include <iostream>

#include <locale.h>

using namespace std;

int soma(int *A, int *B){
	int p;
		p= 1;

	if(*B=*A+*B){
		return (*B);
	}
	
	soma(&p,B);
	
}

int main(){
	
	int N1,N2;
	
	cout<<"Digite Dois numeros para serem somados: "<<endl;
	cin>>N1;
	cin>>N2;
	
	cout<<"A soma vale :\n"<<soma(&N1,&N2);
	
	
}
