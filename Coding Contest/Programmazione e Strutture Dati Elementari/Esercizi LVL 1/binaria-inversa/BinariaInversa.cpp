#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main(){

    string s;

    for (int task = 0; task < 100; task++)
    {
        int counter = 0;
        int v[10000];

        while(in.peek() != '\n' && !in.eof())
        {
            in >> s; 
            int somma = 0;

            for (int i = 0; i < 8; i++)
            {
                if(s.at(i) == '1')
                    somma += pow(2, 7-i);
            }

            v[counter++] = somma;
        }

        getline(in, s);

        out << counter << " ";

        for (int i = 0; i < counter; i++)
            out << v[i] << " ";

       out << endl;
    }
    in.close();
    out.close();
}