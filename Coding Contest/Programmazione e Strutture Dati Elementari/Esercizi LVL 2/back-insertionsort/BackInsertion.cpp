#include<fstream>
#include<iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int insertionSort(int *, int);
int backInsertionSort(int *, int);
void stampa(int *v, int);

int main(){

    int n;

    for (int task = 0; task < 100; task++)
    {
        in >> n;
        int v[n];
        int g[n];

        for (int i = 0; i < n; i++)
        {
            in >> v[i];

            g[i] = v[i];
        }

        out << insertionSort(v, n) << " "; 

        out << backInsertionSort(g, n) << endl;
        stampa(g, n);
    }
    
    in.close();
    out.close();
}


int insertionSort(int *v, int n){
   int counter = 0;

   for (int i = 1; i < n; i++)
   {
       int key = v[i];
       int j = i-1;

       while(key < v[j] && j >= 0){
           v[j+1] = v[j];
           v[j] = key;
           j--;
           counter++;
       }
   }
    return counter;
}

int backInsertionSort(int *g, int n){
   int counter = 0;

   for (int i = n-2; i >=0; i--)
   {
       int key = g[i];
       int j = i+1;

       while(key > g[j] && j <= n-1){
           g[j-1] = g[j];
           g[j] = key;
           j++;
           counter++;
       }
   }
    return counter;
}


void stampa(int *v, int n){

   for (int i = 0; i < n; i++)
   {
       cout << v[i] << " ";
   }
    
    cout << endl;
}