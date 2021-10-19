//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
using namespace std;
ColaLista::ColaLista()
{
 L= new ListaP();
}
bool ColaLista::Vacia()
{
return L->vacia();
}
void ColaLista::Poner(int E)
{
L->inserta(L->primero(),E);
}
void ColaLista::Sacar( int &E)
{
E=L->recupera(L->fin());
L->suprime(L->fin());
}
int ColaLista::Primero()
{
  return L->recupera(L->fin());
}
