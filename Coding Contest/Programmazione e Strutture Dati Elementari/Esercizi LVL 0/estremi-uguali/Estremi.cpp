#include<iostream>
#include<fstream>
#include<string>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    int n = 0;
    string s;

   for(int task = 0;task<100;task++){

       int counter = 0;

       for(int i = 0;i<3;i++){
           in >> n;
           in >> s;

           if(s.at(0) == s.at(n-1))
               counter++;
           
       }

       out << counter << endl;
    }

   in.close();
   out.close();
}
