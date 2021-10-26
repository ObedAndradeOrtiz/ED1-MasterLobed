// ---------------------------------------------------------------------------

#ifndef CpolinimioH
#define RAPCpolinomioH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

struct NodoPoli {
	int coef;
	int exp;
	NodoPoli* sig;
};

class RAPCpolinomio {
private:
	NodoPoli* RAPptr_poli;
	int RAPnt;
	NodoPoli* existe_exponente(int exp);
	NodoPoli* anterior(NodoPoli* p);
	void suprime(NodoPoli* p);
public:
	RAPCpolinomio();
	bool es_cero();
	void poner_termino(int coef, int exp);
	int coeficiente(int exp);
	int exponente(int nro);
	int grado();
	int numero_terminos();
	RAPCpolinomio* suma(RAPCpolinomio* otro);
	RAPCpolinomio* resta(RAPCpolinomio* otro);
	string toStr();
};
#endif