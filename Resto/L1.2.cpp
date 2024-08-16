#include <iostream>
#include <locale.h>

using namespace std;

void converteHora(int total_segundos, int *hora, int *min, int *seg){
	
	*hora=(total_segundos)/3600;
	*min=((total_segundos)/60)-((*hora)*60);
	*seg=(total_segundos)-((*min)*60)-((*hora)*3600);
}

int main(){
	
	int total,hora,min,seg;
	
	cout<<"digite o total de segundos : ";
	cin>>total;
	
	converteHora(total,&hora,&min,&seg);
	
	cout<<"Isto no formato HH:MM:SS fica : "<<hora<<":"<<min<<":"<<seg;
	
	return(0);
	
}
