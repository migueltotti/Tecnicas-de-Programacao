#include <iostream>

using namespace std;

int Multiplica(int a, int b){
	int ret;
	
	if(a > 0){
		
		ret = b + Multiplica(a - 1, b);
	}
	else{
		ret = 0;
	}
	
	return ret;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n1 = 6, n2 = 4;
	
	cout<<"6x4 = "<< Multiplica(n1, n2);

	return 0;
}
