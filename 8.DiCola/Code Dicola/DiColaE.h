//---------------------------------------------------------------------------

#ifndef DiColaEH
#define DiColaEH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elementoS="->elemento";
const string sigS="->sig";
const string anteriorS="->ant";
class DiColaSM
{
	private:
		   CSMemoria *mem;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  DiColaSM();
          DiColaSM(CSMemoria *m);
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  int  ultimo();
		  void poner_frente(int E);
		  void sacar_final(int &E);
          string mostrar();
};
#endif
