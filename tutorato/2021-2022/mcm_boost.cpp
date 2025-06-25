#include <iostream>
#include <limits.h>

//I TIPI

typedef unsigned short int Natural16;
typedef unsigned long int Natural32;
typedef unsigned long long int Natural64;

using namespace std;

//Struttura dati che rappresenta una matrice triangolare
template <typename NType,typename NNType,typename TType> class TriangularMatrix{
private:
	//Dimensione della matrice
	NType size;
	//Puntatore alla matrice
	TType * matrix = nullptr;
public:
	//Costruttore
	TriangularMatrix(const NType size){
		this->size = size;
		matrix = new TType [((NNType) size * ((NNType)size + 1))/2];
	}
	//Accedere all'elemento di indice i,j
	inline TType get(const NType i, const NType j){
		return matrix[(NNType) i * (NNType)size + (NNType) j - ( ((NNType) i * ((NNType) i + 1)) / 2 )];
	}
	//Settare l'elemento di indice i,j
	inline TriangularMatrix<NType,NNType,TType>* set(const NType i, const NType j, const TType value){
		matrix[(NNType) i * (NNType)size + (NNType) j - ( ((NNType) i * ((NNType) i + 1)) / 2 )] = value;
		return this;
	}
	//Incrementare l'elemento di indice i,j
	inline TriangularMatrix<NType,NNType,TType>* add(const NType i, const NType j, const TType value){
		matrix[(NNType) i * (NNType)size + (NNType) j - ( ((NNType) i * ((NNType) i + 1)) / 2 )] += value;
		return this;
	}
};

//Funzione mcm
//Effettua matrix chain multiply su un vettore p facente riferimento a una lista di n matrici
//NType tipo della lunghezza di p che si chiama n - per noi 16 bit
//Ptype è il tipo degli elmenti del vettore p - per noi 16 bit
//TType è il tipo degli elementi della matrice triangolare superiore a - per noi 64 bit
//NNType è il tipo del quadrato di n - per noi 32 bit
template <typename NType, typename PType, typename NNType, typename TType>
TriangularMatrix<NType, NNType, TType>* mcm(const PType* p, const NType n){
	//Creiamo la matrice triangolare superiore come un vettore con n*(n+1)/2 elementi
	TriangularMatrix<NType, NNType, TType>* a = new TriangularMatrix<NType, NNType, TType>(n);
	//Inizializziamo la diagonale principale con 0
	for (NType i = 0; i<n; i++){
		a->set(i,i,0);
	}
	//Applichiamo l'algoritmo procedendo diagonale per diagonale
	for (NType diagonale = 1; diagonale<n; diagonale++){
		//Nell'applicarlo a una diagonale scorriamo tutte le righe aventi elementi in tale diagonale in modo tale da riempire l'elemento a[riga][riga+diagonale]
		for(NType riga = 0; riga+diagonale<n; riga++){
			//Poniamo l'elemento a[riga][riga+diagonale] a infinito
			a->set(riga,riga+diagonale,ULLONG_MAX);
			//Cerchiamo il minimo
			for(NType k = riga; k< riga+diagonale; k++){
				//Poniamo somma = a[riga][k] + a[k+1][riga+diagonale] + p[riga] * p[k+1] * p[riga+diagonale+1]
				TType somma = a->get(riga,k);
				somma += a->get(k+1,riga + diagonale);
				somma += (TType)p[riga] * (TType)p[k+1] * (TType) p[riga+diagonale+1];
				//Se somma è minore della precedente stima del minimo lo salviamo come minimo
				if(somma < a->get(riga,riga+diagonale)){
					a->set(riga,riga+diagonale,somma);
				}
			}
		}
	}
	return a;
}

//MAIN

int main(){
	/*
	Natural16 n = 6;
	Natural16 p[n+1] = {2,2,2,2,2,2,2};
	*/
	/*
	Natural16 n = 7;
	Natural16 p[n+1] = {9,2,8,7,2,7,4,10};
	*/
	Natural16 n = 5;
	Natural16 p[n+1];
	for(Natural16 i = 0; i<=n; i++){
		p[i] = USHRT_MAX;
	}
	TriangularMatrix<Natural16, Natural32, Natural64>* a = mcm<Natural16, Natural16, Natural32, Natural64>(p,n);
	for(Natural16 i = 0; i<n; i++){
		for(Natural16 j = 0; j<n; j++){
			if(j<i){
				cout<<"°\t";
			}
			else{
				cout<<a->get(i,j)<<"\t";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Il numero di minimo di operazioni per moltiplicare le matrici e' : "<<a->get(0,n-1)<<endl;
	return 0;
}
