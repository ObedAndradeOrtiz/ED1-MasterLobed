//---------------------------------------------------------------------------

#ifndef ListaVectorH
#define ListaVectorH
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
typedef int direccion;
const int maxVect=10;
class ListaVector
{
 private:
	 int elementos[maxVect];
	 int longi;
 public:
  ListaVector();
  direccion fin();
  direccion primero();
  direccion anterior(direccion);
  direccion siguiente(direccion);
  bool vacia();
  int recupera(direccion);
  int longitud();
  void inserta(direccion p, int elem);
  void inserta_primero(int e);
  void inserta_ultimo(int e);
  void suprime(direccion);
  void modifica(direccion, int e);
  string toStr();

};
#endif
