#include <iostream>
#include <math.h>

using namespace std; //para usar com cin e cout

#define MAX 3

struct Dados{
	string Nome;
	float Peso;
	float PesoUtilizado;
	float Custo;		
	float CustoUnit;
};

//Carrega o vetor com valores aleat?rios
void CarregaLista(Dados *L){

	/*L[0].Nome = "1";//"A";
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
	L[3].Custo = 25;*/	
	L[0].Nome = "1";
	L[0].Peso = 10;
	L[0].Custo = 60;
	L[0].CustoUnit = 6;	
	L[1].Nome = "2";
	L[1].Peso = 20;
	L[1].Custo = 100;		
	L[1].CustoUnit = 5; 
	L[2].Nome = "3";
	L[2].Peso = 30;		
	L[2].Custo = 120;		
	L[2].CustoUnit = 4;
}

void ImprimeLista(Dados *L){
	int Cont;
	
	for(Cont=0;Cont<MAX;Cont++){
		cout << endl << L[Cont].Nome << ", Peso utilizado: " << L[Cont].PesoUtilizado;
	}		
}

void Swap(Dados *L, int PosA, int PosB){
    Dados Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSort(Dados *L, char TipoOrd, char TipoCusto){
    int Cont1, Cont2, Aux;
    
    for(Cont1=0;Cont1<MAX;Cont1++){
        Aux = Cont1;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont2=Cont1+1;Cont2<MAX;Cont2++) {        
            if ((((L[Aux].Custo > L[Cont2].Custo && TipoOrd == 'C') ||
				(L[Aux].Custo < L[Cont2].Custo && TipoOrd == 'D')) && TipoCusto == 'T') ||
				(((L[Aux].CustoUnit > L[Cont2].CustoUnit && TipoOrd == 'C') ||
				(L[Aux].CustoUnit < L[Cont2].CustoUnit && TipoOrd == 'D')) && TipoCusto == 'U')){  				
                Aux = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Aux);        
    }                
}

//Tipo = T ou U (Mochila Fracionada)
float CalculaMochilaGuloso(Dados *L, float TotalMochila, char Tipo){    
    float Carga=0;
    float Total=0;
    int Cont=0;
    
    SelectionSort(L,  'D', Tipo);
    
    while(Carga < TotalMochila && Cont <= MAX ){
        if (L[Cont].Peso <= (TotalMochila - Carga)){
            L[Cont].PesoUtilizado = L[Cont].Peso;
            Carga = Carga + L[Cont].PesoUtilizado;            
        }
        else{ //Se for fracionada, processa tamb?m pelo custo unit?rio
            if (Tipo == 'U'){
                L[Cont].PesoUtilizado = TotalMochila - Carga;
                Carga = Carga + L[Cont].PesoUtilizado;
            }            
        }
        
        Total += L[Cont].PesoUtilizado * L[Cont].CustoUnit;
        
        Cont++;
    }    
    
    return Total;
}


void bin(int x)
{
    if ( x != 0 ){        
        bin(x / 2);    
        cout << (x % 2);
    }         
}

//Mochila - For?a Bruta
void CalculaMochila(Dados *Lista, int Total, int PesoMax){
	int Cont, ContConjunto;
	float MaiorCusto, CustoAux, SomaPesos;
	string NomeConjunto, NomeAux;
	
	MaiorCusto = Lista[0].Custo;
	NomeConjunto = "{0}";
	for(ContConjunto = 0; ContConjunto < pow(2,Total); ContConjunto++){
		cout << endl;	
		cout << "{ ";
		CustoAux = 0;
		SomaPesos = 0;
		NomeAux = "{ ";
		for (Cont = 0; Cont < Total; Cont++){				
			cout << "Item: ";
			bin((int)pow(2,Cont));
			cout << " Conjunto: ";
			bin(ContConjunto);
			cout << endl << "Pertence ao conjunto? ->" << (((int)pow(2,Cont)) & ContConjunto);
			if ((((int)pow(2,Cont)) & ContConjunto) != 0 ){			
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
	
	cout << endl << endl << "A mochila " << NomeConjunto << " tem o melhor preenchimento!! (Custo = " << MaiorCusto << ")";
}

Dados Lista[MAX];
int main(){
	setlocale(LC_ALL, "Portuguese");

	CarregaLista(Lista);
	//CalculaMochila(Lista, 4, 10);
	cout<< " Valor Total: " << CalculaMochilaGuloso(Lista, 50, 'U');
	ImprimeLista(Lista);
	
	return 0;
}
