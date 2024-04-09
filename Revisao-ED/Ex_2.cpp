#include <iostream>

using namespace std;

void converteHora(int total_segundos, int *hora, int *min, int *seg){
	int cont;
	
	for(cont = 0; cont < total_segundos; cont++){
		
		*seg+= 1;
		
		if(*seg == 60){
			*min += 1;
			*seg = 0;
		}
		
		if(*min == 60){
			*hora += 1;
			*min = 0;
		}

	}
	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int total_segundos = 3720, hora=0, min=0, seg=0;
	
	cout<<"Total Segundos: "<< total_segundos <<endl;
	
	converteHora(total_segundos, &hora, &min, &seg);
	
	cout<<hora<<":"<<min<<":"<<seg<<endl;

	return 0;
}
