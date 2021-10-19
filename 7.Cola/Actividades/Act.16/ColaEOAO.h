#ifndef ColaEOAOH
#define ColaEOAOH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elemento="->elementoC";
const string sig="->sigC";
class ColaEOAO
{
	private:
		   CSMemoria *mem;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  ColaEOAO();
          ColaEOAO(CSMemoria *m);
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  string mostrar();
};
#endif