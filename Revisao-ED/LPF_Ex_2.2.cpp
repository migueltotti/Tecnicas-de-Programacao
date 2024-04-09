#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Parenteses{
	string Valor; 
	Parenteses *Prox;
};

// Pilha encadeada
struct Pilha{
	Parenteses *Topo;
	int Total;
};

// Fila encadeada
struct Fila{ //Header/Cabe?alho
	Parenteses *Inicio;
	Parenteses *Fim;
	int Total;
};

void Ini_Pilha(Pilha *P){
	P->Topo = NULL;
	P->Total = 0;
}

void Ini_Fila(Fila *F){
	F->Inicio = NULL;
	F->Fim = NULL;
	F->Total = 0;
}

int Pilha_Vazia(Pilha *P){
	
	return (P->Topo == NULL);		
}

int Fila_Vazia(Fila *F){
	
	return (F->Inicio == NULL);		
}

Parenteses *Criar_Item(string Valor){
	Parenteses *Item;

	Item = new Parenteses;
	if (Item != NULL){
		Item->Valor = Valor;
		Item->Prox = NULL;
	}
	
	return Item;
}

void Push(Pilha *P, string Valor){
	Parenteses* Item;
	
	Item = Criar_Item(Valor);
	if (Item != NULL){
		Item->Prox = P->Topo;
		P->Topo = Item;
				
		P->Total++;
	}		
}

void Enqueue(Fila *F, string Valor){
	Parenteses* Item;
	
	Item = Criar_Item(Valor);
	if (Item != NULL){
	
		if(Fila_Vazia(F)){ //Fila F? vazia
			F->Inicio = Item;			
		}	
		else{			
			F->Fim->Prox = Item;	
		}	
			
		F->Fim = Item;			
		F->Total++;
	}	
}

Parenteses* Pop(Pilha *P){
	Parenteses* Ret;
	
	if (Pilha_Vazia(P)){
		Ret = NULL; //Lista vazia
	}
	else{		
		Ret = P->Topo;		
		P->Topo = P->Topo->Prox;
		P->Total--;
	}
	
	return Ret;
}

Parenteses* Dequeue(Fila *F){
	Parenteses* Ret;
	
	if (Fila_Vazia(F)){
		Ret = NULL; //Lista vazia
	}
	else{		
		Ret = F->Inicio;		

		F->Inicio = F->Inicio->Prox;
		F->Total--;
		
		if (Fila_Vazia(F)){
			F->Fim = F->Inicio;
		}				
	}
	
	return Ret;
}

void Imprime_Pilha(Pilha *P){
	Parenteses* Item;
	
	for(Item=P->Topo;Item!=NULL;Item = Item->Prox){
		cout << Item->Valor << endl;
	}	
}

void Imprime_Fila(Fila *F){
	Parenteses* Item;
	
	for(Item=F->Inicio;Item!=NULL;Item = Item->Prox){
		cout << Item->Valor << " ";
	}	
	
	cout<<endl;
}


string TratamentoDeParenteses(Fila *F, Pilha *P){
	string ret = "Certo";
	Parenteses *Item;
	
	while(F->Inicio != NULL){
		Item = Dequeue(F);
		
		if(P->Topo == NULL && Item->Valor == "("){
			Push(P, Item->Valor);
		}
		else{
			if(P->Topo == NULL && Item->Valor == ")"){
				ret = "Errado!";
			}
			else{
				if(Item->Valor == "("){
					Push(P, Item->Valor);
				}
				else{
					Pop(P);
				}
			}
		}
	}
	
	if(P->Total > 0){
		ret = "Errado!";
	}
	
	return ret;
}


Fila F;
Pilha P;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	Ini_Fila(&F);
	Ini_Pilha(&P);
	Enqueue(&F, ")");
	Enqueue(&F, "(");
	Enqueue(&F, ")");
	Enqueue(&F, ")");
	Enqueue(&F, "(");
	//Enqueue(&F, ")");
	//Enqueue(&F, "(");
	
	Imprime_Fila(&F);
	
	system("pause");
	cout<<"\nExpressao Correta? \n:"<<TratamentoDeParenteses(&F, &P);
			
	return 0;
} 
