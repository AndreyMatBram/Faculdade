#include <iostream>
#include <locale.h>
//Alterar caminho relativo para a localização do arquivo!!!!
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

    //Fila com os vértices que são fontes
    Inicia_Fila(&FilaFontes);    
    //Fila com a ordenação topológica
    Inicia_Fila(&FilaTopol);    
    
    //Coloca os vértices fontes na fila
    for (V=G->Inicio;V!=NULL;V = V->Prox){
        V->IndEntrada = V->GrauEntrada;
        if (V->GrauEntrada == 0){ //Fonte
            Enfileira(&FilaFontes,V->IdVertice);                
        }        
    }    
    
    while(FilaFontes.Total > 0){
        //Retira da fila a próxima fonte disponível
        IdVertice = Desenfileira(&FilaFontes);
        
        //Inclui na fila com a ordenação topológica
        Enfileira(&FilaTopol, IdVertice);    
        if (IdVertice >= 0){
            V = BuscaVerticePorId(G->Inicio, IdVertice);
            for (A=V->Inicio;A!=NULL;A = A->Prox){
                V = BuscaVerticePorId(G->Inicio, A->IdVertice);
                V->IndEntrada--; //Remoção virtual da aresta A
                if (V->IndEntrada == 0){ //Vértice virou nova fonte virtual
                    Enfileira(&FilaFontes,V->IdVertice);    
                }
            }
        }
    }
    
    if (FilaTopol.Total>=G->NumVertices){ //Gerou ordenação topológica
        cout << endl << endl << "**** ORDENAÇÃO TOPOLÓGICA ****" << endl;
        ImprimeFilaTopologica(G, FilaTopol.Inicio);
    }
}

Grafo G;
main () {
    setlocale (LC_ALL,"Portuguese");
    
    Inicia_Grafo(&G);    
    CadastraVertices(&G);
    //CadastraArestas(&G, 0); //Não direcionado
    CadastraArestas(&G, 1); //Direcionado
    if (G.NumVertices > 0){
        cout << endl << "**** LISTAS DE ADJACÊNCIAS ****";
        ImprimeGrafo(&G, G.Inicio);
        ImprimeMatrizGrafo(&G);
        
        GeraOrdTopologica(&G);
            
        LimparVertices(G.Inicio);                
    }    
        
    return 0;
}
