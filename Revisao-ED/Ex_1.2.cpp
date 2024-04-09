#include <iostream>

using namespace std;

void IncrementoDecremento(int *a, int *b){
	
	*a = *a - 1;
	*b = *b + 1;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int a = 5, b = 6;
	
	cout<<"Valor de a: "<< a <<endl; 
	cout<<"Valor de b: "<< b <<endl<<endl;
	
	IncrementoDecremento(&a, &b);
	
	cout<<"Depois da Funcao: "<<endl;
	cout<<"Valor de a: "<< a <<endl; 
	cout<<"Valor de b: "<< b <<endl;

	return 0;
}
