#include<fstream>
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");
    
    
double z,ris;
int n;   
    
    for(int task=0;task<100;task++){
    	
    	in >> n;
    	
    	for(int i=0;i<n;i++){
    		in >> z;
    		
    		ris = z-floor(z);
    		
    		out << ris << " ";
    		
		}
		
		out << endl;
}
}
    
