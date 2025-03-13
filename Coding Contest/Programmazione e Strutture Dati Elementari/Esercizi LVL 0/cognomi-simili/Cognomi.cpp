#include<fstream>
#include<iostream>
#include<string>


using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    int n = 0;

    for(int task = 0;task<100;task++){

        in >> n;

        string a;
        string b;
        string c;

        in >> a>> b >> c;

        bool flag = false;

        if(a.substr(0,n) == b.substr(0,n) && a.substr(0,n+1) != b.substr(0,n+1)){
            out << a << " " << b;

            flag = true;

            if(a.substr(0,n) == c.substr(0, n) && a.substr(0, n+1) != c.substr(0, n+1) && b.substr(0, n-1) == c.substr(0, n-1) && b.substr(0, n+1) != c.substr(0, n+1)){
                out << " " << c;
            }
        }

        if(a.substr(0, n) == c.substr(0,n) && a.substr(0, n+1) != c.substr(0, n+1) && !flag){
            out << a << " " << c;
        }

        if(b.substr(0, n) == c.substr(0, n) && b.substr(0, n+1)!= c.substr(0, n+1) && !flag){
            out << b << " " << c;
        }

        out << endl;
    }

    in.close();
    out.close();
}    
    