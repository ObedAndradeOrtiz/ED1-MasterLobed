//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
using namespace std;
DiColaLista::DiColaLista()
{
 L= new ListaP();
}
bool DiColaLista::Vacia()
{
return L->vacia();
}
void DiColaLista::Poner(int E)
{
L->inserta(L->primero(),E);
}
void DiColaLista::Sacar( int &E)
{
E=L->recupera(L->fin());
L->suprime(L->fin());
}
int DiColaLista::Primero()
{
  return L->recupera(L->fin());
}
int DiColaLista::ultimo()
{
  int e;
  int numret;
  DiColaLista* aux = new DiColaLista();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
	if(Vacia())
	{
		numret=e;
	}
  }

  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
  return numret;

}
void DiColaLista::poner_frente(int E)
{
  int e;
  DiColaLista* aux = new DiColaLista();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
  }
  Poner(E);
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }

}
void DiColaLista::sacar_final(int &E)
{
  int e;
  DiColaLista* aux = new DiColaLista();
  while (!Vacia()) {
	Sacar(e);
	if(!Vacia())
	{
	   aux->Poner(e);
	}
	else
	{
		E=e;
	}
  }
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
}
string DiColaLista::mostrar() {
  string s = "DICOLALISTA \n+---+\n";
  int e;
  DiColaLista* aux = new DiColaLista();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
	s += "| "+to_string(e)+" |\n";
  }
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
  return  "\n"+s+"+---+\n\n";
}
