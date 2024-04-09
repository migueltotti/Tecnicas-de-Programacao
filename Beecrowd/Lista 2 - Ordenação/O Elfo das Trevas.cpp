#include <iostream>
#include <cstring>

using namespace std;

struct Renas{
	char nome[100];
	int peso;
	int idade;
	float altura;
};

int IndiceInicial(Renas Item, char caracteres[]){
	int ret = 0;
	
	for(int i = 0; i < strlen(caracteres); i++){
		if(Item.nome[0] == caracteres[i]){
			ret = i;
		}
	}
	
	return ret;
}

void Swap(Renas L[], int PosA, int PosB){
    Renas Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSort(Renas L[], int Tam){//, char caracteres[]){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;

        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min].peso < L[Cont2].peso){
                Min = Cont2;                
            }
			else{
				
				if(L[Min].peso == L[Cont2].peso){
					
					if(L[Min].idade > L[Cont2].idade){
						Min = Cont2;	
					}
					else{
						if(L[Min].idade == L[Cont2].idade){
							
							if(L[Min].altura > L[Cont2].altura){
								Min = Cont2;
							}
							else{
								
								if(L[Min].altura == L[Cont2].altura){
									
									if(L[Min].nome[0] > L[Cont2].nome[0]){
										Min = Cont2;
									}
									/*if(IndiceInicial(L[Min], caracteres) > IndiceInicial(L[Cont2], caracteres)){
										Min = Cont2;
									}*/
								}
							}
						}
					}
				}
			}        
        }    

        Swap(L, Cont1, Min);
    }                
}

void ImprimeLista(Renas Lista[], int Tam){
	for(int i = 0; i < Tam; i++){
		cout<<i+1<<" - "<<Lista[i].nome<<endl;
	}
}

Renas Lista[100000];
//char caracteres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int casos_teste = 0;
	int num_max = 1, num_renas = 1;
	
	do{
		cin>>casos_teste;
	}while(1 > casos_teste || casos_teste > 10000);
	
	for(int i = 0; i < casos_teste; i++){
		
		do{
			cin>>num_max>>num_renas;
		}while((1 > num_max || num_max > 10000) && (1 > num_renas || num_renas > 10000));
		
		for(int i = 0; i < num_max; i++){
			cin>>Lista[i].nome>>Lista[i].peso>>Lista[i].idade>>Lista[i].altura;
		}
		
		SelectionSort(Lista, num_max);//, caracteres);
		
		cout<<"CENARIO {"<<i+1<<"}"<<endl;
		ImprimeLista(Lista, num_renas);
	}
	
	return 0;
}
