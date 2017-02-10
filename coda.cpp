#include "coda.h"

namespace queue{
	
	codafotografie::codafotografie(const char* nomefile){
		nelem = 0;
		testa=coda=0;
		ifstream in(nomefile, ios::in | ios::binary);
		if(in.fail()) cout << "errore file!";
		
		cout << "inizializzo la pila\n\n";
		
		T e;
		
		for(int i=0;i<NL;i++){
			if(full()) throw("la coda è piena! impossibile inserire!!!");
			in >> e;
			if(append(e)) cout << "elemento inserito! ";
			else cout << "errore nell'inserimento! ";
		}	
	
	}
	
	bool codafotografie::append(const T & e){
		if(full()) return false;
		s[coda]=e;
		coda=(coda+1)%N;
		nelem++;
		return true;
	}
	
	bool codafotografie::pop(T & e){
		if(empty()) throw("impossibile estrarre da una pila vuota!!");
		e=s[testa];
		nelem--;
		testa=(testa+1)%N;
		return true;
	}
	
	void codafotografie::stampa()const{
		for(int i=0;i<nelem;i++){
			cout << s[i];
		}
	}
	
	
	
	
}
