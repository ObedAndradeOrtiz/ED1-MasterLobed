//---------------------------------------------------------------------------

#ifndef ColaListaH
#define ColaListaH
//---------------------------------------------------------------------------
#include "ListaPuntero.h"
class  ColaLista
{
	private:
			ListaP* L;


	public:
		  ColaLista();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();

};
#endif
