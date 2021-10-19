//---------------------------------------------------------------------------

#ifndef TDAconjuntoCSMemoriaH
#define TDAconjuntoCSMemoriaH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
struct NodoMe{
	   int dato;
	   NodoMe* sig;
};
class ConjuntoSM
{
  private:
			int cant;
			int ptrConj;
            CSMemoria* mem;
	  public:
      ConjuntoSM();
	  ConjuntoSM(CSMemoria * m);
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
