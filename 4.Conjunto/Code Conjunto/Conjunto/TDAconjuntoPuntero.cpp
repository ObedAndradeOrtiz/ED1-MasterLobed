//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include<stdlib.h>
#include<time.h>
ConjuntoP::ConjuntoP(){
cant=0;
ptrConj=new NodoC;
}
bool ConjuntoP::vacio (){
return(cant==0);
}
bool ConjuntoP::pertenece(int e){
bool resp=false;
NodoC* aux=ptrConj;
while(aux!=NULL)
{
	if(aux->dato==e)
	{
		return true;
	}
	aux=aux->sig;
}
}

void ConjuntoP::inserta(int e){
NodoC* aux=new NodoC;
if(vacio())
{
	 ptrConj->dato=e;
	 ptrConj->sig=NULL;
     cant++;
}
else
{
	if(!this->pertenece(e)){
	aux->dato=e;
	aux->sig=ptrConj;
    ptrConj=aux;
    cant++;
	}
}

}
int ConjuntoP::cardinal(){
return(cant);
}
int ConjuntoP::ordinal(int e){
if(vacio())
{
	NodoC *aux=ptrConj;
	while(aux!=NULL)
	{
	 int cont=cont+1;
	  if(aux->dato==e)
	  {
		return cont;
	  }
	}
}
return 0;
}

NodoC* Delete(NodoC * p, NodoC* ptrConj)
{
  NodoC* aux=NULL;
  if(p==ptrConj)
  {
	 return ptrConj->sig;
  }
  else
  {
	  while(ptrConj!=NULL)
	  {
		if(p==ptrConj)
		{
		   p=p->sig;
		   while(p!=NULL)
		   {
			 NodoC* aux1=new NodoC;
			 aux1->dato=p->dato;
			 aux1->sig=aux;
			 aux=aux1;
             p=p->sig;
		   }
		   NodoC* cambiar=NULL;
		   while(aux!=NULL)
		   {
			   NodoC* aux2=new NodoC;
			   aux2->dato=aux->dato;
			   aux2->sig=cambiar;
               cambiar=aux2;
			   aux=aux->sig;
           }

		   ptrConj=NULL;
		   return cambiar;
		}
		NodoC* nuevo=new NodoC;
		nuevo->dato=ptrConj->dato;
		nuevo->sig=aux;
		aux=nuevo;

		ptrConj=ptrConj->sig;
	  }

  }

}
void ConjuntoP::suprime(int e){
 if(pertenece(e))
 {
	NodoC* dir=NULL;
	NodoC *p=ptrConj;
	while(p!=NULL)
	{
	   int ele=p->dato;
	   if(e==ele)
	   {
		  dir=p;
	   }
	   p=p->sig;
	}
	if(dir!=NULL)
	{
	   ptrConj=Delete(dir,ptrConj);
	   cant--;
	}
 }

}
int ConjuntoP::muestrea(){
srand(time(NULL));
int lug=rand()%(cardinal());
 int cont=0;
}

void ConjuntoP::To_Str(){
NodoC* aux=ptrConj;
cout<<"CP<";
while(aux!=NULL)
{
  cout<<aux->dato<<",";
  aux=aux->sig;
}
cout<<">";
}
