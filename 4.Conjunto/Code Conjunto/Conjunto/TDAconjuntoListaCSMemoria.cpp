//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoListaCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConjuntoLM::ConjuntoLM(CSMemoria* m){
 Elem = new ListaSM(m);
 }

bool  ConjuntoLM::vacio (){
 return((Elem->Mostrarlongitud())==0);
 }

bool  ConjuntoLM::pertenece(int e){
 if(!Elem->vacia())
 {
	 int p=Elem->primero();
	 while(p!=nulo)
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
void  ConjuntoLM::inserta(int e){
 if(!pertenece(e))
 {
   Elem->inserta(Elem->primero(),e);
 }
 }
int  ConjuntoLM::cardinal(){
 return(Elem->Mostrarlongitud());
 }
int  ConjuntoLM::ordinal(int e){
 if(!Elem->vacia())
 {
	 int cont=0;
	 int p=Elem->primero();
	 while(p!=nulo)
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
void  ConjuntoLM::suprime(int e){
 if(pertenece(e))
 {
	int dir=nulo;
	int p=Elem->primero();
	while(p!=nulo)
	{
	   int ele=Elem->recupera(p);
	   if(e==ele)
	   {
		  dir=p;
	   }
	   p=Elem->siguiente(p);
	}
	if(dir!=nulo)
	{
	   Elem->suprime(dir);
	}
 }
 }
int  ConjuntoLM::muestrea(){
   int lug=rand()%(Elem->Mostrarlongitud());
   int dir=Elem->primero();
   int dirElem=nulo;
   for(int i=1; i< Elem->Mostrarlongitud(); i++)
   {
	 int cont=cont+1;
	 if(cont ==lug)
	 {
	   dirElem=dir;
	 }
	 dir=Elem->siguiente(dir);
   }
   return(Elem->recupera(dirElem));
}
void ConjuntoLM::To_Str()
{
  cout<<Elem->Mostrar()<<endl;
}
