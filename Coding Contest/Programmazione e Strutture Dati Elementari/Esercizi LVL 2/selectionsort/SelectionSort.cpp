#include<fstream>
#include<iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int selectionSort(int *, int);
int minpos(int *, int, int);
void swap(int *, int, int);
void stampa(int *, int);
 
int main(){

    int n;

    for (int task = 0; task < 100; task++)
    {
        in >> n;

        int v[n];

       for (int i = 0; i < n; i++)
       {
           in >> v[i];
       }
       
       out << selectionSort(v, n) << endl;

        
    }
    
    in.close();
    out.close();
}

int selectionSort(int *v, int n){
    int pos = -1;
    int distance = 0;

    for (int i = 0; i < n; i++)
    {
       pos = minpos(v, n , i);
       distance += (pos - i);
       swap(v, i, pos);
    }
    
   return distance; 
}


int minpos(int *v, int n, int j){
    int min = j;

   for (int i = j; i < n; i++)
   {
       if (v[i] < v[min])
       {
           min = i;
       }
   }

   return min;
}

void swap(int *v, int i, int j){

    int t = 0;

    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void stampa(int *v, int n){

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    
}