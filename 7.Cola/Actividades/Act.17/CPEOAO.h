//---------------------------------------------------------------------------

#ifndef CPEHAH
#define CPEOAOH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elementoC="->elementoC";
const string sigC="->sigC";
using namespace std;
class CPEOAO
{
	private:
		   CSMemoria *mem;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  CPEOAO();
		  CPEOAO(CSMemoria *m);
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  string mostrar();
};
#endif