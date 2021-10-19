//---------------------------------------------------------------------------

#ifndef ColaSMH
#define ColaSMH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elemento="->elemento";
const string sig="->sig";
const string anterior="->ant";
class ColaSM
{
	private:
		   CSMemoria *mem;
		   int ini, fin,ant;
		   int siguiente(int e);
	public:
		  ColaSM();
          ColaSM(CSMemoria *m);
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
};
#endif
