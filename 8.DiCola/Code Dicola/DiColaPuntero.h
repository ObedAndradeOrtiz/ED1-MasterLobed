//---------------------------------------------------------------------------

#ifndef DiColaPunteroH
#define DiColaPunteroH
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
struct NodoC{
int dato;
NodoC* sig;
};
class DiColaP
{
   private:
		   NodoC* cola;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  DiColaP();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  int  ultimo();
		  void poner_frente(int E);
		  void sacar_final(int &E);
		  string mostrarP();
};
#endif
