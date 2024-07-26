using 

using namespace std;

//Lista de arestas do vértice        
struct Aresta{
    int IdVertice;
    float Valor; //grafo ponderado
    struct Aresta* Prox;
};

struct Vertice{
    int IdVertice;
    string Codigo;
    struct Aresta* Inicio;
    struct Vertice* Prox;
};

// Cabecalho geral do grafo
struct Grafo{
    int NumVertices;
    int NumArestas;
    struct Vertice* Inicio;
    int UltimoIdVertice;
};

void Inicia_Grafo(Grafo* G){
    G->NumArestas = 0;
    G->NumVertices = 0;
    G->Inicio = NULL;
    G->UltimoIdVertice = 0;
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

void InsereNovoVertice(Grafo *G, string Codigo){
    struct Vertice *Ret, *Aux;
    
    Ret = new Vertice; //malloc sem pecisar fazer a conta do size
    Ret->Codigo = Codigo;
    //CUIDADO!! Se esquecer de incializar os ponteiros, pode dar pau de memória
    Ret->Inicio = NULL;    //Inicializa lista de arestas do vértice        
    Ret->Prox = NULL;    //Anula para indicar que será o novo último da lista de vértices
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
    
    G->UltimoIdVertice++; //Atualiza último ID usado    
    G->NumVertices++;    //Atualiza total de vértices    
}

void CadastraVertices(Grafo *G){
    string Codigo;
    int IdVertice;
    
    system("cls");
    cout << "**** CADASTRO DE VÉRTICES ****";
    do{        
        cout << endl << "Entre com o novo vértice (0 para sair!!): ";
        cin >> Codigo;
        if (Codigo != "0"){
            if (BuscaVertice(G->Inicio, Codigo) == NULL) { //Não encontrou o vértice            
                InsereNovoVertice(G, Codigo);        
            }
            else{
                cout << endl << "Vértice " << Codigo << " já está cadastrado!!";
            }            
        }
        
    } while (Codigo != "0");    
}

void InsereNovaAresta(Grafo *G, Vertice *V, int IdVertice, float Valor){
    struct Aresta *Ret, *Aux;
    
    Ret = new Aresta;
    Ret->IdVertice = IdVertice;  
	Ret->Valor = Valor;     
    Ret->Prox = NULL;    
        
    //Atualiza a lista de arestas do vértice V
    if (V->Inicio != NULL){ //Se a lista de arestas já tem algum vértice
        Aux = V->Inicio;
        while(Aux->Prox!=NULL){
            Aux = Aux->Prox;
        }
        Aux->Prox = Ret;
    }
    else{
        V->Inicio = Ret; //inclui registro na cabeça da lista de arestas
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
        //Percorre a lista de vertices   
        for (V=G->Inicio;V!=NULL && Ret == 0;V = V->Prox){
            if(V->IdVertice == IdVerticeOri){
				
	            //Se existe aresta, marca a posição na matriz
	            for (A=V->Inicio;A!=NULL && Ret == 0;A = A->Prox){                
	                if(A->IdVertice == IdVerticeDest){
	                    Ret = 1;            
	                }
	            }
	        }
        }        
    }    
    
    return Ret;
}

void CadastraArestas(Grafo *G, int Direcionado){
    string Origem, Destino;
    Vertice *VerticeOri, *VerticeDest;
    float Valor;
    
    system("cls");
    cout << "**** CADASTRO DE ARESTAS ****";
    do{        
        cout << endl << "Entre com o vértice de origem (0 para sair!!): ";
        cin >> Origem;
        if (Origem != "0"){
            VerticeOri = BuscaVertice(G->Inicio, Origem);
            if (VerticeOri == NULL) { //Não encontrou o vértice de origem            
                cout << endl << "Vértice de origem " << Origem << " não está cadastrado!!";                        
            }
            else{
                cout << endl << "Entre com o vértice de destino: ";
                cin >> Destino;
                VerticeDest = BuscaVertice(G->Inicio, Destino);
                if (VerticeDest == NULL) { //Não encontrou o vértice de destino            
                    cout << endl << "Vértice de destino " << Destino << " não está cadastrado!!";                        
                }
                else{
                    if(!VerificaAresta(G, VerticeOri->IdVertice, VerticeDest->IdVertice)){
                    	cout<< endl << "Entre com o valor da aresta (" << Origem << ", " << Destino << ")";
                    	cin>> Valor;
                    	
	                    InsereNovaAresta(G, VerticeOri, VerticeDest->IdVertice, Valor);
	                    if (!Direcionado){
	                        //Se não é direcionado, insere o caminho inverso
	                        InsereNovaAresta(G, VerticeDest, VerticeOri->IdVertice, Valor);                         
	                    }
	                }
	                else{
	                	cout << endl << "Aresta (" << Origem << ", " << Destino << ") já está cadastrado!!";
					}
                }                            
            }            
        }
        
    } while (Origem != "0");    
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
        cout << endl << "Vértice" <<"["<<Item->IdVertice<<"]:"<< Item->Codigo ;
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
        cout << endl<< "**** MATRIZ DE ADJACÊNCIAS ****" << endl;
        cout << "  ";
        //Lista os vértices    por coluna     
        for (V=G->Inicio;V!=NULL;V = V->Prox){
            cout << V->Codigo << " ";
        }
        cout << endl;    

        //Lista os vértices    por linha     
        for (V=G->Inicio;V!=NULL;V = V->Prox){
            cout << V->Codigo << "|";
            //Varre os vértices para procurar se existe cadastro de aresta
            for (Aux=G->Inicio;Aux!=NULL;Aux = Aux->Prox){
                Elem = "0";
                //Se existe aresta, marca a posição na matriz
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
