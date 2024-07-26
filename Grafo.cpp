#include <iostream>

using namespace std;

#include "grafo.h"

Grafo G;
int main(){
	
	Inicia_Grafo(&G);
	
	CadastraVertices(&G);
	
	CadastraArestas(&G, 0); //N�o direcionado
	
	if (G.NumVertices > 0){
        cout << endl << "**** LISTAS DE ADJAC�NCIAS ****";
        ImprimeGrafo(&G, G.Inicio);
        
        ImprimeMatrizGrafo(&G);
        
        LimparVertices(G.Inicio); 
    }
	
	return 0;
}
