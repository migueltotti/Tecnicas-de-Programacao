#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
TÉCNICAS DE PROJETO
*/

using namespace std;

//Caixeiro viajante e Mochila (Força Bruta)
#define MAX 4
//Mínimo #define MAX 100

struct Cidades{
	string Nome;	
	bool Utilizado=0;
};

struct Rotas{
	int Origem;
	int Destino;
	int Custo;
};

//Carrega o vetor com valores aleatórios
void CarregaLista(Cidades L[MAX]){
	int Cont;
	
	L[0].Nome = "A";
	L[1].Nome = "B";
	L[2].Nome = "C";
	L[3].Nome = "D";
}

void ImprimeLista(Cidades L[MAX]){
	int Cont;
	
	for(Cont=0;Cont<MAX;Cont++){
		cout << L[Cont].Nome << ", ";
	}		
}

// Busca a proxima cidade disponivel
int BuscaRotaDisponivel(Cidades *L, Rotas *R, int Origem){
	int Cont, Pos;
	bool Encontrado;
	
	for(Cont=0;Cont<MAX*MAX-4 && !Encontrado;Cont++){
		if (R[Cont].Origem == Origem && !L[R[Cont].Destino].Utilizado){

			//cout<< endl << "Encontrei na posicao: " << Cont;
			
			Encontrado = 1;
			Pos = Cont;
		}
	}
	
	return Pos;
}

// Busca o valor da ultima cidade visitada voltando para a origem
int BuscaCustoRotas(Rotas *R, int Origem, int Destino){
	int Cont, Pos;
	bool Encontrado;
	
	for(Cont=0;Cont<MAX*MAX-4 && !Encontrado;Cont++){
		if (R[Cont].Origem == Origem && R[Cont].Destino == Destino){			
			Encontrado = 1;
			Pos = Cont;
		}
	}
	
	return Pos;
}

string GeraRotasBackTrack(Cidades Lista[MAX], Rotas R[MAX*MAX-4], int M[MAX][MAX] , int NoInicio, int NoCorrente, int Valor, int ProxNivel) {
	int Pos;
	string DescCaminho = "";
		

	//Avalia se já passou pelos níveis (qtde de cidades possíveis no caminho) válidos (0-3), 
	//de acordo com a matriz de caminhos
	if (ProxNivel == MAX){ 
		//Não há mais nós a visitar. Acrescenta valor da volta ao início.
		Pos = BuscaCustoRotas(R, NoCorrente, NoInicio);	
		cout << endl << DescCaminho <<"-"<< Lista[NoInicio].Nome << " => " << (Valor) + R[Pos].Custo;//M[NoCorrente][NoInicio];
	}
	else{		
		Pos = BuscaRotaDisponivel(Lista, R, NoCorrente);				
		Lista[NoCorrente].Utilizado = 1;
	    cout << endl << "Pos: "<< Pos <<" Próximo destino: " << R[Pos].Destino;
		GeraRotasBackTrack(Lista, R, M, NoInicio, R[Pos].Destino, Valor+ R[Pos].Custo, ProxNivel + 1);
	}	
}

void GeraRotasBackTrack(Cidades Lista[MAX], Rotas R[MAX*MAX-4], int M[MAX][MAX] , int NoInicio, int NoCorrente, int Valor, int ProxNivel) {
	int Pos;
	std::size_t EncontrouNo;		

	//Avalia se já passou pelos níveis (qtde de cidades possíveis no caminho) válidos (0-3), 
	//de acordo com a matriz de caminhos
	if (ProxNivel == MAX){ 
		//Não há mais nós a visitar. Acrescenta valor da volta ao início.
		Pos = BuscaCustoRotas(R, NoCorrente, NoInicio);	
		DescCaminho += "-" + Lista[NoInicio].Nome + " => " + to_string((Valor) + R[Pos].Custo);//M[NoCorrente][NoInicio];
	}
	else{		
		if(ProxNivel == 0){
			DescCaminho = Lista[R[NoInicio].Origem].Nome
		}
		Pos = BuscaRotaDisponivel(Lista, R, NoCorrente);				
		Lista[NoCorrente].Utilizado = 1;
	    //cout << endl << "Pos: "<< Pos <<" Próximo destino: " << R[Pos].Destino;
	    //DescCaminho + "-" +Lista[R[Pos].Destino].Nome
		DescCaminho += "-" + Lista[R[Pos].Destino].Nome + GeraRotasBackTrack(Lista, R, M, NoInicio, R[Pos].Destino, Valor+ R[Pos].Custo, ProxNivel + 1);
	}	
	
	return DescCaminho;
}



void CarregaRotas(int M[MAX][MAX], Rotas R[MAX]){
	int Linha, Coluna, Cont=0;
	
	for(Linha=0;Linha<MAX;Linha++){
		for(Coluna=0;Coluna<MAX;Coluna++){
			if (Linha != Coluna){
				R[Cont].Origem = Linha;
				R[Cont].Destino = Coluna;
				R[Cont].Custo = M[Linha][Coluna];
				Cont++;				
			}
		}
	}
	
}

void ImprimeRotas(Rotas R[MAX]){
	int Cont=0;
	
	for(Cont=0;Cont<MAX*MAX-4;Cont++){
		cout << "[O]: "<<R[Cont].Origem << " [C]: " <<R[Cont].Custo << " [D]: "<< R[Cont].Destino;			 
		cout << endl;
	}
}


void Swap(Rotas *L, int PosA, int PosB){
    Rotas Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void OrdenaRotas(Rotas *L){
    int Cont1, Cont2, Aux;
    
    for(Cont1=0;Cont1<MAX*MAX-4;Cont1++){
        Aux = Cont1;
        
        //Origem crescente e custo decrescente
        for (Cont2=Cont1+1;Cont2<MAX*MAX-4;Cont2++) {        
            if (L[Aux].Origem > L[Cont2].Origem || (L[Aux].Origem == L[Cont2].Origem && L[Aux].Custo > L[Cont2].Custo)){  				
                Aux = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Aux);        
    }                
}


Cidades Lista[MAX];
//0=A, 1=B, 2=C e 3=D (Caixeiro Viajante)
int Matriz[MAX][MAX] = {0,2,8,5,
						2,0,3,4,	
						8,3,0,7,
						5,4,7,0};
Rotas R[MAX];						
main () {
	setlocale (LC_ALL,"Portuguese");

	CarregaLista(Lista); //Caixeiro viajante
	//ImprimeLista(Lista);
	CarregaRotas(Matriz, R);
	//ImprimeRotas(R);
	OrdenaRotas(R);
	cout << endl;
	ImprimeRotas(R);
	
	//GeraCaminhosBackTrack(Lista, Matriz, 0, 0, "A", 0, 1);
	Lista[1].Utilizado = 1;
	GeraRotasBackTrack(Lista, R, Matriz, 1, 1, "B", 0, 1);
	
}


