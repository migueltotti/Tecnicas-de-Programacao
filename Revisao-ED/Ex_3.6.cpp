#include <iostream>

using namespace std;

float Calculo(float num){
	float ret=0;
	
	if(num > 0){

		ret += (num*num+1)/(num+3) + Calculo(num-1); 
		
	}
	
	return ret;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	cout<<"Calculo do numero 4: "<<Calculo(4)<<endl;

	return 0;
}
