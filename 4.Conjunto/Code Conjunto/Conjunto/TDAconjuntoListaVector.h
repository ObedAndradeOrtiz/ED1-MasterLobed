//---------------------------------------------------------------------------

#ifndef TDAconjuntoListaVectorH
#define TDAconjuntoListaVectorH
#include "ListaVector.h"
//---------------------------------------------------------------------------
class ConjuntoLV{
private:
	   ListaVector* Elem;
       int cant;
public:
	  ConjuntoLV();
	  bool vacío ();
	  bool pertenece(int e);
	  void inserta(int e);
	  int cardinal();
	  int ordinal(int e);
	  void suprime(int e);
	  int muestrea();
	  void To_Str();
};
#endif
