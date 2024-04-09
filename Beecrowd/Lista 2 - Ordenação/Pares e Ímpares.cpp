#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100000

/*
void Swap(int L[], int PosA, int PosB){
    int Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSortPar(int L[]){
    int Cont1, Cont2, Min;
    int Tam = sizeof(L)/sizeof(L[0]);
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min] > L[Cont2]){
                Min = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);
    }                
} */

void MergeSortPar(int* L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    int* Aux;
    
    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;
    
    	//Quebra em vetores menores (metade)
        if (Debug) {
        	cout << "\nMergeSort(" << Inicio << "," << Meio << ")\n";
        	system("pause");
		}
    	MergeSortPar(L, Inicio, Meio, Debug); //VetorA
    	
    	if (Debug) {
        	cout << "\nMergeSort(" << Meio+1 << "," << Fim << ")\n";
        	system("pause");
		} 
		MergeSortPar(L, Meio+1, Fim, Debug); //VetorB
		
		ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (int *) malloc(sizeof(int) * (Fim - Inicio + 1));
        
        if (Debug) {
        	cout << "\nInicio: " << Inicio << " Meio: " << Meio << " Fim: " << Fim;
        	cout << "\nContA:" << ContA;
        	cout << "\nContB:" << ContB;
        	cout << "\nCont:" << Cont << "\n";
        	system("pause");
		}      
        
        while (ContA <= Meio || ContB <= Fim){
        	if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L[ContB];
                
                if (Debug) {
        			cout << "\nJ? processou vetor esquerdo (A). Copiando vetor direito (B)";
        			cout << "\nContA:" << ContA;
        			cout << "\nContB:" << ContB;
        			cout << "\nCont:" << Cont << "\n";
        			system("pause");
				}   
                
                ContB++; 
        	}
        	else{
        		if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L[ContA];
                    
                    if (Debug) {
	        			cout << "\nJ? processou vetor direito (B). Copiando vetor esquerdo (A)";
	        			cout << "\nContA:" << ContA;
	        			cout << "\nContB:" << ContB;
	        			cout << "\nCont:" << Cont << "\n";
	        			system("pause");
	       			}
                    
                    ContA++; 
				}
				else{
                    if (L[ContA] < L[ContB]){ //meio do VetorA                    
                        Aux[Cont] = L[ContA];
                        
                        if (Debug) {
		        			cout << "\n1? item do vetor esquerdo (A) menor do que 1? item do vetor direito (B). Copiando item do vetor (A) para Aux.";
		        			cout << "\nContA:" << ContA;
		        			cout << "\nContB:" << ContB;
		        			cout << "\nCont:" << Cont << "\n";
		        			system("pause");
		       			}
                        
                        ContA++;
                    }
                    else{
                    	Aux[Cont] = L[ContB];
                    	
                    	if (Debug) {
		        			cout << "\n1? item do vetor direito (B) menor ou igual do que 1? item do vetor esquerdo (A). Copiando item do vetor (B) para Aux.";
		        			cout << "\nContA:" << ContA;
		        			cout << "\nContB:" << ContB;
		        			cout << "\nCont:" << Cont << "\n";
		        			system("pause");
		       			} 
                    	
                    	ContB++;
					}
            	}	
			}
			
			Cont++; //passa para a pr?xima posi??o do vetor com o merge
    	}
    	
    	//Copia o merge ordenado dos vetores para o vetor original    
        for(Cont=Inicio;Cont<=Fim;Cont++){
            L[Cont] = Aux[Cont - Inicio];
            
            if (Debug) {
    			cout << "L["<<Cont<<"].Valor = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio]<<")" << "\n";
    			system("pause");				
   			}  
        }
        
        free(Aux);
	}
}
/*
void SelectionSortImpar(int L[]){
    int Cont1, Cont2, Min;
    int Tam = sizeof(L)/sizeof(L[0]);
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min] < L[Cont2]){
                Min = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);
    }                
} */

void MergeSortImpar(int* L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    int* Aux;
    
    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;
    
    	//Quebra em vetores menores (metade)
        if (Debug) {
        	cout << "\nMergeSort(" << Inicio << "," << Meio << ")\n";
        	system("pause");
		}
    	MergeSortImpar(L, Inicio, Meio, Debug); //VetorA
    	
    	if (Debug) {
        	cout << "\nMergeSort(" << Meio+1 << "," << Fim << ")\n";
        	system("pause");
		} 
		MergeSortImpar(L, Meio+1, Fim, Debug); //VetorB
		
		ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (int *) malloc(sizeof(int) * (Fim - Inicio + 1));
        
        if (Debug) {
        	cout << "\nInicio: " << Inicio << " Meio: " << Meio << " Fim: " << Fim;
        	cout << "\nContA:" << ContA;
        	cout << "\nContB:" << ContB;
        	cout << "\nCont:" << Cont << "\n";
        	system("pause");
		}      
        
        while (ContA <= Meio || ContB <= Fim){
        	if (ContA > Meio){ //final do VetorA
                Aux[Cont] = L[ContB];
                
                if (Debug) {
        			cout << "\nJ? processou vetor esquerdo (A). Copiando vetor direito (B)";
        			cout << "\nContA:" << ContA;
        			cout << "\nContB:" << ContB;
        			cout << "\nCont:" << Cont << "\n";
        			system("pause");
				}   
                
                ContB++; 
        	}
        	else{
        		if (ContB > Fim){ //final do VetorB
                    Aux[Cont] = L[ContA];
                    
                    if (Debug) {
	        			cout << "\nJ? processou vetor direito (B). Copiando vetor esquerdo (A)";
	        			cout << "\nContA:" << ContA;
	        			cout << "\nContB:" << ContB;
	        			cout << "\nCont:" << Cont << "\n";
	        			system("pause");
	       			}
                    
                    ContA++; 
				}
				else{
                    if (L[ContA] > L[ContB]){ //meio do VetorA                    
                        Aux[Cont] = L[ContA];
                        
                        if (Debug) {
		        			cout << "\n1? item do vetor esquerdo (A) menor do que 1? item do vetor direito (B). Copiando item do vetor (A) para Aux.";
		        			cout << "\nContA:" << ContA;
		        			cout << "\nContB:" << ContB;
		        			cout << "\nCont:" << Cont << "\n";
		        			system("pause");
		       			}
                        
                        ContA++;
                    }
                    else{
                    	Aux[Cont] = L[ContB];
                    	
                    	if (Debug) {
		        			cout << "\n1? item do vetor direito (B) menor ou igual do que 1? item do vetor esquerdo (A). Copiando item do vetor (B) para Aux.";
		        			cout << "\nContA:" << ContA;
		        			cout << "\nContB:" << ContB;
		        			cout << "\nCont:" << Cont << "\n";
		        			system("pause");
		       			} 
                    	
                    	ContB++;
					}
            	}	
			}
			
			Cont++; //passa para a pr?xima posi??o do vetor com o merge
    	}
    	
    	//Copia o merge ordenado dos vetores para o vetor original    
        for(Cont=Inicio;Cont<=Fim;Cont++){
            L[Cont] = Aux[Cont - Inicio];
            
            if (Debug) {
    			cout << "L["<<Cont<<"].Valor = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio]<<")" << "\n";
    			system("pause");				
   			}  
        }
        
        free(Aux);
	}
}

void Imprimir(int L[], int Tam){
	int i;
	
	for(i = 0; i < Tam; i++){
		cout<<L[i]<<endl;
	}
}

int Numeros[MAX], Par[MAX], Impar[MAX];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qtde_numeros=0;
	int verifica = 0;
	int num;
	int i = 0, tp=0, ti=0;
	
	while(verifica == 0){
		cin>>qtde_numeros;
		if(1 < qtde_numeros && qtde_numeros <= MAX){
			verifica = 1;
		}
	}
	
	// inserindo no vetor
	while(i < qtde_numeros){
		cin>>num;
		
		if(num >= 0){
			if(num%2==0){
				Par[tp] = num;
				tp++;
			}
			else{
				Impar[ti] = num;
				ti++;
			}
			
			i++;
		}
	}
	//cout<<endl;
	//SelectionSortPar(Par);
	//SelectionSortImpar(Impar);
	MergeSortPar(Par, 0, tp-1, 0);
	MergeSortImpar(Impar, 0, ti-1, 0);
	
	
	Imprimir(Par, tp);
	Imprimir(Impar, ti);
	
	return 0;
}
