/*
Rachele ha adottato un gattino. Non sa ancora se si tratti di un maschio o di una femmina ma vuole ugualmente cominciare a pensare al nome da dargli.
Tuttavia è molto esigente in fatto di nomi e dovrà tenere in considerazione alcune restrizioni.
Nello specifico lei vorrebbe trovare un nome che inizi o finisca con una determinata lettera, ma che allo stesso tempo non inizi ne finisca con un'altra determinata lettera.

Specifiche
Si fornisca un programma che dati in input tre nomi di lunghezza variabile, sia in grado di individuare tra questi quelli che iniziano o finiscono
con un determinato carattere A ma che, allo stesso tempo, non inizino ne finiscano con un altro determinato carattere B.

if( (string[0]!=A || string[string.length()]!=A) && (string[0]!=B || string[string.length()]!=B) ){
    out<<quello che è
}

Dati in input
Il file di input contiene 100 task, uno per ogni riga. Ogni riga contiene 8 valori. I primi due valori sono i due caratteri A e B.
seguono tre coppie di valori, ciascuna delle quali è formata da un valore intero K ed un none di lunghezza K. Tutti gli elementi forniti in input sono separati da uno spazio.

Dati in output
Il file di output contiene 100 righe di testo, una per ogni task contenuto nel file di input. Ogni riga contiene da uno a tre valori.
Nello specifico dovranno essere riportati tutti i nomi, tra quelli forniti in input, che iniziano o finiscono con la lettera A, ma che non iniziano
e non finiscono con la lettera B. I nomi dovranno essere riportati nello stesso ordine in cui appaiono in input.

Note
La lunghezza dei nomi forniti in input è sempre un valore compreso tra 3 e 9 (estremi inclusi)

Esempio
Il seguente esempio presenta un file di input, contenente 3 task, ed il corrispondente file di output.

input.txt:
e a 6 alcide 6 alvise 8 salomone
a i 5 isaia 8 albenzio 5 akira
i o 6 gianni 4 imer 9 pierluigi

output.txt:
salomone
albenzio akira
gianni imer pierluigi
*/
#include <iostream>
#include <fstream>
using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");
string disA, disB, line1, line2, line3;
int a,b,c;

int main(){

    for(int task=0; task<100; task++){

        in>>disA;
        in>>disB;
        in>>a; //non serve
        in>>line1;
        in>>b; //non serve
        in>>line2;
        in>>c; //non serve
        in>>line3;

        //line1
        if( (line1[0]==disA[0] || line1[a-1]==disA[0]) && (line1[0]!=disB[0] && line1[a-1]!=disB[0]) ){
            out<<line1<<"";
        }

        //line2
        if( (line2[0]==disA[0] || line2[b-1]==disA[0]) && (line2[0]!=disB[0] && line2[b-1]!=disB[0]) ){
            out<<line2<<" ";
        }

        //line3
        if( (line3[0]==disA[0] || line3[c-1]==disA[0]) && (line3[0]!=disB[0] && line3[c-1]!=disB[0]) ){
            out<<line3<<" ";
        }

        out<<endl;

        /*
        e a 6 alcide 6 alvise 8 salomone
        a i 5 isaia 8 albenzio 5 akira
        i o 6 gianni 4 imer 9 pierluigi
        */

    }




    return 0;
}