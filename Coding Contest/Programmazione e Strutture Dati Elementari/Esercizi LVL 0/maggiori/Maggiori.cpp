#include<fstream>
#include<vector>

using namespace std;

    ifstream in("input.txt");
    ofstream out("output.txt");

int main(){

    int n, x, number, counter;

    for(int task = 0;task<100;task++){
        in >> n;
        in >> x;
        number = 0;
        vector<int> v;
        counter = 0;

        for(int i = 0;i<n;i++){
            in >> number;

            if(number > x){
                v.push_back(number);
                counter++;
            }
        }

            out << counter  << " ";

        for (auto i = v.begin(); i != v.end(); ++i)
            out << *i << " "; 
        
        out << endl;
    }
}
