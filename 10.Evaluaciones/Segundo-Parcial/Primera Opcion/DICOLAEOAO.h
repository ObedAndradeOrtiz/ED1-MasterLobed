//---------------------------------------------------------------------------

#ifndef DICOLAEOAOH
#define DICOLAEOAOH
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const string elementoS="->elemento";
const string sigS="->sig";
const string anteriorS="->ant";
class DiColaEOAO
{
	private:
		   CSMemoria *mem;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  DiColaEOAO();
		  DiColaEOAO(CSMemoria *m);
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