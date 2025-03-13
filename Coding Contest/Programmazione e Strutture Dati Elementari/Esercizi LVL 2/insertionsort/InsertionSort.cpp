#include<fstream>
#include<iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int insertionSort(int *, int);
void swap(int *, int, int);

int main(){

    for (int task = 0; task < 100; task++)
    {
        int n;

        in >> n;

        int v[n];

        for (int i = 0; i < n; i++)
        {
            in >> v[i];
        }

        out << insertionSort(v, n) << endl;
        
    }
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
