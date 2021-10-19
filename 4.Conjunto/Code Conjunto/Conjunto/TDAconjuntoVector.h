//---------------------------------------------------------------------------

#ifndef TDAconjuntoVectorH
#define TDAconjuntoVectorH
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
const int max=10;
class ConjuntoV{
private:
	   int v[max];
	   int cant;
public:
	  ConjuntoV();
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
