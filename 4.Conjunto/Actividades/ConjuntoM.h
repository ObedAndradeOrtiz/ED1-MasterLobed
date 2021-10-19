#ifndef ConjuntoMH
#define ConjuntoMH
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

const string datosCJ = "dato,sig";
const string datoCJ = "->dato";
const string sigCJ = "->sig";

class ConjuntoM {
private:
 CSMemoria* mem;
 int ptr_conj;
 int cant;

public:
 ConjuntoM();
 ConjuntoM(CSMemoria* m);
 bool vacio();
 bool pertenece(int e);
 void inserta(int e);
 int cardinal();
 int ordinal(int e);
 void suprime(int e);
 int muestrea();
 void to_str();
};
#endif