#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>

using namespace std;


/**
 * Classe Heap : implementa un heap.
 */
template<class Key> class Heap{
protected:
	/**
	 * Key v : vettore contenente le chiavi.
	 */
	Key* v;
	/**
	 * Int n: dimensione massima dell'heap.
	 */
	int n;
	/**
	 * Int size : dimensione dell'heap.
	 */
	int size;
	/**
	 * Int left() : restituisce l'indice del figlio sinistro di un nodo.
	 * Int i : indice del nodo.
	 */
	inline int left(int i){return i << 1;}
	/**
	 * Int right() : restituisce l'indice del figlio destro di un nodo.
	 * Int i : indice del nodo.
	 */
	inline int right(int i){return sibling(left(i));}
	/**
	 * Int parent() : restituisce l'indice del genitore di un nodo.
	 * Int i : indice del nodo.
	 */
	inline int parent(int i){return i >> 1;}
	/**
	 * Bool isRoot() : controlla se un nodo è radice.
	 * Int i : indice del nodo.
	 */
	inline bool isRoot(int i){return i <= 1;}
	/**
	 * Bool isEmpty() : controlla se l'heap è vuoto.
	 */
	inline bool isEmpty(){return size <= 0;};
	/**
	 * Bool isIndex() : controlla se un nodo non supera i limiti dell'heap.
	 * Int i : indice del nodo.
	 */
	inline bool isIndex(int i){return i<= size;}
	/**
	 * Int sibling() : restituisce l'indice del fratello di un nodo.
	 * Int i : indice del nodo.
	 */
	inline int sibling(int i){return i | 1;}
	inline void swap(int i, int j){
		Key k = v[i];
		v[i] = v[j];
		v[j] = k;
	}
	/**
	 * Bool isLower : relazione di ordinamento tra due nodi.
	 * Int i : indice del primo nodo.
	 * Int j : indice del secondo nodo.
	 */
	virtual bool isLower(int i,int j){cout<<"Warning!"<<endl;return true;};
	/**
	 * Void down() : fa scendere un nodo fin quando non rispetta la proprietà degli heap.
	 * Int i : indice del nodo.
	 */
	void down(int i){
		while(!isRoot(i)){
			int p = parent(i);
			if(isLower(i,p))
				swap(i,p);
			else 
				return;
			i = p;
		}
	}
	/**
	 * Void heapify() : heapify.
	 * Int i : indice del nodo.
	 */
	void heapify(int i){
		int m = left(i);
		if(!isIndex(m))
			return;
		int s = sibling(m);
		if(isIndex(s))
			if(isLower(s,m)){
				m = s;
			}
		if(isLower(m,i)){
			swap(m,i);
			heapify(m);
		}
	}
public:
	/**
	 * Heap() : crea un heap.
	 * Int n : dimensione massima dell'heap.
	 */
	Heap(int n){
		this->n = n;
		size = 0;
		v = new Key [n];
		v--;
	}
	/**
	 * ~Heap() : distruttore dell'heap.
	 */
	~Heap(){
		v++;
		delete [] v;
	}
	/**
	 * Heap<Key>* insert() : inserisce un nuovo nodo e ritorna se stesso.
	 * Key k : chiave del nodo da tornare.
	 */
	Heap<Key>* insert(Key k){
		size++;
		v[size] = k;
		down(size);
		return this;
	}
	/**
	 * Key extract() : estrae la radice.
	 */
	Key extract(){
		if(isEmpty())
			throw std::invalid_argument( "Extraction on empty heap." );
		Key k = v[1];
		v[1] = v[size--];
		heapify(1);
		return k;
	}
	/**
	 * Heap<Key>* insert() : stampa l'heap e ritorna se stesso.
	 */
	Heap<Key>* show(){
		cout<<"Showing Heap:"<<endl;
		cout<<"Size : "<<size<<endl;
		cout<<"< ";
		for(int i = 1; i<=size; i++){
			cout<<v[i];
			if(i != size)
				cout<<" ";
		}
		cout<<" >"<<endl;
		return this;
	}
	/**
	 *
	 */
	Heap<Key>* buildHeap(Key buffer[],int bufferSize){
		if(size>0)
			return this;
		size = bufferSize;
		for(int i = 0; i<size; i++)
			v[i+1] = buffer[i];
		for(int i = size/2; i>0; i--){
			heapify(i);
		}
		return this;
	}
};

/**
 * Classe MinHeap : implementa un min-heap.
 */
template<class Key> class MinHeap : public Heap<Key>{
	using Heap<Key>::Heap;
protected:
	inline bool isLower(int i, int j) override {return this->v[i]<this->v[j];}
};

/**
 * Classe MaxHeap : implementa un max-heap.
 */
template<class Key> class MaxHeap : public Heap<Key>{
	
	using Heap<Key>::Heap;
protected:
	inline bool isLower(int i, int j) override {return this->v[i]>this->v[j];}
};

#endif
