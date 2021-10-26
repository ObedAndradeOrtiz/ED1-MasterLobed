#include "RAPCpolinomio.h"


RAPCpolinomio::RAPCpolinomio() {
	RAPptr_poli = NULL;
	RAPnt = 0;
}

bool RAPCpolinomio::es_cero() {
	return RAPnt == 0;
}

NodoPoli* RAPCpolinomio::existe_exponente(int exp) {
	NodoPoli* aux = RAPptr_poli;
	while (aux != NULL) {
		if (aux->exp == exp)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void RAPCpolinomio::poner_termino(int coef, int exp) {
	NodoPoli* existe = existe_exponente(exp);
	if (existe == NULL) {
		NodoPoli* aux = new NodoPoli;
		if (aux != NULL) {
			aux->coef = coef;
			aux->exp = exp;
			aux->sig = RAPptr_poli;
			RAPptr_poli = aux;
			RAPnt++;
		}
		else
			cout << "ERROR ESPACIO MEMORIA\n";
	}
	else {
		existe->coef = existe->coef + coef;
		if (existe->coef == 0) {
			suprime(existe);
			RAPnt--;
		}
	}
}

NodoPoli* RAPCpolinomio::anterior(NodoPoli* p) {
	if (RAPnt == 0) {
	}
	else if (p == RAPptr_poli) {
		cout << "DIRECCION INCORRECTA\n";
	}
	else {
		NodoPoli* x = RAPptr_poli;
		NodoPoli* ant = NULL;
		while (x != NULL) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}

void RAPCpolinomio::suprime(NodoPoli* p) {
	if (RAPnt == 0) {
		return;
	}
	else if (p == RAPptr_poli) {
		NodoPoli* x = RAPptr_poli;
		RAPptr_poli = RAPptr_poli->sig;
		delete(x);
	}
	else {
		NodoPoli* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
}

int RAPCpolinomio::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		NodoPoli* aux = RAPptr_poli;
		while (aux != NULL) {
			if (aux->exp == exp)
				return aux->coef;
			aux = aux->sig;
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int RAPCpolinomio::exponente(int nro) {
	if (nro < RAPnt) {
		NodoPoli* aux = RAPptr_poli;
		int cont = 0;
		while (cont < nro) {
			aux = aux->sig;
			cont++;
		}
		return aux->exp;
	}
	else
		cout << "ERROR DE RANGO\n";
}

int RAPCpolinomio::grado() {
	NodoPoli* aux = RAPptr_poli;
	int may = aux->exp;
	while (aux != NULL) {
		if (aux->exp > may)
			may = aux->exp;
		aux = aux->sig;
	}
	return may;
}

int RAPCpolinomio::numero_terminos() {
	return RAPnt;
}

RAPCpolinomio* RAPCpolinomio::suma(RAPCpolinomio* otro) {
	RAPCpolinomio* pr = new RAPCpolinomio();
	for (int i = 0; i < RAPnt; i++) {
		int exp1 = this->exponente(i);
		int coef1 = this->coeficiente(exp1);
		pr->poner_termino(coef1, exp1);
	}
	for (int i = 0; i < otro->RAPnt; i++) {
		int exp2 = otro->exponente(i);
		int coef2 = otro->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}
	return pr;
}

RAPCpolinomio* RAPCpolinomio::resta(RAPCpolinomio* otro) {
	RAPCpolinomio* pr = new RAPCpolinomio();
	for (int i = 0; i < RAPnt; i++) {
		int exp1 = this->exponente(i);
		int coef1 = this->coeficiente(exp1);
		pr->poner_termino(coef1, exp1);
	}
	for (int i = 0; i < otro->RAPnt; i++) {
		int exp2 = otro->exponente(i);
		int coef2 = -otro->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}
	return pr;
}

string RAPCpolinomio::toStr() {
	string ret = "";
	for (int i = 0; i < RAPnt; i++) {
		int exp = this->exponente(i);
		int coef = this->coeficiente(exp);
		string signo;
		if (coef > 0)
			signo = "+";
		else {
			signo = "-";
			coef = coef * -1;
		}
		ret = ret + signo + to_string(coef) + "x^" + to_string(exp);
	}
	return ret;
}