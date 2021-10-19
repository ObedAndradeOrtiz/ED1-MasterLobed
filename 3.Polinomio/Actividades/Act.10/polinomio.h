#ifndef polinomioH
#define polinomioH
#include <iostream>
#include <string>

using namespace std;

const int maxV = 10;

class polinomio {
private:
	int vc[maxV];
    int ve[maxV];
	int nt; 
public:
	polinomio();
	bool es_cero();
	int grado();
	void asignarCoeficiente(int Exp, int coef);
	void poner_termino(int coef, int Exp);
	int coeficiente(int Exp);
	int exponente(int nro);
	
	int numero_terminos();
	void  suma(polinomio otro);
	void  resta(polinomio otro);
	void multiplica(polinomio otro);
	
	void toStr();
};

#endif