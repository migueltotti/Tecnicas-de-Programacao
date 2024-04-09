#include <iostream>

using namespace std;

struct Presentes{
	int Id;
	int volume;
};

void SwapV(Presentes *L, int PosA, int PosB){
    Presentes Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SwapI(int *L, int PosA, int PosB){
    int Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

// ordenar pelo volume
int EncontraPivoV(Presentes* L, int Inicio, int Fim){
	int pivo, i, j;
	
	pivo = Fim;
	i = j = Inicio;
	
	while(j < Fim){
		
		if(L[j].volume > L[pivo].volume){
			
			SwapV(L, j, i);
			
			i++;
		}
		else if(L[j].volume == L[pivo].volume){
			if(L[j].Id < L[pivo].Id){
				SwapV(L, j, i);
				i++;
			}
		}
		
		j++;
	}
	
	SwapV(L, i, pivo);
	
	return i;
}

void QuickSortV(Presentes* L, int Inicio, int Fim){
	int pivo;
	
	if(Inicio < Fim){
		
		pivo = EncontraPivoV(L, Inicio, Fim);
		
		QuickSortV(L, Inicio, pivo-1);
		QuickSortV(L, pivo+1, Fim);
	}
}

// ordenar pelo id apos o volume
int EncontraPivoI(int* L, int Inicio, int Fim){
	int pivo, i, j;
	
	pivo = Fim;
	i = j = Inicio;
	
	while(j < Fim){
		
		if(L[j] < L[pivo]){
			
			SwapI(L, j, i);
			
			i++;
		}
		
		j++;
	}
	
	SwapI(L, i, pivo);
	
	return i;
}

void QuickSortI(int* L, int Inicio, int Fim){
	int pivo;
	
	if(Inicio < Fim){
		
		pivo = EncontraPivoI(L, Inicio, Fim);
		
		QuickSortI(L, Inicio, pivo-1);
		QuickSortI(L, pivo+1, Fim);
	}
}

Presentes Lista[100100];
int Ids[100100];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int T, N, K;
	int I, H, W, L;
	
	//cin>>T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		//cin>>N>>K;
		scanf("%d %d", &N, &K);
		for(int j = 0; j < N; j++){
			//cin>>I>>H>>W>>L;
			scanf("%d %d %d %d", &I, &H, &W, &L);
			Lista[j].Id = I;
			Lista[j].volume = H * W * L;
		}
		
		QuickSortV(Lista, 0, N-1);
		
		for(int j = 0; j < K; j++){
			//cout<<Lista[j].Id<<endl;
			Ids[j] = Lista[j].Id;
			//cout<<Ids[j]<<endl;
		}
		
		QuickSortI(Ids, 0, K-1);
		
		for(int j = 0; j < K; j++){
			if(j < K-1)
				printf("%d ", Ids[j]);
				//cout<<Lista[j].Id<<" ";
			else
				printf("%d", Ids[j]);
				//cout<<Lista[j].Id;
		}
		printf("\n");
	}
	
	return 0;
}
