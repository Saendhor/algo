/*
E' convenzione che i nomi propri vadano sempre scritti con la prima lettera in forma maiuscola.
Se, all'interno di un testo, è presente un nome proprio la cui prima lettera è trascritta in minuscolo, possiamo parlare di un errore di tipo concettuale.

Specifiche
Si fornisca un programma che dati in input tre nomi propri, maschili o femminili, trascritti con caratteri minuscoli,
 li ri-trascriva in output in modo che la prima lettera di ciascun nome sia in forma maiuscola.

Dati in input
Il file di input contiene 100 task, uno per ogni riga. Ogni riga contiene tre coppie di valori.
Ciascuna coppia di valori è formata da un valore intero K ed un nome proprio di lunghezza K.
Tutti gli elementi forniti in input sono separati da uno spazio. I nomi propri sono sempre trascritti con tutti i caratteri minuscoli.

Dati in output
Il file di output contiene 100 righe di testo, una per ogni task contenuto nel file di input.
Ogni riga contiene i tre nomi propri forniti in input, nel medesimo ordine, con la prima lettera trascritta in maiuscolo.

Note
La lunghezza delle parole fornite in input è sempre un valore compreso tra 3 e 9 (estremi inclusi).
Tutti i nomi propri forniti in input iniziano con una vocale.

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
6 ottone 7 agrippa 6 emidio
7 arcadio 7 eugenio 5 elias
7 arnaldo 6 amleto 4 orio

output.txt:
Ottone Agrippa Emidio
Arcadio eugenio Elias
Arnaldo Amleto Orio


DALLE MIE RICERCHE
nella tabella ascii i caratteri minuscoli distano di esattamente 32 caratteri

a=97  -> A=65   DELTA=32
*/
#include <iostream>
#include <cstring>
#include<fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
string line1, line2, line3, line4, line5, line6;
int a,b,c;
int main(){

    for(int i=0;i<100;i++){

        in>>line1;
        in>>line2;
        in>>line3;
        in>>line4;
        in>>line5;
        in>>line6;

        a=int(line2[0]);
        a-=32;
        line2[0]=char(a);

        b=int(line4[0]);
        b-=32;
        line4[0]=char(b);

        c=int(line6[0]);
        c-=32;
        line6[0]=char(c);

        out<<line2<<" ";
        out<<line4<<" ";
        out<<line6<<" ";
        out<<"\n";

    }



    return 0;
}

