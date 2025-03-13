#include<fstream>
#include<string>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    string s;

    for(int task = 0;task<100;task++){

        in >> s;

        out << s+s << endl;
    }

    in.close();
    out.close();

}
