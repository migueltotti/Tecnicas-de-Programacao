#include <iostream>

using namespace std;

#define MAX 100000

int Lista[MAX];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int n = 0, cont;
	
	while(n < 1 || n > 100000){
		cin>>n;
	}
	
	for(int i = 0; i < n; i++){
		cin>>Lista[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				
				if(Lista[i] > Lista[j] && Lista[i] > Lista[k] && Lista[j] > Lista[k]){
					cont++;
				}
				
			}
		}
	}
	
	cout<<cont<<endl;
	
	return 0;
}
