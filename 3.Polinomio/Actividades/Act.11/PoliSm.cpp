#include <iostream>
#include <string>
#include "PoliSm.h"
using namespace std;
int anterior(int p, int ptrPoli, int nt, CSMemoria* mem) {
	if (nt == 0) {
	}
	else if (p == ptrPoli) {
		cout << "DIRECCION INCORRECTA\n";
	}
	else {
		int x = ptrPoli;
		int ant = nulo;
		while (x != nulo) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = mem->obtener_dato(x, at_sig);
		}
	}
}

void suprime(int p , int nt, int ptrPoli, CSMemoria*  mem) {
	if (nt == 0) {
		return;
	}
	else if (p == ptrPoli) {
		int x = ptrPoli;
		ptrPoli = mem->obtener_dato(ptrPoli, at_sig);
		mem->delete_espacio(x); // delete(x);
	}
	else {
		int ant = anterior(p, ptrPoli,nt, mem);
		int p_sig = mem->obtener_dato(p, at_sig); // (p,"->sig")
		mem->poner_dato(ant, at_sig, p_sig); // (ant,"->sig,p_sig)
		// ant->sig = p->sig;
		mem->delete_espacio(p);
	}
}

PoliSm::PoliSm() {
	mem = new CSMemoria();
	ptrPoli = nulo;
	nt = 0;
}

PoliSm::PoliSm(CSMemoria *m) {
	mem = m;
	ptrPoli = nulo;
	nt = 0;
}

bool PoliSm::es_cero() {
	return nt == 0;
}

void PoliSm::poner_termino(int coef, int exp) {
	int existe = BuscarExponente(exp);
	if (existe == nulo) {
		int aux = mem->new_espacio(data);
		if (aux != nulo) {
			mem->poner_dato(aux, at_coef, coef); // aux->coef = coef;
			mem->poner_dato(aux, at_exp, exp); // aux->exp = exp;
			mem->poner_dato(aux, at_sig, ptrPoli); // aux->sig = ptrPoli;
			ptrPoli = aux;
			nt++;
		}
		else
			cout << "ERROR ESPACIO MEMORIA\n";
	}
	else {
		int existe_coef = mem->obtener_dato(existe, at_coef);
		// existe->coef = existe->coef + coef;
		mem->poner_dato(existe, at_coef, existe_coef + coef);
		existe_coef = mem->obtener_dato(existe, at_coef);
		if (existe_coef == 0) {
			suprime(existe, nt, ptrPoli, mem);
			nt--;
		}
	}
}

int PoliSm::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		int aux = ptrPoli;
		while (aux != nulo) {
			int aux_exp = mem->obtener_dato(aux, at_exp);
			if (aux_exp == exp)
				return mem->obtener_dato(aux, at_coef); // return aux->coef;
			aux = mem->obtener_dato(aux, at_sig); // aux = aux->sig;
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliSm::exponente(int nro) {
	if (nro < nt) {
		int aux = ptrPoli;
		int cont = 0;
		while (cont < nro) {
			aux = mem->obtener_dato(aux, at_sig); // aux = aux->sig;
			cont++;
		}
		return mem->obtener_dato(aux, at_exp); // return aux->exp;
	}
	else
		cout << "ERROR DE RANGO\n";
}

int PoliSm::grado() {
	int aux = ptrPoli;
	int may = mem->obtener_dato(aux, at_exp); // int may = aux->exp;
	while (aux != nulo) {
		int aux_exp = mem->obtener_dato(aux, at_exp); // aux->exp
		if (aux_exp > may)
			may = aux_exp;
		aux = mem->obtener_dato(aux, at_sig);
	}
	return may;
}

int PoliSm::numero_terminos() {
	return nt;
}

PoliSm* PoliSm::suma(PoliSm* otro) {
	PoliSm *pr = new PoliSm();
	for (int i = 0; i < nt; i++) {
		int exp1 = this->exponente(i);
		int coef1 = this->coeficiente(exp1);
		pr->poner_termino(coef1, exp1);
	}
	for (int i = 0; i < otro->nt; i++) {
		// poner_termino(p1.coeficiente(p2.exponente(i)), p2.exponente(i))
		int exp2 = otro->exponente(i);
		int coef2 = otro->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}
	return pr;
}

PoliSm* PoliSm::resta(PoliSm* otro) {
	PoliSm* pr = new PoliSm();
	for (int i = 0; i < nt; i++) {
		int exp1 = this->exponente(i);
		int coef1 = this->coeficiente(exp1);
		pr->poner_termino(coef1, exp1);
	}
	for (int i = 0; i < otro->nt; i++) {
		// poner_termino(p1.coeficiente(p2.exponente(i)), p2.exponente(i))
		int exp2 = otro->exponente(i);
		int coef2 = -otro->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}
	return pr;
}

void PoliSm::toStr() {
	string ret = "";
	for (int i = 0; i < nt; i++) {
		int exp = this->exponente(i);
		int coef = this->coeficiente(exp);
		string signo;
		if (coef > 0)
			signo = "+";
		else {
			signo = "-";
			coef = coef*-1;
		}
		ret = ret + signo + to_string(coef) + "x^" + to_string(exp);
	}
	cout<<ret<<endl;
}

int PoliSm::BuscarExponente(int Exp) {
	int aux = ptrPoli;
	while (aux != nulo) {
		int aux_exp = mem->obtener_dato(aux, at_exp);
		int aux_sig = mem->obtener_dato(aux, at_sig);
		if (aux_exp == Exp)
			return aux;
		aux = aux_sig;
	}
	return nulo;
}

