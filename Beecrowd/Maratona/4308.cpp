#include <iostream>
#include <stdlib.h>

#define MAX 1000000

using namespace std;

struct Pessoas{
	int Senha;
	unsigned int Idade;
};

void swap(Pessoas *Lista, int a, int b){
	Pessoas aux;
	
	aux = Lista[a];
	Lista[a] = Lista[b];
	Lista[b] = aux;
}

void MergeSort(Pessoas* L, int Inicio, int Fim, int Debug, char Opcao){
    int Meio, Cont, ContA, ContB;
    Pessoas* Aux;
    
    if(Opcao == 'P'){
    	if (Inicio < Fim){
	        Meio = (Inicio + Fim)/2;    
	        
	        //Quebra em vetores menores (metade)
        
	        MergeSort(L, Inicio, Meio, Debug, Opcao); //VetorA
 
	        MergeSort(L, Meio+1, Fim, Debug, Opcao); //VetorB
	        
	        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
	        //de forma ordenada
	        ContA = Inicio;
	        ContB = Meio+1;
	        Cont = 0;
	        Aux = (Pessoas *) malloc(sizeof(Pessoas) * (Fim - Inicio + 1));
        
	        while (ContA <= Meio || ContB <= Fim){
	            if (ContA > Meio){ //final do VetorA
	                Aux[Cont] = L[ContB];
  
					ContB++;      
	            }            
	            else{
	                if (ContB > Fim){ //final do VetorB
	                    Aux[Cont] = L[ContA];
	
						ContA++;				                    
		           	}	
	                else{
	                    if (L[ContA].Idade > L[ContB].Idade){ //meio do VetorA                    
	                        Aux[Cont] = L[ContA];
	                               
							ContA++; 						                                               
	                    }
	                    else{ //meio do VetorB
	                        Aux[Cont] = L[ContB];                      
                  
							ContB++;                                                      
	                    }
	                }
	            }            
	            Cont++;            
	        }  
	        for(Cont=Inicio;Cont<=Fim;Cont++){
	            L[Cont].Idade = Aux[Cont - Inicio].Idade;
	            L[Cont].Senha = Aux[Cont - Inicio].Senha;                                                           
	        }    
	        
	        free(Aux);    
	    }        
	}
	else{
		if (Inicio < Fim){
	        Meio = (Inicio + Fim)/2;    
	        
	        //Quebra em vetores menores (metade)
       
	        MergeSort(L, Inicio, Meio, Debug, Opcao); //VetorA
 
	        MergeSort(L, Meio+1, Fim, Debug, Opcao); //VetorB
	        
	        //Junta as partes (merge), pegando sempre o menor elemento de cada parte
	        //de forma ordenada
	        ContA = Inicio;
	        ContB = Meio+1;
	        Cont = 0;
	        Aux = (Pessoas *) malloc(sizeof(Pessoas) * (Fim - Inicio + 1));
       
	        while (ContA <= Meio || ContB <= Fim){
	            if (ContA > Meio){ //final do VetorA
	                Aux[Cont] = L[ContB];
	                  
					ContB++;      
	            }            
	            else{
	                if (ContB > Fim){ //final do VetorB
	                    Aux[Cont] = L[ContA];
		
						ContA++;				                    
		           	}	
	                else{
	                    if (L[ContA].Idade < L[ContB].Idade){ //meio do VetorA                    
	                        Aux[Cont] = L[ContA];
	                             
							ContA++; 						                                               
	                    }
	                    else{ //meio do VetorB
	                        Aux[Cont] = L[ContB];                      
							                   
							ContB++;                                                      
	                    }
	                }
	            }            
	            Cont++;            
	        }  
	        for(Cont=Inicio;Cont<=Fim;Cont++){
	            L[Cont].Idade = Aux[Cont - Inicio].Idade;
	            L[Cont].Senha = Aux[Cont - Inicio].Senha;                                                           
	        }    
	        
	        free(Aux);    
	    }
	}
}


Pessoas ListaP[MAX], ListaN[MAX];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int N, Cont, ContP=0, ContN=0;
	Pessoas Item;
	
	cin>>N;
	
	for(Cont = 0; Cont < N; Cont++){
		cin>>Item.Senha>>Item.Idade;
		
		if(Item.Idade >= 60){
			ListaP[ContP] = Item;
			ContP++;
		}
		else{
			ListaN[ContN] = Item;
			ContN++;
		}
		
		//cout<<ContP<<endl;
		//cout<<ContN<<endl;
	}
	
	//cout<<ListaN[0].Senha<<" "<<ListaN[0].Idade;
	
	/*cout<<endl;
	for(Cont = 0; Cont < ContP; Cont++){
		cout<<ListaP[Cont].Senha<<" "<<ListaP[Cont].Idade<<"\n";
	}
	
	for(Cont = 0; Cont < ContN; Cont++){
		cout<<ListaN[Cont].Senha<<" "<<ListaN[Cont].Idade<<"\n";
	}*/
	
	//cout<<ContP<<endl<<ContN<<endl;
	//cout<<ListaN[1].Senha<<" "<<ListaN[Cont].Idade;
	
	MergeSort(ListaP, 0, ContP-1, 0, 'P');
	
	cout<<"Atendimento prioritario:\n";
	for(Cont = 0; Cont < ContP; Cont++){
		cout<<ListaP[Cont].Senha<<" "<<ListaP[Cont].Idade<<"\n";
	}
	
	cout<<"Atendimento normal:\n";
	for(Cont = 0; Cont < ContN; Cont++){
		cout<<ListaN[Cont].Senha<<" "<<ListaN[Cont].Idade<<"\n";
	}
	
	return 0;
}
