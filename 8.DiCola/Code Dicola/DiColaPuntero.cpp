//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DiColaP::DiColaP()
{
  cola=NULL;
}
bool DiColaP::Vacia()
{
return cola==NULL;
}
void DiColaP::Poner(int E)
{
  if(Vacia())
  {
	  cola=new NodoC();
	  cola->dato=E;
	  cola->sig=NULL;
  }
  else
  {
	  NodoC* aux=new NodoC();
	  aux->dato=E;
	  aux->sig=cola;
	  cola=aux;
  }
}
void DiColaP::Sacar( int &E)
{
 NodoC* principal=NULL;
 if(!Vacia())
 {
  if(cola->sig==NULL)
	{
	  E=cola->dato;
	  cola=cola->sig;
	}
  else
   {
 while(cola->sig!=NULL)
 {
	NodoC *aux=new NodoC;
	if(cola->sig!=NULL)
	{
	aux->dato=cola->dato;
	aux->sig=principal;
	principal=aux;
    }
	cola=cola->sig;
	 if(cola->sig==NULL)
	{
	  E=cola->dato;
	}

 }
 cola= NULL;
 while(principal!=NULL)
 {
   NodoC* aux= new NodoC;
   aux->dato=principal->dato;
   aux->sig=cola;
   cola=aux;

   principal=principal->sig;
 }
}
}
}
int DiColaP::Primero()
{
  int e=0;
  Sacar(e);

  return e;
}

int DiColaP::ultimo()
{
  int e;
  int numret;
  DiColaP* aux = new DiColaP();
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
void DiColaP::poner_frente(int E)
{
  int e;
  DiColaP* aux = new DiColaP();
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
void DiColaP::sacar_final(int &E)
{
  int e;
  DiColaP* aux = new DiColaP();
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
string DiColaP::mostrarP() {
  string s = "DiColaP \n+---+\n";
  int e;
  DiColaP* aux = new DiColaP();
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
