//---------------------------------------------------------------------------

#ifndef TDAconjuntoListaCSMemoriaH
#define TDAconjuntoListaCSMemoriaH
#include "ListaCSMemoria.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
class ConjuntoLM{
private:
	   ListaSM* Elem;
	   int ptrConj;
	   int cant;
public:
	  ConjuntoLM(CSMemoria* m);
	  bool vacio ();
	  bool pertenece(int e);
	  void inserta(int e);
	  int cardinal();
	  int ordinal(int e);
	  void suprime(int e);
	  int muestrea();
	  void To_Str();
};
#endif
