#include <iostream>

using namespace std;

void Binario(int num){
//	3 / 2 - 1 : 1
//	1 / 2 - 0 : 1

// 4 / 2 - 2 : 0
// 2 / 2 - 1 : 0
// 1 /2 - 0 : 1

	if(num != 0){ // 4 - 2 - 0 (NAO PODE ENTRAR)
		
		int ret;
		
		ret = num%2; // 0 - 0 - 1

		Binario(num/2); // 2 - 1 - 0
	
		cout<< ret; // 0 - 0 - 1
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	// 0 - 1 - 10 - 11
	int num = 7;
	
	Binario(num);

	return 0;
}
