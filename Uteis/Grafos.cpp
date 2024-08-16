#include <iostream>
#include <locale.h>
//Alterar caminho relativo para a localiza��o do arquivo!!!!
#include <C:\Users\Andrey\Desktop\Facul\programas\Grafos.h>

void ImprimeFilaTopologica(Grafo *G, No_Visitado *VerticeFila){
    Vertice *V;
                
    if (VerticeFila != NULL){
        V = BuscaVerticePorId(G->Inicio, VerticeFila->IdVertice);    
        
        cout << V->Codigo << " ";
        
        ImprimeFilaTopologica(G, VerticeFila->Prox);
    }
}


void GeraOrdTopologica(Grafo *G){
    Fila_Visitados FilaFontes, FilaTopol;
    Vertice *V;
    Aresta *A;
    int IdVertice;    

    //Fila com os v�rtices que s�o fontes
    Inicia_Fila(&FilaFontes);    
    //Fila com a ordena��o topol�gica
    Inicia_Fila(&FilaTopol);    
    
    //Coloca os v�rtices fontes na fila
    for (V=G->Inicio;V!=NULL;V = V->Prox){
        V->IndEntrada = V->GrauEntrada;
        if (V->GrauEntrada == 0){ //Fonte
            Enfileira(&FilaFontes,V->IdVertice);                
        }        
    }    
    
    while(FilaFontes.Total > 0){
        //Retira da fila a pr�xima fonte dispon�vel
        IdVertice = Desenfileira(&FilaFontes);
        
        //Inclui na fila com a ordena��o topol�gica
        Enfileira(&FilaTopol, IdVertice);    
        if (IdVertice >= 0){
            V = BuscaVerticePorId(G->Inicio, IdVertice);
            for (A=V->Inicio;A!=NULL;A = A->Prox){
                V = BuscaVerticePorId(G->Inicio, A->IdVertice);
                V->IndEntrada--; //Remo��o virtual da aresta A
                if (V->IndEntrada == 0){ //V�rtice virou nova fonte virtual
                    Enfileira(&FilaFontes,V->IdVertice);    
                }
            }
        }
    }
    
    if (FilaTopol.Total>=G->NumVertices){ //Gerou ordena��o topol�gica
        cout << endl << endl << "**** ORDENA��O TOPOL�GICA ****" << endl;
        ImprimeFilaTopologica(G, FilaTopol.Inicio);
    }
}

Grafo G;
main () {
    setlocale (LC_ALL,"Portuguese");
    
    Inicia_Grafo(&G);    
    CadastraVertices(&G);
    //CadastraArestas(&G, 0); //N�o direcionado
    CadastraArestas(&G, 1); //Direcionado
    if (G.NumVertices > 0){
        cout << endl << "**** LISTAS DE ADJAC�NCIAS ****";
        ImprimeGrafo(&G, G.Inicio);
        ImprimeMatrizGrafo(&G);
        
        GeraOrdTopologica(&G);
            
        LimparVertices(G.Inicio);                
    }    
        
    return 0;
}
