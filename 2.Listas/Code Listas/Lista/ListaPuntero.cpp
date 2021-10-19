//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>

using namespace std;
ListaP::ListaP() {
	longi = 0;
	ptrElementos = NULL;
}
NodoL* ListaP::fin() {
	if (vacia()) {
		cout << "LISTA VACIA\n";
	}
	else {
		NodoL* ptrFin=NULL;
		NodoL* x = ptrElementos;
		while (x != NULL) {
			ptrFin = x;
			x = x->sig;
		}
		return ptrFin;
	}
}
NodoL* ListaP::primero() {
	if (!this->vacia()) {
		return ptrElementos;
	}
	else {
		return NULL;
		// cout << "LISTA VACIA\n";
	}
}
NodoL* ListaP::siguiente(NodoL* p) {
	if (this->vacia()) {
		cout << "LISTA VACIA\n";
	}
	else if (p== fin())
	 {

        return NULL;
	 }
	  else {
		return p->sig;
	  }
}
NodoL* ListaP::anterior(NodoL* p) {
	if (this->vacia()) {
		cout << "LISTA VACIA\n";
	}
	else if (p == primero()) {
		cout << "DIRECCION INCORRECTA\n";
	}
	else {
		NodoL* x = ptrElementos;
		NodoL* ant = NULL;
		while (x != NULL) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}
bool ListaP::vacia() {
	return longi == 0; // ptrElementos == NULL;
}
int ListaP::recupera(NodoL* p) {
	if (this->vacia()) {
		cout << "LISTA VACIA\n";
	}
	else {
		return p->elemento;
	}
}

int ListaP::longitud() {
	return longi;
}

void ListaP::inserta(NodoL* p, int e) {
	NodoL* x = new NodoL;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia()) {
			ptrElementos = x;
			longi = 1;
		}
		else {
			longi++;
			if (p == primero()) {
				x->sig = p;
				ptrElementos = x;
			}
			else {
				NodoL* ant = anterior(p);
				ant->sig = x;
				x->sig = p;
			}
		}
	}
}
void ListaP::inserta_primero(int e)
{
NodoL* x= new NodoL;
if(x!=NULL)
{
	x->elemento=e;
	x->sig=ptrElementos;
	longi++;
	ptrElementos=x;
}
}
void ListaP::inserta_ultimo(int e) {
	NodoL* x = new NodoL;
if(x!=NULL)
{
	x->elemento=e;
	x->sig=NULL;
	if(longi!=0)
	{
		fin()->sig=x;
	}
	else
	{
		ptrElementos=x;
	}
    longi++;
}
}

void ListaP::suprime(NodoL* p) {
	if (longi == 0) {
		cout << "LISTA VACIA\n";
		return;
	}
	else if (p == ptrElementos) {
		NodoL*x = ptrElementos;
		ptrElementos = ptrElementos->sig;
		delete(x);
	}
	else {
		NodoL* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
	longi--;
}

void ListaP::modifica(NodoL* p, int e) {
	if (vacia()) {
		cout << "LISTA VACIA\n";
	}
	else {
		p->elemento = e;
	}
}
string ListaP::toStr() {
	string r = "Keoao<";
	NodoL* x = ptrElementos;
	while (x != NULL) {
		r += to_string(x->elemento);
		if (x->sig != NULL)
			r += ",";
		x = x->sig;
	}
	r = r + ">";
	return r;
}









