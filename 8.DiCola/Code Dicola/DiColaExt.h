//---------------------------------------------------------------------------

#ifndef DiColaExtH
#define DiColaExtH
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
const int maxim=10;
class DiColaExtrem
{
	private:
		   char v[maxim];
		   int ini, fin;
		   int siguiente(int e);
	public:
		  DiColaExtrem();
		  bool Vacia();
		  void Poner(char E);
		  void Sacar( char &E);
		  char Primero();
		  void mostrar();
		  char  ultimo();
		  void poner_frente(char E);
		  void sacar_final(char &E);
		  string mostrarD();
};
#endif
