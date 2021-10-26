// ---------------------------------------------------------------------------

#ifndef CpolinimioH
#define CpolinomioH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct NodoPoli {
	int coef;
	int exp;
	NodoPoli* sig;
};

class Cpolinomio {
private:
	NodoPoli* ptrPoli;
	int nt;
	NodoPoli* existe_exponente(int exp);
	NodoPoli* anterior(NodoPoli* p);
	void suprime(NodoPoli* p);
public:
	Cpolinomio();
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro);
	int grado();
	int numero_terminos();
	Cpolinomio* suma(Cpolinomio* otro);
	Cpolinomio* resta(Cpolinomio* otro);
	string toStr();
};
#endif
