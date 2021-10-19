//---------------------------------------------------------------------------

#ifndef DiColaDesH
#define DiColaDesH
#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
const int maximo=10;
class DiColaDes
{
	private:
		   int v[maximo];
		   int ini, fin;
	public:
		  DiColaDes();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int  Primero();
		  int  ultimo();
		  void poner_frente(int E);
		  void sacar_final(int &E);
          string mostrar();

};
#endif
