#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Camisetas{
	//char nome[100];
	string nome;
	char cor[10];
	char tam[2];
};

void Swap(Camisetas *L, int PosA, int PosB){
    Camisetas Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSort(Camisetas *Lista, int Tam){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (strcmp(Lista[Min].cor, Lista[Cont2].cor) > 0){
                Min = Cont2;                
            }
			else{
				if(strcmp(Lista[Min].cor, Lista[Cont2].cor) == 0){
					
					if(strcmp(Lista[Min].tam, Lista[Cont2].tam) < 0){
						Min = Cont2;
					}
					else{
						if(strcmp(Lista[Min].tam, Lista[Cont2].tam) == 0){
							
							if(Lista[Min].nome > Lista[Cont2].nome){
								Min = Cont2;
							}
						}
					}
				}
			}        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(Lista, Cont1, Min);
    }                
}

Camisetas Lista[60];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int Num_Camisetas, Cont;
	bool Primeiro = true;
	
	while(cin>>Num_Camisetas && Num_Camisetas != 0){
		
		if(!Primeiro){
			cout<<endl;
		}
		else{
			Primeiro = false;
		}
		
		for(Cont=0; Cont < Num_Camisetas; Cont++){
			cin.ignore();
			getline(cin, Lista[Cont].nome);
			
			cin>>Lista[Cont].cor>>Lista[Cont].tam;	
		}
		
		SelectionSort(Lista, Num_Camisetas);
		
		for(Cont=0; Cont < Num_Camisetas; Cont++){
			cout<<Lista[Cont].cor<<" "<<Lista[Cont].tam<<" "<<Lista[Cont].nome<<"\n";
		}
	}
	
	return 0;
}
