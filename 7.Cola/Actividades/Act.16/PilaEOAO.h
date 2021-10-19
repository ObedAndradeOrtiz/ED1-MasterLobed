#ifndef PilaEOAOH
#define PilaEOAOH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
typedef int Elemento;
class PilaEOAO
{
   private:
		  CSMemoria * mem;
		  int tope;
   public:
          PilaEOAO();
		  PilaEOAO(CSMemoria *m);
		  bool vacia();
		  void meter(Elemento e);
		  void sacar(Elemento &e);
		  Elemento cima();
		  string mostrar();
};
#endif