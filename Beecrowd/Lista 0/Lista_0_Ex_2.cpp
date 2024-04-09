#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int D, VF, VG;
	double DG, TF, TG;
	
	while(cin>>D && cin>>VF && cin>>VG){
		
		DG = sqrt((double)(D*D) + (144.0));
		
		TF = 12.0/VF;
		TG = DG/VG;
		
		if(TG <= TF){
			cout<<"S"<<endl;
		}
		else{
			cout<<"N"<<endl;
		}
	}
	
	return 0;
}
