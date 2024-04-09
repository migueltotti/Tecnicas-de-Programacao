#include <iostream>
#include <math.h>

using namespace std;

#define MAX 4

struct Dados{
	string Nome;
	float Peso;
	float Custo;		
};

void CarregaCidades(Dados *L){
	
	L[0].Nome = "A";//"A";	
	L[1].Nome = "B";//"B";		
	L[2].Nome = "C";//"C";		
	L[3].Nome = "D";//"D";			
}

void CarregaMochila(Dados *L){

	L[0].Nome = "1";//"A";
	L[0].Peso = 7;
	L[0].Custo = 42;	
	L[1].Nome = "2";//"B";
	L[1].Peso = 3;
	L[1].Custo = 12;		
	L[2].Nome = "3";//"C";	
	L[2].Peso = 4;
	L[2].Custo = 40;	
	L[3].Nome = "4";//"D";	
	L[3].Peso = 5;
	L[3].Custo = 25;		
}

void ImprimeLista(Dados *L){
	int Cont;
	
	for(Cont=0;Cont<MAX;Cont++){
		cout << L[Cont].Nome << ", ";
	}		
}

//Caixeiro Viajante - Força Bruta
void GeraCaminhosFBruta(Dados *Lista, int M[MAX][MAX], int Inicio){
	int ContInicio,ContMeio1, ContMeio2;
	
	for (ContInicio= 0;ContInicio<MAX;ContInicio++){
		if (Inicio != ContInicio){
			// ContInicio tem q ser diferente do inicio para ser utilizado
			cout << endl  << Lista[Inicio].Nome << "->"<< Lista[ContInicio].Nome << ": " << M[Inicio][ContInicio];	
			
			for (ContMeio1= 0;ContMeio1<MAX;ContMeio1++){
				if(ContMeio1 != Inicio && ContMeio1!= ContInicio){
					// ContMeio1 tem q ser diferente do anterior e diferente do inicio para ser utilizado
					cout << endl << "  " << Lista[ContInicio].Nome << "->"<< Lista[ContMeio1].Nome << ": " << M[ContInicio][ContMeio1];
					
					for (ContMeio2= 0;ContMeio2<MAX;ContMeio2++){
						if(ContMeio2 != Inicio && ContMeio2!= ContInicio && ContMeio2!= ContMeio1){
							cout << endl << "  " << "  " << Lista[ContMeio1].Nome << "->"<< Lista[ContMeio2].Nome << ": " << M[ContMeio1][ContMeio2];
							cout << endl << "  " << "  " << "  " << Lista[ContMeio2].Nome << "->"<< Lista[Inicio].Nome << ": " << M[ContMeio2][Inicio];
							
							cout << endl << Lista[Inicio].Nome << "->"<< Lista[ContInicio].Nome << 
										"->"<< Lista[ContMeio1].Nome <<"->"<< Lista[ContMeio2].Nome << 
										"->"<< Lista[Inicio].Nome << " => " 
										<< M[Inicio][ContInicio] + M[ContInicio][ContMeio1]+
										M[ContMeio1][ContMeio2]+M[ContMeio2][Inicio];	
						}
					}
				}
			}
		}
	}
}

void bin(int x)
{
    if ( x != 0 ){        
        bin(x / 2);    
        cout << (x % 2);
    }  
}

void CalculaMochila(Dados *Lista, int Total, int PesoMax){
	int Cont, ContConjunto;
	float MaiorCusto, CustoAux, SomaPesos;
	string NomeConjunto, NomeAux;
	
	MaiorCusto = 0;
	NomeConjunto = "{0}";
	// gera todas as combinações
	for(ContConjunto = 0; ContConjunto < pow(2,Total); ContConjunto++){
		
		cout << endl;	
		cout << "{ ";
		CustoAux = 0;
		SomaPesos = 0;
		NomeAux = "{ ";
		
		// verifica se o elemento esta no conjunto corrente
		for (Cont = 0; Cont < Total; Cont++){	
		
			cout << "Item: ";
			bin((int)pow(2,Cont));
			cout << " Conjunto: ";
			if(ContConjunto == 0){
				cout << NomeConjunto;
			}
			bin(ContConjunto);
			cout << endl << "Pertence ao conjunto? ->" << (((int)pow(2,Cont)) & ContConjunto);
			
			if ((((int)pow(2,Cont)) & ContConjunto) != 0 ){		
				// & - 'E' binario, se for 1 e 1 da 1, 0 e 0 da 0, se for 1 e 0 da 0...	
				cout << " " << Lista[Cont].Nome << " ";
				NomeAux = NomeAux + Lista[Cont].Nome + " ";
				CustoAux = CustoAux + Lista[Cont].Custo;
				SomaPesos = SomaPesos + Lista[Cont].Peso;
			}						
			cout << endl;
		}
		
		cout << "}" << endl;
		NomeAux = NomeAux + "}";		
		
		if (MaiorCusto < CustoAux && ContConjunto!=0 && SomaPesos <= PesoMax){
			MaiorCusto = CustoAux;
			NomeConjunto = NomeAux;
		}
	}
}

Dados Lista[MAX];
//0=A, 1=B, 2=C e 3=D (Caixeiro Viajante)
int Matriz[MAX][MAX] = {0,2,8,5,
						2,0,3,4,	
						8,3,0,7,
						5,4,7,0};
						// organização de cada posicao ij da matriz:
						// A->A, A->B, A->C, A->D
						// B->A, B->B, B->C, B->D
						// C->A, C->B, C->C, C->D
						// D->A, D->B, D->C, D->D

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	//CarregaCidades(Lista);
	//GeraCaminhosFBruta(Lista, Matriz, 0);
	
	CarregaMochila(Lista);
	
	CalculaMochila(Lista, 4, 10);
	//ImprimeLista(Lista);
	
	//bin(10);
	
	return 0;
}
