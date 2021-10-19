//---------------------------------------------------------------------------

#ifndef PilaEOAOH
#define PilaEOAOH
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
		  void poner(elemento e);
		  elemento sacar(elemento &e);
		  elemento cima();
          void mostrar();
};
#endif