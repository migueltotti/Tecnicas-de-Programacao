#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define MAX_ITENS 10

struct Itens{
	char nome_item[20];
	unsigned int validade_item;
};

void Swap(Itens L[], int PosA, int PosB){
    Itens Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void QuickSort(Itens *L, int Inicio, int Fim, int Msg){
    int Pivo, ContIni, ContFim;

    if (Inicio < Fim){
    	//Processar posi??o do piv?, de forma que os elementos sucessivos
        //sejam maiores e os antecessores menores
        Pivo = Inicio;        
        ContIni = Inicio;        
        ContFim = Fim + 1;
        do{  
        	// 4 2 8 10 6 7 1
        	// 1 2 8 10 6 7 4
        	// 1 2 4 10 6 7 8
        	//Busca primeiro menor que o piv? da direita para a esquerda
            do{
                ContFim--;
            }            
            while (L[ContFim].validade_item > L[Pivo].validade_item && ContFim > Pivo);
            
            if (ContFim > Pivo){
                Swap(L, Pivo, ContFim);
                Pivo = ContFim;
        	}
        	
        	do{
                ContIni++;            
            } while (L[ContIni].validade_item < L[Pivo].validade_item && ContIni < Pivo);
            
            if (ContIni < Pivo){
                Swap(L, ContIni, Pivo);
                Pivo = ContIni;
            }
        
    	} while (ContIni < ContFim);
    	
    	QuickSort(L, Inicio, Pivo-1, Msg);
    	
    	QuickSort(L, Pivo+1, Fim, Msg);
	}
}



Itens Lista[MAX_ITENS];
int main(){
	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	setlocale(LC_ALL, "Portuguese");
	
	unsigned int qtde_itens=0;
	int i=0;
	Itens Item;
	
	while(scanf("%d", &qtde_itens)){
		
		//if(0 < qtde_itens && qtde_itens <= 10){
		
		for(i = 0; i < qtde_itens; i++){
			cin>>Lista[i].nome_item>>Lista[i].validade_item;
			//scanf("%s %d", Lista[i].nome_item, Lista[i].validade_item);
			//cin.getline(Lista[i].nome_item, 20, ' ');
			//scanf("%d", Lista[i].validade_item);
		}

		QuickSort(Lista, 0, qtde_itens-1, 0);
		
		for(i = 0; i < qtde_itens; i++){
			//cout<<Lista[i].nome_item<<" ";
			printf("%s ", Lista[i].nome_item);
		}
		//cout<<"\n";
		printf("\n");
	}

	return 0;
}
