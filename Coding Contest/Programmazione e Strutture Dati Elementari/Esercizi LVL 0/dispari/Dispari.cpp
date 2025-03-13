#include<fstream>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    int n = 0;
    int number = 0;

    for(int task = 0;task<100;task++){

        in >> n;

        for(int i = 0;i<n;i++){

            in >> number;

            if(number%2 !=0)
                out << number << " ";
        }

        out << endl;
    }

    in.close();
    out.close();
}
