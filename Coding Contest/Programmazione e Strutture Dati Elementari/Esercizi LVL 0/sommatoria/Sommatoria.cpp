#include<fstream>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){
    int n = 0;
    double temp = 0;

    for(int task = 0;task<100;task++){
        in >> n;
        double somma = 0;
        

        for(int i = 0;i<n;i++){
            in >> temp;
            somma += temp;
        }

        out << somma << endl;
    }

    in.close();
    out.close();
}
