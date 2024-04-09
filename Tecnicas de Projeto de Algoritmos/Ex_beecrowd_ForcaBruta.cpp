#include <iostream>
#include <math.h>

#define MAX 100

using namespace std;

struct Dados{
	string Nome;
	unsigned int Peso;
	unsigned int Quantidade;		
};

void CalculaMochila(Dados *Lista, int Total, int PesoMax){
	int Cont, ContConjunto;
	float MaiorCusto, CustoAux, SomaPesos, MaiorPeso, QtdePacotes, Qtde;
	
	Qtde = 0; 
	QtdePacotes = 0;
	MaiorPeso = 0;
	MaiorCusto = 0;
	// gera todas as combinações
	for(ContConjunto = 0; ContConjunto < pow(2,Total); ContConjunto++){
		
		CustoAux = 0;
		SomaPesos = 0;
		QtdePacotes = 0;
		
		// verifica se o elemento esta no conjunto corrente
		for (Cont = 0; Cont < Total; Cont++){	
			
			if ((((int)pow(2,Cont)) & ContConjunto) != 0 ){		
				// & - 'E' binario, se for 1 e 1 da 1, 0 e 0 da 0, se for 1 e 0 da 0...	
				CustoAux = CustoAux + Lista[Cont].Quantidade;
				SomaPesos = SomaPesos + Lista[Cont].Peso;
				QtdePacotes++;
			}						
		}		
		
		if (MaiorCusto < CustoAux && ContConjunto!=0 && SomaPesos <= PesoMax){
			MaiorCusto = CustoAux;
			MaiorPeso = SomaPesos;
			Qtde = QtdePacotes;
		}
	}
	
	cout<<MaiorCusto<<" brinquedos"<<endl;
	cout<<"Peso: "<<MaiorPeso<<" kg"<<endl;
	
	if(Qtde - Total < 0){
		cout<<"sobra(m) "<<-(Qtde-Total)<<" pacote(s)"<<endl;
	}
	else{
		cout<<"sobra(m) "<<(Qtde-Total)<<" pacote(s)"<<endl;
	}
}


Dados Lista[MAX];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int N = 0, Cont, Cont2;
	unsigned int Pac;
	
	cin>>N;
	
	for(Cont = 0; Cont < N; Cont++){
		cin>>Pac;
		for(Cont2 = 0; Cont2 < Pac; Cont2++){
			
			cin>>Lista[Cont2].Quantidade>>Lista[Cont2].Peso;	
			
		}
		
		CalculaMochila(Lista, Pac, 50);
	}
	
	return 0;
}
