#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct Alunos{
	char Matricula[9];
	float Nota;
};

void swap(Alunos *Lista, int a, int b){
	Alunos aux;
	
	aux = Lista[a];
	Lista[a] = Lista[b];
	Lista[b] = aux;
}

void SelectionSort(Alunos *Lista, int tam, char Tipo){
	int menor = 0, i, j; 
	
	if(Tipo == 'N'){
		for(i = 0; i < tam; i++){
			menor = i;
			for(j = i+1; j < tam; j++){
				
				if(Lista[j].Nota < Lista[menor].Nota){
					menor = j;
				}
			}
			
			swap(Lista, menor, i);
		}
	}
	else{
		for(i = 0; i < tam; i++){
			menor = i;
			for(j = i+1; j < tam; j++){
				
				if(strcmp(Lista[menor].Matricula, Lista[j].Matricula) > 0){
					menor = j;
				}
			}
			
			swap(Lista, menor, i);
		}
	}
}


Alunos Lista0[40], ListaNota[40], ListaMatricula[40];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int N = 0;
	
	while(cin>>N){
		
		for(int i = 0; i < N; i++){
			
			cin>>Lista0[i].Matricula>>Lista0[i].Nota;
			
		}
		
		SelectionSort(Lista0, N, 'N');
		
		cout<<"Ordem notas:\n";
		for(int i = 0; i < N; i++){
			
			cout<<Lista0[i].Matricula<<" "<<fixed<<setprecision(1)<<Lista0[i].Nota<<"\n";
			//printf("%c %0.1f\n", Lista0[i].Matricula, Lista0[i].Nota);
		}
		
		SelectionSort(Lista0, N, 'M');
		
		cout<<"Ordem matricula:\n";
		for(int i = 0; i < N; i++){
			
			cout<<Lista0[i].Matricula<<" "<<fixed<<setprecision(1)<<Lista0[i].Nota<<"\n";
			//printf("%c %0.1f\n", Lista0[i].Matricula, Lista0[i].Nota);
		}
		

	}
	
	return 0;
}
