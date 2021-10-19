//---------------------------------------------------------------------------

#ifndef DiColaListaH
#define DiColaListaH
//---------------------------------------------------------------------------
#include "ListaPuntero.h"
class  DiColaLista
{
	private:
			ListaP* L;


	public:
		  DiColaLista();
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
