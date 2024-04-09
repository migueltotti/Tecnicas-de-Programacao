#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10000

struct Estudantes{
	char nome[50];
	char regiao;
	int distancia;
};

void Swap(Estudantes L[], int PosA, int PosB){
    Estudantes Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

/*int IndiceRegiao(Estudantes Item, char regioes[]){
	int ret = 0;
	
	for(int i = 0; i < strlen(regioes); i++){
		if(Item.regiao == regioes[i]){
			ret = i;
		}
	}
	
	return ret;
}

int IndiceInicial(Estudantes Item, char caracteres[]){
	int ret = 0;
	
	for(int i = 0; i < strlen(caracteres); i++){
		if(Item.nome[0] == caracteres[i]){
			ret = i;
		}
	}
	
	return ret;
}

void SelectionSort(Estudantes L[], int Tam){//, char caracteres[], char regioes[]){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min].distancia > L[Cont2].distancia){
                Min = Cont2;                
            }
			else{
				
				if(L[Min].distancia == L[Cont2].distancia){
					
					if(L[Min].regiao > L[Cont2].regiao){
						Min = Cont2;
					}
					else{
						
						if(L[Min].regiao == L[Cont2].regiao){
							
							if(L[Min].distancia > L[Cont2].distancia){
								Min = Cont2;
							}
						}
					}
				}
			}        
        }    
        
        Swap(L, Cont1, Min);
    }                
}
*/

int EncontraPivo(Estudantes* L, int Inicio, int Fim){
	int pivo, i, j;
	Estudantes Aux;
	
	pivo = Fim;
	i = j = Inicio;
	
	while(j < Fim){
		
		if(L[j].distancia < L[pivo].distancia){
			
			Aux = L[j];
			L[j] = L[i];
			L[i] = Aux;
			
			i++;
		}
		else{
			if(L[j].distancia == L[pivo].distancia){
				
				if(L[j].regiao < L[pivo].regiao){
					Aux = L[j];
					L[j] = L[i];
					L[i] = Aux;
					
					i++;
				}
				else{
					if(L[j].regiao == L[pivo].regiao){
						
						if(L[j].nome[0] < L[pivo].nome[0]){
							Aux = L[j];
							L[j] = L[i];
							L[i] = Aux;
							
							i++;
						}
					}
				}
			}
		}
		
		j++;
	}
	
	Aux = L[pivo];
	L[pivo] = L[i];
	L[i] = Aux;
	
	return i;
}

void QuickSort(Estudantes* L, int Inicio, int Fim){
	int pivo;
	
	if(Inicio < Fim){
		
		pivo = EncontraPivo(L, Inicio, Fim);
		
		QuickSort(L, Inicio, pivo-1);
		QuickSort(L, pivo+1, Fim);
	}
}

void ImprimirLista(Estudantes Lista[], int Tam){
	
	//cout<<endl;
	for(int i = 0; i < Tam; i++){
		cout<<Lista[i].nome<<"\n";
	}
	//cout<<"\n";
}


Estudantes Lista[MAX];
//char caracteres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//char regioes[4] = {'L', 'N', 'O', 'S'};
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde_estudantes;
	
	while(cin>>qtde_estudantes){
		
		for(int i = 0; i < qtde_estudantes; i++){
			cin>>Lista[i].nome>>Lista[i].regiao>>Lista[i].distancia;
		}
		
		// ordenar a lista pref.: distancia -> regiao -> nome
		//SelectionSort(Lista, qtde_estudantes);//, caracteres, regioes);
		QuickSort(Lista, 0, qtde_estudantes-1);
		
		ImprimirLista(Lista, qtde_estudantes);
	}
	
	
	return 0;
}
