#ifndef foto_h
#define foto_h

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace photos{
	
	class fotografia{
		private:
			char* titolo;
			char* formato;
			void print(ostream & of)const; 
			void printf(ofstream & of)const; 
			void read(istream & in); 
			void readf(ifstream & in);
			
		public:
			fotografia(); 
			explicit fotografia(const char* titolo, const char* formato = "jpeg");
			fotografia(const fotografia & foto); 
			const fotografia & operator=(const fotografia&);
			~fotografia();
			const char* get_titolo()const{return titolo;}
			const char* get_formato()const{return formato;}
			void set_titolo(const char* titolo);
			void set_formato(const char* formato);
			bool operator==(const fotografia& f)const{return (!strcmp(titolo,f.titolo) && !strcmp(formato,f.formato));}
			bool operator!=(const fotografia& f)const{return !(*this==f);}
			friend ostream & operator<<(ostream & of, const fotografia & f); 
			friend ofstream & operator<<(ofstream & of, const fotografia & f);
			friend ifstream & operator>>(ifstream & in, fotografia & f);
			friend istream & operator>>(istream & in, fotografia & f); 
			
	};
		
	
	
	
	

	
	
	
}

#endif //foto_h
