#include <iostream>
#include "ConjuntoM.h"
#include "CSMemoria.h" 

using namespace std;
void complemento_interseccion(ConjuntoM* a, ConjuntoM* b, ConjuntoM* &c);
int main() {
   CSMemoria* m = new CSMemoria();
 m->new_espacio("grupo,sd");
 ConjuntoM* aEOAO = new ConjuntoM(m);
 ConjuntoM* bEOAO = new ConjuntoM(m);
 ConjuntoM* cEOAO = new ConjuntoM(m);
 aEOAO->inserta(10);
 bEOAO->inserta(10);
 bEOAO->inserta(30);
 aEOAO->inserta(20);
 complemento_interseccion(aEOAO,bEOAO,cEOAO); 
 cEOAO->to_str();
 m->mostrar();
 return 0;
}


void complemento_interseccion(ConjuntoM* a, ConjuntoM* b, ConjuntoM* &c) {
 ConjuntoM*ayuda = new ConjuntoM();
 while (!a->vacio()) {
  int elem = a->muestrea();
  if (!(a->pertenece(elem) && b->pertenece(elem))) {
   c->inserta(elem);
  }
  a->suprime(elem);
  ayuda->inserta(elem);
 }
 while (!ayuda->vacio()) {
  int e = ayuda->muestrea();
  ayuda->suprime(e);
  a->inserta(e);
 }
 while (!b->vacio()) {
  int elemb = b->muestrea();
  if (!(a->pertenece(elemb) && b->pertenece(elemb))) {
   c->inserta(elemb);
  }
  b->suprime(elemb);
  ayuda->inserta(elemb);
 }
 while (!ayuda->vacio()) {
  int e = ayuda->muestrea();
  ayuda->suprime(e);
  b->inserta(e);
 }
}