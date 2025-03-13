#include<fstream>
#include<string>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    string s;
    
    for(int task = 0;task<100;task++){
    
        int n = 0, min = 10001;

        in >> s;

        while(s != "STOP"){

            n = stoi(s);

            if(n < min)
                 min = n;

            in >> s;
        }

        out << min << endl;
    }

    in.close();
    out.close();
}
