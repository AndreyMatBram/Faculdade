#include <iostream>
#include <locale.h>     
using namespace std;

// retorna a menor distancia para os vetores ainda não inclusos em Tset

int minimumDist(int dist[], bool Tset[]) 
{
	int min=INT_MAX,index;
              
	for(int i=0;i<6;i++) 
	{
		if(Tset[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[6][6],int src) //usando uma matrix de 6x6
{
	
	int dist[6]; // inteiro para guardar o caminho minimo de cada nó                          
	bool Tset[6];// função booleana para marcar as nó ja visitadas
	
	// inicialmente colocamos os nós com distancia infinita
	// exeto pelo nó inicial e os nós previamente analisados  
	for(int i = 0; i<6; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;	
	}
	
	dist[src] = 0;   // o nó inicial das distancias é definido como 0             
	
	for(int i = 0; i<6; i++)                           
	{
		int m=minimumDist(dist,Tset); // nó ainda não incluso
		Tset[m]=true;// Variavel m com a distancia minima de Tset
		for(int i = 0; i<6; i++)                  
		{
			// atualizar a minima distancia para o nó analisado
			if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
				dist[i]=dist[m]+graph[m][i];
		}
	}
	cout<<"\tNó\t\tDistancia"<<endl;
	for(int i = 0; i<6; i++)                      
	{ 
		char str=65+i; // valores Ascii para os caracteres A,B,C...
		cout<<"|\t"<<str<<"\t|\t   "<<dist[i]<<"\t\t|"<<endl;
	}
}

int main()
{
	setlocale (LC_ALL,"Portuguese");
	int graph[6][6]={
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0}};
	Dijkstra(graph,0);
	return 0;	                        
}
