#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main(){
    int number = 0;

    for (int task = 0; task < 100; task++)
    {
        in >> number;

        for (int i = 0; i < number; i++)
        {
            int n;
            in >> n;

            int power = 0;

            int v[8];

            for (int i = 0; i < 8; i++)
            {
                v[i] = 0;
            }

            while (n >= pow(2, power))
                power++; 


            int j = 7;
            while(power > 0)
            {
               v[j--] = n%2;
               n /= 2;
               power --;
            }
            
            for (int i = 0; i < 8; i++)
            {
                out << v[i];
            }

            out << " ";
        }
        out << endl;
    }
    
    in.close();
    out.close();
}