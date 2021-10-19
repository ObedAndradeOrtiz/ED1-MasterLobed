//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cstdlib>
#include<stdlib.h>
#include<time.h>
Conjunto::Conjunto(){
 Elem = new ListaP();
 }
bool  Conjunto::vacío (){
 return(Elem->longitud()==0);
 }
bool  Conjunto::pertenece(int e){
 if(!Elem->vacia())
 {
	 NodoL* p=Elem->primero();
	 while(p!=NULL)
	 {
	   int ele=Elem->recupera(p);
	   if(e==ele)
	   {
		 return(true);
	   }
	   p=Elem->siguiente(p);
	 }
 }
 return(false);
 }
void  Conjunto::inserta(int e){
 if(!pertenece(e))
 {
Elem->inserta(Elem->primero(),e);
 }
 }
int  Conjunto::cardinal(){
 return(Elem->longitud());
 }
int  Conjunto::ordinal(int e){
 if(!Elem->vacia())
 {
	 int cont=0;
	 NodoL* p=Elem->primero();
	 while(p!=NULL)
	 {
	   cont++;
	   int ele=Elem->recupera(p);
	   if(e==ele)
	   {
		 return cont;
	   }
	   p=Elem->siguiente(p);
	 }
 }
 }
void  Conjunto::suprime(int e){
 if(pertenece(e))
 {
	NodoL* dir=NULL;
	NodoL *p=Elem->primero();
	while(p!=NULL)
	{
	   int ele=Elem->recupera(p);
	   if(e==ele)
	   {
		  dir=p;
	   }
	   p=Elem->siguiente(p);
	}
	if(dir!=NULL)
	{
	   Elem->suprime(dir);
	}
 }
 }
int  Conjunto::muestrea(){
   srand(time(NULL));
   int lug=rand()%(cardinal());
   int cont=0;
   NodoL* dir=Elem->primero();
   NodoL* dirElem=NULL;
   for(int i=0; i< Elem->longitud(); i++)
   {

	 if(cont ==lug)
	 {
	   dirElem=dir;
	 }
	  cont++;
	 dir=Elem->siguiente(dir);
   }
   if(dirElem!=NULL)
   {
   return(Elem->recupera(dirElem));
   }

}

void Conjunto::To_Str()
{
  NodoL* aux=Elem->primero();
  cout<<"C<";
  while(aux!=NULL)
  {
	cout<<Elem->recupera(aux)<<",";
	aux=Elem->siguiente(aux);
  }
  cout<<">"<<endl;
}
