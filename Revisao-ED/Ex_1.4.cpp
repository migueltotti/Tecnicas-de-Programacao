#include <iostream>
#include <math.h>

using namespace std;

void CalcEq2Grau(int a, int b, int c, float *x1, float *x2){
	
	*x1 = ((-b) + sqrt(b*b - 4 * a * c))/(2*a);
	*x2 = ((-b) - sqrt(b*b - 4 * a * c))/(2*a);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int a = 2, b = -3, c = -5;
	float x1, x2;

	CalcEq2Grau(a, b, c, &x1, &x2);

	cout<<"x1 = " << x1 <<endl;
	cout<<"x2 = " << x2;
	return 0;
}
