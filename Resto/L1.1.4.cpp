#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

void Segundo(int *x1, int*x2){
	
	setlocale (LC_ALL,"Portuguese");
	
	float a, b, c, delta;

    cout << "Coeficiente a: ";
    cin >> a;

    cout << "Coeficiente b: ";
    cin >> b;

    cout << "Coeficiente c: ";
    cin >> c;

    if(a != 0){
        delta = (b*b) - (4*a*c);

        if(delta<0){
            cout <<"Não tem raízes reais\n";
        }
		if (delta==0){
            *x1=(-b)/(2*a);
            
        }else{
            *x1=(-b - sqrt(delta))/(2*a);
            *x2=(-b + sqrt(delta))/(2*a);
            
        }
    }else{
        cout <<"a=0, não é uma equação do segundo grau\n";
    }
}

int main(){
	setlocale (LC_ALL,"Portuguese");
	
	int x1,x2;
	
	x1=0;
	x2=0;
	
	Segundo(&x1,&x2);
	
	cout<<"\nRaiz 1 : "<<x1<<"\nRaiz 2 : "<<x2;
	
	
	return(0);
}
