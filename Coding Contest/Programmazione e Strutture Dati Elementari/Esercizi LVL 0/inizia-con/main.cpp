#include <iostream>
#include <cstring>
#include<fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
string startLine, line1, line2, line3, line4, line5, line6;
int a,b,c;
int main(){

    for(int i=0;i<100;i++){

        in>>startLine;
        in>>line1;
        in>>line2;
        in>>line3;
        in>>line4;
        in>>line5;
        in>>line6;

        //2 4 6
        if(line2[0]==startLine[0]){
            out<<line2<<" ";
        }

        if(line4[0]==startLine[0]){
            out<<line4<<" ";
        }

        if(line6[0]==startLine[0]){
            out<<line6<<" ";
        }

        out<<endl;

    }



    return 0;
}