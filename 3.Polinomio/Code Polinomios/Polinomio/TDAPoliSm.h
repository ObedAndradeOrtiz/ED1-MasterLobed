#ifndef TDAPoliSmH
#define TDAPoliSmH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

using namespace std;

const string datosP = "coef,exp,sig";
const string coefP = "->coef";
const string expP = "->exp";
const string sigP = "->sig";


class PoliSm {
private:
	CSMemoria* mem;
	int ptr_poli;
	int nt;

	int buscar_exponente(int exp);
	int buscar_termino_n(int i);
	int anterior(int dir);

public:
	PoliSm();
	PoliSm(CSMemoria* m);
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	void sumar(PoliSm* p1, PoliSm* p2, PoliSm* &pr);
	void restar(PoliSm* p1, PoliSm* p2, PoliSm* &pr);
	void multiplicar(PoliSm* p1, PoliSm* p2, PoliSm* &pr);
	void derivar();
	string to_str();
};
#endif
