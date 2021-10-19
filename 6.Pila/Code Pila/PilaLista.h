//---------------------------------------------------------------------------

#ifndef PilaListaH
#define PilaListaH
#include "ListaPuntero.h"
//---------------------------------------------------------------------------
typedef int elemento;
class pilaL
{
   private:
		  ListaP *L;
   public:
		  pilaL();
		  bool vacia();
		  void meter(elemento e);
		  elemento sacar(elemento e);
		  elemento cima();

};
#endif
