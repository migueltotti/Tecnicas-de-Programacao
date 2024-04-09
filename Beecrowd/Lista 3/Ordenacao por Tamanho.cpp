#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX 50

using namespace std;

int Gravar_String(char STR[], string vetor[], int tam_str){
	string palavra = "";
	int j = 0;
	
	for(int i = 0; i <= tam_str; i++){
		
		if(palavra == "" && STR[i] != ' '){
			palavra = STR[i];
		}
		else{
			if(STR[i] != ' ' && i != tam_str){
				palavra += STR[i];
			}
			else{
				if(STR[i] == ' ' || STR[i] == '\0' || i == tam_str){
					vetor[j] = palavra;
					j++;
					palavra = "";
				}
			}
		}
				
	}
	
	return j;
}

void Swap(string *L, int PosA, int PosB){
    string Aux;
    
    Aux = L[PosA];
    L[PosA] = L[PosB];
    L[PosB] = Aux;    
}

void InsertionSort(string *L, int Tam){
    int Cont1, Cont2;
    
    for(Cont1=1;Cont1<Tam;Cont1++){
        Cont2 = Cont1; //Pr?ximo item da lista n?o ordenada
        
        //Move o pr?ximo item da lista n?o ordenada para
        //a posi??o correta na lista ordenada
        while (Cont2 > 0 && L[Cont2].length() > L[Cont2-1].length() ) {        
            //Move o valor encontrado pra lista ordenada
            Swap(L, Cont2, Cont2-1);
            
            Cont2--;    
        } 		           
    }                
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n, tam = 0;
	string vetor[50];
	char STR[2501];
	
	cin>>n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		//getline(cin, STR);
		cin.getline(STR, 2501);
		
		//cout<<STR;
		//cout<<strlen(STR)<<endl;
		//cout<<STR[3]<<endl;
		tam = Gravar_String(STR, vetor, strlen(STR));
		
		//SelectionSort(vetor, tam);
		InsertionSort(vetor, tam);
		
		for(int i = 0; i < tam; i++){
			if(i < tam-1)
				cout<<vetor[i]<<" ";
			else
				cout<<vetor[i]<<endl;
				
			//vetor[i] = "";
		}
		//cout<<endl;
	}
	
	return 0;
}
