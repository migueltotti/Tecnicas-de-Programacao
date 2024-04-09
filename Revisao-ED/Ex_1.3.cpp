#include <iostream>

using namespace std;

void PerimetroArea(float *r, float *p, float *a){
	
	*p = 2 * 3.14 * *r;
	*a = 3.14 * *r * *r;
	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float raio = 5, perimetro, area;
	
	PerimetroArea(&raio, &perimetro, &area);
	
	cout<<"Perimetro de raio "<< raio << ": "<< perimetro <<endl;
	cout<<"Area de raio "<< raio << ": "<< area <<endl;

	return 0;
}
