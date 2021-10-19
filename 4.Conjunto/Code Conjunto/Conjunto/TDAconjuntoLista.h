//---------------------------------------------------------------------------

#ifndef TDAconjuntoListaH
#define TDAconjuntoListaH
#include "ListaPuntero.h"
//---------------------------------------------------------------------------
class Conjunto{
private:
	   ListaP *Elem;
public:
	  Conjunto();
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
