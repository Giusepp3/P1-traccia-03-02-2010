#include "foto.h"

namespace photos{
	
	fotografia::fotografia(){
		titolo = new char[1];
		strcpy(titolo,"");
		formato = new char[1];
		strcpy(formato,"");
	}
	
	fotografia::fotografia(const char* t, const char* f){
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
		formato = new char[strlen(f)+1];
		strcpy(formato,f);
	}
	
	fotografia::fotografia(const fotografia & f){
		titolo = new char[strlen(f.titolo)+1];
		strcpy(titolo,f.titolo);
		formato = new char[strlen(f.formato)+1];
		strcpy(formato,f.formato);
	}
	
	fotografia::~fotografia(){
		delete [] titolo;
		delete [] formato;
	}
	
	const fotografia & fotografia::operator=(const fotografia & f){
		if(this==&f) return *this;
		set_titolo(f.titolo);
		set_formato(f.formato);
		return *this;
	}
	
	
	void fotografia::set_titolo(const char* t){
		if(titolo) delete [] titolo;
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
	}
	
	void fotografia::set_formato(const char* f){
		if (formato) delete [] formato;
		formato = new char[strlen(f)+1];
		strcpy(formato,f);
	}
	
	void fotografia::print(ostream  & of)const{
		of << "titolo:	" << titolo << endl << "formato:	" << formato << "\n\n\n";
	}
	
	ostream & operator<<(ostream & os, const fotografia & f){
		f.print(os);
		return os;
	}
	
	void fotografia::printf(ofstream & of)const{
		int t,f;
		t=strlen(titolo);
		f=strlen(formato);
		of.write((char*)&t,sizeof(t));
		of.write(titolo,t);
		of.write((char*)&f,sizeof(f));
		of.write(formato,f);
	}
	
	ofstream & operator<<(ofstream  & of, const fotografia & f){
		f.printf(of);
		return of;
	}
	
	void fotografia::read(istream & in){
		char b[800];
		cout << "inserisci il titolo: ";
		in.getline(b,799);
		cout << "inserisci il formato: ";
		set_titolo(b);
		in.getline(b,799);
		set_formato(b);
	}
	
	istream & operator>>(istream  &in,  fotografia & f){
		f.read(in);
		return in;
	}
	
	
	void fotografia::readf(ifstream & in){
		int f,t;
		in.read((char*)&t,sizeof(t));
		char* b = new char[t+1];
		in.read(b,t);
		b[t]='\0';
		set_titolo(b);
		delete [] b;
		in.read((char*)&f,sizeof(f));
		b=new char[f+1];
		in.read(b,f);
		b[f]='\0';
		set_formato(b);
		delete [] b;
	}
	
	ifstream & operator>>(ifstream & in, fotografia  &f){
		f.readf(in);
		return in;
	}
	
	
}
