#include <iostream>
// Implementacao dos algoritmos de ordenacao iterativo e recursivo - Selection Sort / Insertion Sort / Bubble Sort 
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX 10

struct Dados{
    int Valor;
    int Ordem;
};

//Carrega o vetor com valores aleat?rios
void CarregaLista(Dados *L, int GeraDados){
    int Cont;
    
    if (GeraDados){
        for(Cont=0;Cont<MAX;Cont++){
            L[Cont].Valor = rand()%100;
            L[Cont].Ordem = Cont;
        }        
    }
    else{
        L[0].Valor = 3; L[1].Valor = 3; L[2].Valor = 1; L[3].Valor = 2; L[4].Valor = 7;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        L[5].Valor = 0; L[6].Valor = 5; L[7].Valor = 4; L[8].Valor = 9; L[9].Valor = 6;
        L[5].Ordem = 5; L[6].Ordem = 6; L[7].Ordem = 7; L[8].Ordem = 8; L[9].Ordem = 9;
        /*
        L[0].Valor = 5; L[1].Valor = 4; L[2].Valor = 3; L[3].Valor = 2; L[4].Valor = 1;
        L[0].Ordem = 0; L[1].Ordem = 1; L[2].Ordem = 2; L[3].Ordem = 3; L[4].Ordem = 4;
        */
    }    
}

void ImprimeLista(Dados *L){
    int Cont;
    
    for(Cont=0;Cont<MAX;Cont++){
        cout <<    "[" << L[Cont].Ordem << "] " << L[Cont].Valor << ", ";
    }        
}

void Swap(Dados *L, int PosA, int PosB){
    Dados Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void SelectionSort(Dados *L, int Tam){
    int Cont1, Cont2, Min;
    
    for(Cont1=0;Cont1<Tam;Cont1++){
        Min = Cont1;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont2=Cont1+1;Cont2<Tam;Cont2++) {        
            if (L[Min].Valor > L[Cont2].Valor){
                Min = Cont2;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Cont1, Min);
    }                
}


void SelectionSortRec(Dados *L, int Inicio, int Fim){
    int Cont, Min;
    
    if(Inicio <= Fim){
    	Min = Inicio;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont=Inicio+1;Cont<=Fim;Cont++) {        
            if (L[Min].Valor > L[Cont].Valor){
                Min = Cont;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Inicio, Min);
        SelectionSortRec(L, Inicio+1, Fim);
	}                  
}

// usando backtraking
void SelectionSortRecBack(Dados *L, int Inicio, int Fim){
    int Cont, Min;
    
    if(Inicio <= Fim){
    	SelectionSortRec(L, Inicio+1, Fim);
    	
    	Min = Fim - Inicio;
    	// chegando na ultima chamada nos precisamos que o min seja 0, ent para isso vamos subtraindo o valor Inicio de Fim, assim eh como se fizessmos normalmente a incrementacao de min;
        
        //Procura o valor m?nimo na lista n?o ordenada
        for (Cont=Fim-Inicio;Cont<=Fim;Cont++) {        
            if (L[Min].Valor > L[Cont].Valor){
                Min = Cont;                
            }        
        }    
        
        //Move o valor encontrado pra lista ordenada
        Swap(L, Fim-Inicio, Min);        
	}                  
}


void InsertionSort(Dados *L, int Tam){
    int Cont1, Cont2;
    
    for(Cont1=1;Cont1<Tam;Cont1++){
        Cont2 = Cont1; //Pr?ximo item da lista n?o ordenada
        
        //Move o pr?ximo item da lista n?o ordenada para
        //a posi??o correta na lista ordenada
        while (Cont2 > 0 && L[Cont2].Valor < L[Cont2-1].Valor ) {        
            //Move o valor encontrado pra lista ordenada
            Swap(L, Cont2, Cont2-1);
            
            Cont2--;    
        } 		           
    }                
}

void BubbleSort(Dados *L , int Tam){
    int Cont1, Cont2, FezSwap;
    
    Cont1=0;
    do{    
        FezSwap = 0;    
        //Traz, a partir do fim da lista, cada menor valor
        //at? achar algum valor maior que ele. Se achar,
        //passa a fazer o mesmo com esse novo valor
        for (Cont2=Tam-1;Cont2>Cont1;Cont2--) {        
            if (L[Cont2].Valor < L[Cont2-1].Valor){
                //Troca os valores de posi??o
                Swap(L, Cont2, Cont2-1);
                FezSwap = 1;             
            }        
        }        
        
        Cont1++;                    
    } while (Cont1<Tam && FezSwap==1);
}

// BI3023613 - Miguel Totti
void BubbleSortRec(Dados *L , int Inicio, int Fim, int FezSwap){
    int Cont;
    
    if(Inicio <= Fim && FezSwap == 1){
    	FezSwap = 0;    
        for (Cont=Fim;Cont>Inicio;Cont--) {        
            if (L[Cont].Valor < L[Cont-1].Valor){
                //Troca os valores de posi??o
                Swap(L, Cont, Cont-1);
                FezSwap = 1;             
            }        
        } 
        
        BubbleSortRec(L , Inicio+1, Fim, FezSwap);
	}   
}

void MergeSort(Dados* L, int Inicio, int Fim, int Debug){
    int Meio, Cont, ContA, ContB;
    Dados* Aux;
    
    if (Inicio < Fim){
        Meio = (Inicio + Fim)/2;
    
    	//Quebra em vetores menores (metade)
        if (Debug) {
        	cout << "\nMergeSort(" << Inicio << "," << Meio << ")\n";
        	system("pause");
		}
    	MergeSort(L, Inicio, Meio, Debug); //VetorA
    	
    	if (Debug) {
        	cout << "\nMergeSort(" << Meio+1 << "," << Fim << ")\n";
        	system("pause");
		} 
		MergeSort(L, Meio+1, Fim, Debug); //VetorB
		
		ContA = Inicio;
        ContB = Meio+1;
        Cont = 0;
        Aux = (Dados *) malloc(sizeof(Dados) * (Fim - Inicio + 1));
        
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
                    if (L[ContA].Valor < L[ContB].Valor){ //meio do VetorA                    
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
            L[Cont].Valor = Aux[Cont - Inicio].Valor;
            L[Cont].Ordem = Aux[Cont - Inicio].Ordem;
            
            if (Debug) {
    			cout << "L["<<Cont<<"].Valor = Aux[" <<Cont - Inicio<<"] (" <<Aux[Cont - Inicio].Valor<<")" << "\n";
    			system("pause");				
   			}  
        }
        
        free(Aux);
	}
}
        
void QuickSortV(Dados *L, int Inicio, int Fim, int Msg){
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
            while (L[ContFim].Valor > L[Pivo].Valor && ContFim > Pivo);
            
            if (ContFim > Pivo){
                Swap(L, Pivo, ContFim);
                Pivo = ContFim;
        	}
        	
        	do{
                ContIni++;            
            } while (L[ContIni].Valor < L[Pivo].Valor && ContIni < Pivo);
            
            if (ContIni < Pivo){
                Swap(L, ContIni, Pivo);
                Pivo = ContIni;
            }
        
    	} while (ContIni < ContFim);
    	
    	QuickSortV(L, Inicio, Pivo-1, Msg);
    	
    	QuickSortV(L, Pivo+1, Fim, Msg);
	}
}

int EncontraPivo(Dados* L, int Inicio, int Fim){
	int pivo, i, j;
	Dados Aux;
	
	pivo = Fim;
	i = j = Inicio;
	
	while(j < Fim){
		
		if(L[j].Valor <= L[pivo].Valor){
			
			Aux = L[j];
			L[j] = L[i];
			L[i] = Aux;
			
			i++;
		}
		
		j++;
	}
	
	Aux = L[pivo];
	L[pivo] = L[i];
	L[i] = Aux;
	
	return i;
}

void QuickSort(Dados* L, int Inicio, int Fim){
	int pivo;
	
	if(Inicio < Fim){
		
		pivo = EncontraPivo(L, Inicio, Fim);
		
		QuickSort(L, Inicio, pivo-1);
		QuickSort(L, pivo+1, Fim);
	}
}

void InicializaVetor(Dados* LOri, Dados* LDest){
	int Cont;
	
	for(Cont = 0; Cont < MAX; Cont++){
		LDest[Cont] = LOri[Cont];
	}
}

void ExecutaSort(int SortInd, Dados* ListaBase){
	Dados Lista[MAX];
	clock_t T;
	string SortAlg;
	
	InicializaVetor(ListaBase, Lista);
	
	T = clock();
	switch(SortInd){
		case 1:
			SortAlg = "SelectionSort";
			SelectionSort(Lista, MAX);
			break;
		case 2:
			SortAlg = "InsertionSort";
			InsertionSort(Lista, MAX);
			break;
		case 3:
			SortAlg = "BubbleSort";
			BubbleSort(Lista, MAX);
			break;
		case 4:
			SortAlg = "MergeSort";
			MergeSort(Lista, 0, MAX-1, 0);
			break;
		case 5: 
			SortAlg = "QuickSort";
			QuickSort(Lista, 0, MAX-1);
			break;
		default:
			SortAlg = "QuickSortV";
			QuickSortV(Lista, 0, MAX-1, 0);
			break;
	}
	T = clock() - T;
	
	cout << endl << endl << "Tempo [" << SortAlg << "]:"<< ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos." <<endl;
	
	//ImprimeLista(Lista);
}
        

Dados ListaBase[MAX];
clock_t T;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	//CarregaLista(ListaBase,0); 
    CarregaLista(ListaBase,1);
	
	if (MAX <= 100){
        cout << endl << endl << "Lista original" << endl << endl;    
        ImprimeLista(ListaBase);        
    }

	//T = clock();
    //SelectionSort(Lista, MAX);
    //SelectionSortRec(Lista, 0, MAX-1);
    //SelectionSortRecBack(Lista, 0, MAX-1);
    //T = clock() - T;//tempo decorrido!!
    //cout << endl << endl << "Tempo de Ordenação SELECTION: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
    
    //T = clock();
    //InsertionSort(Lista, MAX);
    //T = clock() - T;//tempo decorrido!!
    //cout << endl << endl << "Tempo de Ordenação INSERTION: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";

    //T = clock();
    //BubbleSort(Lista, MAX);
    //BubbleSortRec(Lista, 0, MAX-1, 1);
    //T = clock() - T;//tempo decorrido!!
    //cout << endl << endl << "Tempo de Ordenação BUBBLE: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
    
    //T = clock();
    //MergeSort(Lista, 0, MAX-1, 0);
    //T = clock() - T;//tempo decorrido!!
    //cout << endl << endl << "Tempo de Ordenação BUBBLE: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
    
    //T = clock();
    //QuickSort(Lista, 0, MAX-1, 0);
    //T = clock() - T;//tempo decorrido!!
    //cout << endl << endl << "Tempo de Ordenação BUBBLE: " << ((double) T)/((CLOCKS_PER_SEC/1000)) << " milisegundos.";
    
    ExecutaSort(5, ListaBase);
    // maiss lento
    
    /*if (MAX <= 100){
        cout << endl << endl << "Lista ordenada" << endl << endl;    
        ImprimeLista(ListaBase);        
    }*/
    
    //ExecutaSort(1, ListaBase);
    //ExecutaSort(2, ListaBase);
    //ExecutaSort(3, ListaBase);
    //ExecutaSort(4, ListaBase);
    ExecutaSort(6, ListaBase);
    // quick sort do valtemir
		
	return 0;
}         
