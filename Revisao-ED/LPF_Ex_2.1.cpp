#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Item{
	int Codigo;
	char Nome[20];
	float Preco;
	Item *Prox;
};

struct Pilha{
	Item *Topo;
	int Tamanho;
};

void Ini_Pilha(Pilha *P){ //Cria uma lista vazia
	P->Topo = NULL;
	P->Tamanho = 0;	
}

int Pilha_Vazia(Pilha *P){ //Verifica se a pilha est? vazia (1 - Vazia, 0 - Tem mais de 1 elemento)
	int Ret;

	if (P->Topo == NULL){
		Ret = 1;
	}
	else{
		Ret = 0;
	}
	
	return Ret;
}

int Tamanho(Pilha *P){
	
	return P->Tamanho;
}

Item* Cria_Item(int Codigo, char* Nome, float Preco){
	Item *Elemento;

	Elemento = (Item *) malloc(sizeof(Item)); //Problema com o campo string
	if (Elemento != NULL) {
		Elemento->Codigo = Codigo;
		strcpy(Elemento->Nome, Nome);
		Elemento->Preco = Preco;
		Elemento->Prox = NULL;				
	}

	return Elemento;	
}

void Empilha(Pilha *P, int Codigo, char* Nome, float Preco){	
	Item *Elemento;
	
	Elemento = 	Cria_Item(Codigo, Nome, Preco);
	if (Elemento != NULL){
		Elemento->Prox = P->Topo;
		P->Topo = Elemento;	
		P->Tamanho++;
	}
	else{
		cout << "N?o h? mais espa?o na pilha!!" << endl;
	}
} 


Item * Desempilha(Pilha *P){		

	Item *Ret = NULL;

	if (Pilha_Vazia(P) == 0){ //H? alunos na Turma					
		Ret = P->Topo;
		P->Topo = P->Topo->Prox;

		P->Tamanho--;	//Atualiza o topo				
	}
	else{
		cout << "Pilha vazia!!" << endl;
	}
	
	return Ret;
} 

void Imprime_Pilha(Pilha *P){
	Item* Cont;	

	//system("cls");

	cout<<"\tCODIGO\t"<<"\tNOME\t\t"<<"\tPRECO\t\n";	

	for (Cont=P->Topo; Cont!=NULL; Cont=Cont->Prox){
		cout<<"\t"<<Cont->Codigo<<"\t";
		cout<<"\t"<<Cont->Nome<<"\t\t";
		cout<<"\t"<<Cont->Preco<<"\n";
	}	
	
	cout<<endl;
}

void RemoveChave(Pilha *P, int Codigo){
	Pilha Aux;
	Item *ItemAux;
	
	Ini_Pilha(&Aux);
	
	while(P->Topo->Codigo != Codigo){
		ItemAux = Desempilha(P);
		Empilha(&Aux, ItemAux->Codigo, ItemAux->Nome, ItemAux->Preco);
		
		free(ItemAux);
	}
	
	if(P->Topo != NULL){ //  Encontrou o Item a ser removido
		ItemAux = Desempilha(P);
		free(ItemAux);
		
		while(Aux.Topo != NULL){
			ItemAux = Desempilha(&Aux);
			Empilha(P, ItemAux->Codigo, ItemAux->Nome, ItemAux->Preco);
		
			free(ItemAux);
		}
	}
}

void RemoveChaveNic(Pilha *P, int Codigo){
	Item *ItemAux;

	if(P->Topo->Codigo != Codigo){
		ItemAux = Desempilha(P);
		
		RemoveChaveNic(P, Codigo);
		// utiliza backtracking para substituir a pilha aux que seria utilizada para armazenar os numeros que sairiam da pilha principal
		// os numeros ficam guardados na memoria da propria funcao e só dpois que o numero certo for encontrado a recursao acaba,
		// dai os numeros que estao armazenados na memoria da funcao sao utilizados novamente para empilhar ate acabar as funcoes
		
		Empilha(P, ItemAux->Codigo, ItemAux->Nome, ItemAux->Preco);
		
		free(ItemAux);
	}
	else{
		ItemAux = Desempilha(P);
		free(ItemAux);
	}

}


Pilha P;
Item *I;
char Nome[20];
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	Ini_Pilha(&P);
	
	strcpy(Nome, "1");
	Empilha(&P, 1, Nome, 1); //Push
	strcpy(Nome, "5");
	Empilha(&P, 5, Nome, 5);
	strcpy(Nome, "9");
	Empilha(&P, 9, Nome, 9);
	strcpy(Nome, "3");
	Empilha(&P, 3, Nome, 3);  	
	strcpy(Nome, "2");
	Empilha(&P, 2, Nome, 2);
	Imprime_Pilha(&P);
	//system("pause");	

	
	RemoveChave(&P, 9);
	
	Imprime_Pilha(&P);
	//system("pause");	

		
	return 0;
}
