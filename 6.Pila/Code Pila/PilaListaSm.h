//---------------------------------------------------------------------------

#ifndef PilaListaSmH
#define PilaListaSmH
#include "ListaCSMemoria.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------//---------------------------------------------------------------------------
typedef int elemento;
class PilaEOAO
{
   private:
		  ListaSM *L;
   public:
		  PilaEOAO(CSMemoria *m);
		  bool vacia();
		  void meter(elemento e);
		  elemento sacar(elemento &e);
		  elemento cima();
          void ToStr();
};
#endif
