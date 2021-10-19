#include <string>
#include "CSMemoria.h"

using namespace std;

const string data = "coef,exp,sig";
const string at_coef = "->coef";
const string at_exp = "->exp";
const string at_sig = "->sig";

class PoliSm {
private:
	CSMemoria *mem;
	int ptrPoli;
	int nt; // numero de terminos

	// metodos privados
	int BuscarExponente(int Exp);
    

public:
	PoliSm();
	PoliSm(CSMemoria *m);
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro);
	int grado();
	int numero_terminos();
	PoliSm *suma(PoliSm* otro);
	PoliSm *resta(PoliSm* otro);
	void toStr();
};