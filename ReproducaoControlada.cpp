#include <iostream>
#include <stdlib.h>

using namespace std;

//Lista de arestas do v�rtice        
struct Aresta{
    int IdVertice;
    float Valor; //grafo ponderado
    struct Aresta* Prox;
};

//Lista de v�rtices
struct Vertice{
    int IdVertice;
    string Codigo;
    struct Aresta* Inicio;
    struct Vertice* Prox;
};

struct Grafo{
    int NumVertices;
    int NumArestas;
    struct Vertice* Inicio;
    int UltimoIdVertice;
};

struct No_Visitado{
    int IdVertice;
    struct No_Visitado* Prox;
};

struct Fila_Visitados{
    struct No_Visitado* Inicio;
    struct No_Visitado* Fim;
    int Total;
};

void Inicia_Grafo(Grafo* G){
    G->NumArestas = 0;
    G->NumVertices = 0;
    G->Inicio = NULL;
    G->UltimoIdVertice = 0;
}

//Inicializa a fila dos v?rtices visitados
void Inicia_Fila(Fila_Visitados *F){
    F->Inicio = NULL;
    F->Fim = NULL;
    F->Total = 0;
}



void InsereNovoVertice(Grafo *G, string Codigo){
    struct Vertice *Ret, *Aux;
    
    Ret = new Vertice; //malloc sem pecisar fazer a conta do size
    Ret->Codigo = Codigo;
    //CUIDADO!! Se esquecer de incializar os ponteiros, pode dar pau de mem�ria
    Ret->Inicio = NULL;    //Inicializa lista de arestas do v�rtice        
    Ret->Prox = NULL;    //Anula para indicar que ser� o novo �ltimo da lista de v�rtices
    Ret->IdVertice = G->UltimoIdVertice + 1;
        
    //Atualiza grafo    
    if (G->Inicio != NULL){
        Aux = G->Inicio;
        while(Aux->Prox!=NULL){
            Aux = Aux->Prox;
        }
        Aux->Prox = Ret;
    }
    else{
        G->Inicio = Ret;
    }
    
    G->UltimoIdVertice++; //Atualiza �ltimo ID usado    
    G->NumVertices++;    //Atualiza total de v�rtices    
}

Vertice* BuscaVertice(Vertice *V, string Codigo){
    Vertice *Ret;
    
    if (V!=NULL){
        if (V->Codigo != Codigo){
            Ret = BuscaVertice(V->Prox, Codigo);        
        }
        else{
            Ret = V;
        }
    }
    else{
        Ret = NULL;
    }
    
    return Ret;
}

Vertice* BuscaVerticePorId(Vertice *V, int IdVertice){
    Vertice *Ret;
    
    if (V!=NULL){
        if (V->IdVertice != IdVertice){
            Ret = BuscaVerticePorId(V->Prox, IdVertice);        
        }
        else{
            Ret = V;
        }
    }
    else{
        Ret = NULL;
    }
    
    return Ret;
}

void InsereNovaAresta(Grafo *G, Vertice *V, int IdVertice){
    struct Aresta *Ret, *Aux;
    
    Ret = new Aresta;
    Ret->IdVertice = IdVertice;        
    Ret->Prox = NULL;    
        
    //Atualiza a lista de arestas do v�rtice V
    if (V->Inicio != NULL){ //Se a lista de arestas j� tem algum v�rtice
        Aux = V->Inicio;
        while(Aux->Prox!=NULL){
            Aux = Aux->Prox;
        }
        Aux->Prox = Ret;
    }
    else{
        V->Inicio = Ret; //inclui registro na cabe�a da lista de arestas
    }
    
    //Atualiza o grafo
    G->NumArestas++;        
}

int VerificaAresta(Grafo *G, int IdVerticeOri, int IdVerticeDest){
    Vertice *V;
    Aresta *A;
    string Elem;
    int Ret = 0;
    
    if (G->NumVertices > 0){
        //Percorre a lista de v�rtices
        for (V=G->Inicio;V!=NULL && Ret==0;V = V->Prox){
        	if(V->IdVertice == IdVerticeOri){
	            //Se existe aresta, marca a posi��o na matriz
	            for (A=V->Inicio;A!=NULL && Ret==0;A = A->Prox){                
	                if(A->IdVertice == IdVerticeDest){
	                    Ret = 1;            
	                }
	            }            
	   		}
        }        
    }    
    
    return Ret;
}

void CadastraArestas(Grafo *G, int Direcionado, string P1, string P2, string Filho){
    Vertice *VerticeP1, *VerticeP2, *VerticeFilho;

    VerticeFilho = BuscaVertice(G->Inicio, Filho);
    if (VerticeFilho != NULL) { //N�o encontrou o v�rtice de origem            
        
        VerticeP1= BuscaVertice(G->Inicio, P1);
        
        if (VerticeP1 != NULL) { //N�o encontrou o v�rtice de destino            

            if (!VerificaAresta(G, VerticeFilho->IdVertice, VerticeP1->IdVertice)) {
                InsereNovaAresta(G, VerticeFilho, VerticeP1->IdVertice);
                
                if (!Direcionado){
                    //Se n�o � direcionado, insere o caminho inverso
                    InsereNovaAresta(G, VerticeP1, VerticeFilho->IdVertice);                         
                }
            }	                    
        }                            
    }   

    if (VerticeFilho != NULL) { //N�o encontrou o v�rtice de origem            
    
        VerticeP2= BuscaVertice(G->Inicio, P2);
        if (VerticeP2 != NULL) { //N�o encontrou o v�rtice de destino            

            if (!VerificaAresta(G, VerticeFilho->IdVertice, VerticeP2->IdVertice)) {
            	
                InsereNovaAresta(G, VerticeFilho, VerticeP2->IdVertice);
                
                if (!Direcionado){
                    //Se n�o � direcionado, insere o caminho inverso
                    InsereNovaAresta(G, VerticeP2, VerticeFilho->IdVertice);                         
                }
            }	                    
        }                            
    }             
}

void CadastraVertices(Grafo *G){
    string P1, P2, Filho;
    int Cont;       


    cin >> P1 >> P2 >> Filho;

    if (BuscaVertice(G->Inicio, P1) == NULL) {            
        InsereNovoVertice(G, P1);        
    }
    
    if (BuscaVertice(G->Inicio, P2) == NULL) {          
        InsereNovoVertice(G, P2);        
    }
    
    if (BuscaVertice(G->Inicio, Filho) == NULL) {           
        InsereNovoVertice(G, Filho);  
		CadastraArestas(G, 1, P1, P2, Filho);      
    }
            
}

string BuscaCodVertice(Vertice *V, int IdVertice){
    string Ret="";
    
    if (V!=NULL){
        if (V->IdVertice != IdVertice){
            Ret = BuscaCodVertice(V->Prox, IdVertice);        
        }
        else{
            Ret = V->Codigo;
        }
    }
    
    return Ret;
}



////////////////////////////////////////////////////////////// DFS //////////////////////////////////////////////////////////////

void ImprimeVisitados(Grafo *G, No_Visitado *N){        
    if (N!=NULL){
        cout << BuscaCodVertice(G->Inicio, N->IdVertice) << ", ";
        ImprimeVisitados(G, N->Prox);        
    }    
}

void Enfileira(Fila_Visitados *F, int IdVertice){
    struct No_Visitado *Ret, *Aux;
    
    Ret = new No_Visitado;
    Ret->IdVertice = IdVertice;        
    Ret->Prox = NULL;    
        
    //Atualiza grafo    
    if (F->Inicio != NULL){ //Fim da Fila
        F->Fim->Prox = Ret;
        F->Fim = Ret;
    }
    else{ //In?cio da fila
        F->Inicio = Ret;
        F->Fim = Ret;
    }
    
    F->Total++;
}

int Visitado(No_Visitado *N, int IdVertice){
    int Ret;
    
    if (N!=NULL){
        if (N->IdVertice != IdVertice){
            Ret = Visitado(N->Prox, IdVertice);        
        }
        else{
            Ret = N->IdVertice;
        }
    }
    else{
        Ret = -1;
    }
    
    return Ret;
}

//DFS - Percorre o grafo por profundidade
int Percorre_DFS(Grafo *G, Fila_Visitados *F, Vertice *V){
    Aresta *A;
    int Ret = -1;
    
    //Marca como visitado
    Enfileira(F,V->IdVertice);
	

    //Percorre as arestas
    for (A=V->Inicio;A!=NULL && Ret == -1;A = A->Prox){
    
        if (Visitado(F->Inicio, A->IdVertice) == -1) { //N?o visitado                

            V = BuscaVerticePorId(G->Inicio, A->IdVertice);
            Ret = Percorre_DFS(G, F, V);
        }
        else{
        	Ret = 1;
		}
    }
    
	
	return Ret;    
}

int GeraDFS(Grafo *G, Fila_Visitados *F, string NomeCavalo){
	Vertice *V;
	int Ret;
	
	V = BuscaVertice(G->Inicio, NomeCavalo);          

    Ret = Percorre_DFS(G, F, V);
    
    
    return Ret;
}

////////////////////////////////////////////////////////// FIM  DFS /////////////////////////////////////////////////////////////

void ImprimeArestas(Grafo *G, string CodVertice, Aresta *Item){
    string Destino;
    
    if (Item != NULL){
        Destino = BuscaCodVertice(G->Inicio, Item->IdVertice);
        //imprime o item na tela
        cout << "(" << CodVertice << "," << Destino << ")";
        ImprimeArestas(G, CodVertice, Item->Prox);
    }
}

void ImprimeGrafo(Grafo *G, Vertice* Item){
    if (Item != NULL){
        //imprime o item na tela
        cout << endl << "V�rtice" <<"["<<Item->IdVertice<<"]:"<< Item->Codigo ;
        cout << endl << "Arestas: {";
        ImprimeArestas(G, Item->Codigo, Item->Inicio);
        cout << "}";
        ImprimeGrafo(G, Item->Prox);
    }
}

void ImprimeMatrizGrafo(Grafo *G){
    Vertice *V, *Aux;
    Aresta *A;
    string Elem;
    
    if (G->NumVertices > 0){
        cout << endl<< "**** MATRIZ DE ADJAC�NCIAS ****" << endl;
        cout << "  ";
        //Lista os v�rtices    por coluna     
        for (V=G->Inicio;V!=NULL;V = V->Prox){
            cout << V->Codigo << " ";
        }
        cout << endl;    

        //Lista os v�rtices    por linha     
        for (V=G->Inicio;V!=NULL;V = V->Prox){
            cout << V->Codigo << "|";
            //Varre os v�rtices para procurar se existe cadastro de aresta
            for (Aux=G->Inicio;Aux!=NULL;Aux = Aux->Prox){
                Elem = "0";
                //Se existe aresta, marca a posi��o na matriz
                for (A=V->Inicio;A!=NULL;A = A->Prox){                
                    if(Aux->IdVertice == A->IdVertice){
                        Elem = "1";            
                    }
                }
                    
                cout << Elem;
                if (Aux->Prox!= NULL){
                    cout << " ";
                }                
            }
            cout << "|" << endl;
        }        
    }    
}

void LimparArestas(Aresta* Item){
    if (Item != NULL){        
        LimparArestas(Item->Prox);
    }
    
    free(Item);
}

void LimparVertices(Vertice* Item){
    if (Item != NULL){
        LimparArestas(Item->Inicio);
        LimparVertices(Item->Prox);
    }
    
    free(Item);
}

Grafo G;
Fila_Visitados F;
int main(){
    setlocale(LC_ALL, "Portuguese");

    unsigned int NumCavalos, NumRelacoesParentesco, NumCasosTeste, Cont;
    string C1, C2;
    int ret;

    cin>>NumCavalos>>NumRelacoesParentesco>>NumCasosTeste;

    Inicia_Grafo(&G);

    for(Cont = 0; Cont < NumRelacoesParentesco; Cont++){
        CadastraVertices(&G);
    }
    
    for(Cont = 0; Cont < NumCasosTeste; Cont++){
    	cin>>C1>>C2;
    	
    	Inicia_Fila(&F);
    	
    	GeraDFS(&G, &F, C1);
    	ret = GeraDFS(&G, &F, C2);
    	
    	if(ret == 1){
    		cout<<"verdadeiro"<<endl;
		}
		else{
			cout<<"falso"<<endl;
		}
	}

    return 0;
}
