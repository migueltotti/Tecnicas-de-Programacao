#include <iostream>

using namespace std;

int Soma(int a, int b){
	int ret;
	
	if(a > 0){
		ret = 1 + Soma(a - 1, b);
	}
	else{
		if(b > 0){
			ret = 1 + Soma(a, b - 1);
		}
		else{
			ret = 0;
		}
	}
	
	return ret;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n1 = 3, n2 = 4;
	
	cout<<"3+4 = "<< Soma(n1, n2);

	return 0;
}
