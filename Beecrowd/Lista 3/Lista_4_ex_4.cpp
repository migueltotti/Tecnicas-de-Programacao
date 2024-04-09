/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

#define MOD 1000000007
#define MAX 100000

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main()
{
    long int N, K, soma = 0;
    int arr[MAX];
    
    while(cin>>N && cin>>K){
        
        for(long int i = 0; i < N; i++){
            cin>>arr[i];
        }
        
        qsort(arr,N,sizeof(int),compare);
        
        for(int i = N-1; i > N - K - 1; i--){
            soma = (soma+arr[i])%MOD;
        }
        
        cout<<soma%MOD<<"\n";
    
        soma = 0;
    }

    return 0;
}

