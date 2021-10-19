// ---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAPoliPuntero.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliPtr::PoliPtr() {
	ptrPoli = NULL;
    KEOAO= new ListaP();
	nt = 0;
}

bool PoliPtr::es_cero() {
	return nt == 0;
}

NodoPoli* PoliPtr::existe_exponente(int exp) {
	NodoPoli* aux = ptrPoli;
	while (aux != NULL) {
		if (aux->exp == exp)
			return aux;
		aux = aux->sig;
	}
	return NULL;
}

void PoliPtr::poner_termino(int coef, int exp) {
	NodoPoli* existe = existe_exponente(exp);
	if (existe == NULL) {
		NodoPoli* aux = new NodoPoli;
		if (aux != NULL) {
			aux->coef = coef;
			aux->exp = exp;
			aux->sig = ptrPoli;
			ptrPoli = aux;
			nt++;
		}
		else
			cout << "ERROR ESPACIO MEMORIA\n";
	}
	else {
		existe->coef = existe->coef + coef;
		if (existe->coef == 0) {
			suprime(existe);
			nt--;
		}
	}
}

NodoPoli* PoliPtr::anterior(NodoPoli* p) {
	if (nt == 0) {
	}
	else if (p == ptrPoli) {
		cout << "DIRECCION INCORRECTA\n";
	}
	else {
		NodoPoli* x = ptrPoli;
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

void PoliPtr::suprime(NodoPoli* p) {
	if (nt == 0) {
		return;
	}
	else if (p == ptrPoli) {
		NodoPoli* x = ptrPoli;
		ptrPoli = ptrPoli->sig;
		delete(x);
	}
	else {
		NodoPoli* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
}

int PoliPtr::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		NodoPoli* aux = ptrPoli;
		while (aux != NULL) {
			if (aux->exp == exp)
				return aux->coef;
			aux = aux->sig;
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliPtr::exponente(int nro) {
	if (nro < nt) {
		NodoPoli* aux = ptrPoli;
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

int PoliPtr::grado() {
	NodoPoli* aux = ptrPoli;
	int may = aux->exp;
	while (aux != NULL) {
		if (aux->exp > may)
			may = aux->exp;
		aux = aux->sig;
	}
	return may;
}

int PoliPtr::numero_terminos() {
	return nt;
}

PoliPtr* PoliPtr::suma(PoliPtr *otro) {
	PoliPtr *pr = new PoliPtr();
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

PoliPtr* PoliPtr::resta(PoliPtr *otro) {
	PoliPtr *pr = new PoliPtr();
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

string PoliPtr::toStr() {
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
	return ret;
}

