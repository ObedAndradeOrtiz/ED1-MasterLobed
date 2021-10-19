// ---------------------------------------------------------------------------

#ifndef UPoliListaSmH
#define UPoliListaSmH

// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "ListaCSMemoria.h"

class PoliListaSm {
private:
	ListaSM* KEOAO;
	int nt;

	int exponente_existe(int exp);

public:
	PoliListaSm(CSMemoria *mem);
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