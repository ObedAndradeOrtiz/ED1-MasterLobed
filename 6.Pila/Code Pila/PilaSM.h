//---------------------------------------------------------------------------

#ifndef PilaSMH
#define PilaSMH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
typedef int Elemento;
class pilaSM
{
   private:
		  CSMemoria * mem;
		  int tope;
   public:
		  pilaSM(CSMemoria *m);
		  bool vacia();
		  void meter(Elemento e);
		  void sacar(Elemento &e);
		  Elemento cima();
};
#endif
