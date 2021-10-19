//---------------------------------------------------------------------------

#ifndef TDAconjuntoPunteroH
#define TDAconjuntoPunteroH
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
struct NodoC
{
	int dato;
	NodoC* sig;
};
class ConjuntoP
{
	  private:
			int cant;
            NodoC* ptrConj;
	  public:
      ConjuntoP();
	  bool vacio ();
	  bool pertenece(int e);
	  void inserta(int e);
	  int cardinal();
	  int ordinal(int e);
	  void suprime(int e);
	  int muestrea();
	  void To_Str();
};
#endif
