//---------------------------------------------------------------------------

#ifndef pilaDicolaH
#define pilaDicolaH
#include "DiColaExt.h"
//---------------------------------------------------------------------------

typedef int elemento;
const int max=50;
class pilaDicola
{
   private:

		  int tope;
   public:
		  pilaDicola();
		  bool vacia();
		  void meter(elemento e);
		  int sacar(elemento e);
		  int cima();

};
#endif
