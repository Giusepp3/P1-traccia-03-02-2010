#ifndef coda_h
#define coda_h
#include <iostream>
#include <fstream>
#include <cstring>
#include "foto.h"

#define NL 4 // numero degli elementi scritti su file 

using namespace std;
using namespace photos;

typedef fotografia T;

namespace queue{
	
	class codafotografie{
		private:
			static const int N = 20;
			T s[N];
			int nelem;
			int testa;
			int coda;
		public:
			codafotografie(const char* nomefile);
			bool full()const{return N==nelem;}
			bool empty()const{return nelem==0;}
			bool append(const T & e);
			bool pop(T & e);
			void stampa()const; //
		 
	};
	
	
	
	
	
}





#endif //coda_h
