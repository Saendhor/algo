#include "heap.hpp"
#include <iostream>
#include <limits.h>
#include <exception>

using namespace std;


/**
 * Classe Parser : implementa il parsing dei parametri forniti dall'utente. 
 */
class Parser{
private:
	/**
	 * Enum Instruction : rappresenta le istruzioni disponibili.
	 */
	enum Instruction{
		INSERT,
		EXTRACT,
		DELETE,
		DECREASE,
		MAXHEAP,
		MINHEAP,
		HELP,
		BUFFER,
		INSTRUCTION_NUMBER,
		VALUE,
		FAKE
	};
	/**
	 * Int max : massimo numero di elementi nell'heap.
	 */
	static const int max = 1000;
	/**
	 * String label : rapressenta l'etichetta di ogni istruzione.
	 */
	static const string label[ INSTRUCTION_NUMBER ];
	/**
	 * String arity : rappresenta l'arità di ogni istruzione.
	 */
	static const int arity[ INSTRUCTION_NUMBER ];
	/**
	 *Int buffer : buffer di valori non assegnati.
	 */
	int buffer[max];
	/**
	 * Int bufferSize : numero di elementi nel buffer;
	 */
	int bufferSize = 0;
	/**
	 * Instruction instruction : vettore che classifica ciascun argomento come istruzione.
	 */
	Instruction* instruction;
	/**
	 * String argument : vettore degli argomenti.
	 */
	string* argument;
	/**
	 * Int n : numero di argomenti fornito dall'utente.
	 */
	int n;
	/**
	 * Heap heap : l'heap usato nell'applicazione.
	 */
	Heap<int>* heap = nullptr;
	/**
	 * Void set() : imposta n e argument.
	 * - Int argc : è il numero di argomenti forniti al processo.
	 * - Char** argv : argv è il vettore degli argomenti forniti al processo.
	 */
	void set(int argc, char** argv){
		n = argc-1;
		argument = new string [n];
		instruction = new Instruction[n];
		for(int i = 0; i<n; i++)
			argument[i] = string(argv[i+1]);
	}
	/**
	 * Bool check() : controlla la correttezza degli argomenti forniti e ritorna 'true' se errati.
	 * Int current : indice dell'argomento da cui iniziare il controllo.
	 */
	bool check(int current){
		if(current>=n)
			return false;
		Instruction command = FAKE;
		for(int i = 0; i < (int) INSTRUCTION_NUMBER; i++)
			if(argument[current] == label[i])
				command = (Instruction) i;
		if(inconsistent(command,current))
			return (check(current+1) || true);
		return (check(current+1+arity[command]) || false);
	}
	/**
	 * Bool inconsistent() : controlla se un determinato comando è stato applicato bene.
	 * Instruction command : il tipo del comando da controllare.
	 * Int current : indice dell'argomento da controllare.
	 */
	bool inconsistent(Instruction command, int current){
		if(command == FAKE){
			cout<<"Error: expected <command> instead of '"<<argument[current]<<"'."<<endl;
			return true;
		}
		if(n - current - 1 < arity[command]){
			cout<<"Error: expected "<<arity[command]<<" arguments after the last instruction : '"<<label[command]<<"'."<<endl;
			return true;
		}
		instruction[current] = command;
		bool status = false;
		for(int i = 0; i<arity[command]; i++){
			if(isValue(argument[current + i + 1]))
				instruction[current + i + 1] = VALUE;
			else{
				status = true;
				instruction[current + i + 1] = FAKE;
				cout<<"Error: expected <value> instead of '"<<argument[current]<<"'."<<endl;
			}	
		}
		return status;
	}
	/**
	 * Bool run() : esegue quanto richiesto dall'utente.
	 * Int current : indice del primo comando da eseguire.
	 */
	bool run(int current){
		if(current>=n){
			cout<<endl;
			return false;
		}
		cout<<endl;
		Instruction& command = instruction[current];
		switch(command){
			case MAXHEAP:
				cout<<"Making Max-Heap:"<<endl;
				try{
					delete heap;
				}catch(const exception& e){
					error(e);
					return true;
				}
				heap = new MaxHeap<int>(max);
				heap->buildHeap(buffer,bufferSize);
				bufferSize = 0;
				heap->show();
				break;
			case MINHEAP:
				cout<<"Making Min-Heap:"<<endl;
				try{
					delete heap;
				}catch(const exception& e){
					error(e);
					return true;
				}
				heap = new MinHeap<int>(max);
				heap->buildHeap(buffer,bufferSize);
				bufferSize = 0;
				heap->show();
				break;
			case INSERT:
				try{
					cout<<"Inserting "<<argument[current+1]<<" to the data structure:"<<endl;
					heap->insert(stoi(argument[current+1]));
					heap->show();
				}catch(const exception& e){
					error(e);
					return true;
				}
				break;
			case EXTRACT:
				try{
					cout<<"Extracting value from the data structure:"<<endl;
					int k = heap->extract();
					heap->show();
					cout<<"Heap returned value "<<k<<" after extraction."<<endl;
				}catch(const exception& e){
					error(e);
					return true;
				}
				break;
			case HELP:
				help();
				break;
			case BUFFER:
				try{
					cout<<"Inserting value "<<argument[current+1]<<" in buffer:"<<endl;
					if(bufferSize < max)
						buffer[bufferSize++] = stoi(argument[current+1]);
					showBuffer();
				}catch(const exception& e){
					error(e);
					return true;
				}
				break;	
		}
		return (run(current+1+arity[command]) || false);
	}
	/**
	 * Void help() : mostra la modalità d'uso dell'applicazione.
	 */
	void help(){
		cout<<"Usage:"<<endl;
		cout<<"'./heap [<command>]*'"<<endl;
		cout<<endl;
		cout<<"<command> can be: "<<endl;
		cout<<"'-h' to show help."<<endl;
		cout<<"'-v <value>' to insert <value> in the buffer."<<endl;
		cout<<"'-m' to create a min-heap from buffer."<<endl;
		cout<<"'-M' to create a max-heap from buffer."<<endl;
		cout<<"'-i <value>' to insert <value> in the data structure."<<endl;
		cout<<"'-e' to extract a <value> from the data structure."<<endl;
		cout<<endl;
		cout<<"<value> can be any integer between "<<INT_MIN<<" and "<<INT_MAX<<"."<<endl;
		cout<<endl;
		cout<<"Example:"<<endl;
		cout<<"'./heap -m -i 3 -i 2 -i 1 -e -e -M -i 3 -i 2 -i 1 -e -e -e'"<<endl;
	}
	/**
	 * Void error() : mostra all'utente la presenza di un errore.
	 * Exveption e : eccezione sollevata dall'errore.
	 */
	void error(const exception& e){
		cout<<"Error, something went wrong:"<<endl;
		cout<<"System sent error: '"<<e.what()<<"'."<<endl;
	}
	/**
	 * Bool isValue() : controlla se una stringa rappresenta un intero.
	 * String str : la stringa da controllare.
	 */
	bool isValue(const std::string &str){
	    return str.find_first_not_of("0123456789") == std::string::npos;
	}
	/**
	 * Void aware() : suggerisce all'utente di controllare la modalità d'uso.
	 */
	void aware(){
		cout<<"Run './heap -h' for help."<<endl;
	}
	void showBuffer(){
		cout<<"Buffer = < ";
		for(int i = 0; i<bufferSize; i++)
			cout<<buffer[i]<<" ";
		cout<<">"<<endl;
	}
public:
	/**
	 * Parser : esegue il parsing.
	 * - Int argc : è il numero di argomenti forniti al processo.
	 * - Char** argv : argv è il vettore degli argomenti forniti al processo.
	 */
	Parser(int argc, char** argv){
		set(argc,argv);
		if(check(0)){
			aware();
			return;
		}
		if(run(0))
			return ;
		return ;		
	}
};

//Istanziazione

const string	Parser::label[]	= {	"-i",	"-e",	"-r",	"-d",	"-M",	"-m",	"-h",	"-v"	};
const int	Parser::arity[]	= {	1,	0,	1,	2,	0,	0,	0,	1	};			




int main(int argc, char** argv){
	Parser p = Parser(argc,argv);
	return 0;
}
