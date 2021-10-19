// ---------------------------------------------------------------------------

#ifndef UPoliListaSmH
#define UPoliListaSmH

// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "ListaCSMemoria.h"

class PoliListaSm {
private:
	ListaSM* KDCDS;
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
	void Derivada();
	void toStr();
};
#endif
