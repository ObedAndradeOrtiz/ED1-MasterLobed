//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ColaP::ColaP()
{
  cola=NULL;
}
bool ColaP::Vacia()
{
return cola==NULL;
}
void ColaP::Poner(int E)
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
void ColaP::Sacar( int &E)
{
  NodoC *aux=cola;
  NodoC* principal= NULL;
   while(aux->sig!=NULL)
   {
	  NodoC* aux2= new NodoC();
	  aux2->dato=aux->dato;
	  aux->sig=principal;
	  principal=aux;
	  aux=aux->sig;
   }
   E=aux->dato;
   cola=NULL;
   while(principal!=NULL)
   {
	   NodoC* aux2= new NodoC();
	   aux2->dato=principal->dato;
	   aux2->sig=cola;
	   cola=aux2;
   }

}
int ColaP::Primero()
{
   NodoC *aux=cola;
   while(aux->sig!=NULL){
   aux=aux->sig;
   }
   return aux->dato;
}
