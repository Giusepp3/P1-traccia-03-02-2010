#include <iostream>
#include "foto.h"

#include "coda.h"

#define S "coda"

using namespace std;
using namespace photos;
using namespace queue;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main() {
	
	//programma di test per la classe fotografia
	
	if(S=="foto"){
	
	{ // blocco 1 
	
	cout << "programma test per la classe foto:\n\n";
	
	//test costruttore
	fotografia f, f1("una giornata al mare"), f2("in gita a roma", "tiff"); // costruttore con argomenti e senza
	fotografia f3=f2; //costruttore di copia
	
	f=f1; //op assegnazione
	
	if(f1==f) cout << "le foto sono uguali! \n\n"; // op == 
	
	if(f1!=f3) cout << "le foto sono diverse! \n\n"; // op !=
	
	cin >> f >> f3; //lettura da tastiera
	
	cout << f << f1 << f2 << f3 << endl; // stampa a video 
	
	//test scrittura e lettura da file 
	
	cout << "scrivo le foto su file: ";
	
	ofstream of("testfoto.bin", ios::out | ios::binary);
	if(of.fail()) cout << "errore file!";
	
	of << f << f1 << f2 << f3;
	
	of.close();
	
	cout << "scrittura su file completata!\n\ndealloco e leggo le foto da file!\n\n\n";
	
	} // blocco 1
	
	{ // blocco 2
	
	fotografia f,f1,f2,f3;
	
	ifstream in("testfoto.bin", ios::in | ios::binary);
	if(in.fail()) cout << "errore file!";
	
	cout << "leggo le foto da file: \n\n";
	
	in >> f >> f1 >> f2 >> f3;
	
	cout << "le foto lette da file sono: " << endl << f << f1 << f2 << f3 ;
	
	} // blocco 2
	
	} //fine test foto
	
	
	if(S=="coda"){
	
	codafotografie c("testfoto.bin");
	
	fotografia f;
	
	cin >> f;
	
	c.append(f); //test inserimento
	
	c.stampa();
	
	
	
	try{
	while(true) c.pop(f); //test eccezione
	} catch(const char* e){
		cout << "rilevato errore!! " << e;
	}
	
	c.append(f);
	
	c.stampa();
	
		
	} //fine test coda
	
	
	return 0;
}
