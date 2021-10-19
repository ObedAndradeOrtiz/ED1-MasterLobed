//---------------------------------------------------------------------------

#ifndef PoliListaH
#define PoliListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "ListaPuntero.h"

using namespace std;

class PoliLista {
private:
	ListaP* KEOAO;
	int nt;
	NodoL* exponente_existe(int exp);
public:
	PoliLista();
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro);
	int grado();
	int numero_terminos();

	void derivada();
	string toStr();
};
#endif
