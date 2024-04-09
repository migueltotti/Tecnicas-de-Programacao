#include <iostream>

using namespace std;

void TrocarNumeros(int *a, int *b){
	int copia;
	
	copia = *a;
	*a = *b;
	*b = copia;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int a = 5, b = 6;
	
	cout<<"Valor de a: "<< a <<endl; 
	cout<<"Valor de b: "<< b <<endl<<endl;
	
	TrocarNumeros(&a, &b);
	
	cout<<"Valor de a trocado: "<< a <<endl; 
	cout<<"Valor de b trocado: "<< b <<endl;
	
	return 0;
}
