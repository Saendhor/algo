#include<fstream>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    int n;

    long v[60] = {1, 1};

    for(int i = 2;i<60;i++)
        v[i] = v[i-1] + v[i-2];


    for(int task = 0;task<100;task++){

        in >> n;

        out << v[n-1] << endl;
    }

    in.close();
    out.close();
}
