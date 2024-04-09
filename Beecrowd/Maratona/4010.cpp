#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 1000000

void swap(float *Lista, int a, int b){
	float aux;
	
	aux = Lista[a];
	Lista[a] = Lista[b];
	Lista[b] = aux;
}

void QuickSort(float *L, int Inicio, int Fim){
    int Pivo, ContIni, ContFim;

    if (Inicio < Fim){
    	
        Pivo = Inicio;        
        ContIni = Inicio;        
        ContFim = Fim + 1;
        do{    
        
            do{
                ContFim--;
            }            
            while (L[ContFim] > L[Pivo] && ContFim > Pivo);
            
            if (ContFim > Pivo){
                swap(L, Pivo, ContFim);
                
                Pivo = ContFim;
            }                            
                                            
            do{
                ContIni++;            
            } while (L[ContIni] < L[Pivo] && ContIni < Pivo);
                                    
            if (ContIni < Pivo){
                swap(L, ContIni, Pivo);
				   
                Pivo = ContIni;                
            }    
            
        } while (ContIni < ContFim);
        
        QuickSort(L, Inicio, Pivo-1);
        QuickSort(L, Pivo+1, Fim);
    }
}

float Lista[MAX];
int main(){
	
	int N = 0;
	
	cin>>N;
	
	for(int i = 0; i < N; i++){
		cin>>Lista[i];
	}
	
	QuickSort(Lista, 0, N-1);
	
	for(int i = 0; i < N; i++){
		cout<<fixed<<setprecision(2)<<Lista[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
