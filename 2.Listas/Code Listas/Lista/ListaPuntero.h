//---------------------------------------------------------------------------

#ifndef ListaPunteroH
#define ListaPunteroH
#include <iostream>
#include <string>

using namespace std;

struct NodoL {
	int elemento;
	NodoL* sig;
};

class ListaP{
private:
	NodoL* ptrElementos;
	int longi;

public:
	ListaP();
	NodoL* fin();
	NodoL* primero();
	NodoL* siguiente(NodoL*);
	NodoL* anterior(NodoL*);
	bool vacia();
	int recupera(NodoL*);
	int longitud();
	void inserta(NodoL*, int);
	void inserta_primero(int);
	void inserta_ultimo(int);
	void suprime(NodoL*);
	void modifica(NodoL*, int);
	string toStr();
};
#endif
