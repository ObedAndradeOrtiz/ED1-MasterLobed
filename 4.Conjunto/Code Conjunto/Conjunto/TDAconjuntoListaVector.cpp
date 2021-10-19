//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoListaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cstdlib>
ConjuntoLV::ConjuntoLV(){
 Elem = new ListaVector();
 cant=0;
 }
bool  ConjuntoLV::vacío (){
 return(Elem->longitud()==0);
 }
bool  ConjuntoLV::pertenece(int e){
 if(!Elem->vacia())
 {
	 int p=Elem->primero();
     while(p<cant)
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
void  ConjuntoLV::inserta(int e){
 if(!pertenece(e))
 {
Elem->inserta(Elem->primero(),e);
cant++;
 }
 }
int  ConjuntoLV::cardinal(){
 return(Elem->longitud());
 }
int  ConjuntoLV::ordinal(int e){
 if(!Elem->vacia())
 {
	 int cont=0;
	 int p=Elem->primero();
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
void  ConjuntoLV::suprime(int e){
 if(pertenece(e))
 {
	int dir=-1;
	int p=Elem->primero();
	while(p<cant)
	{
	   int ele=Elem->recupera(p);
	   if(e==ele)
	   {
		  dir=p;
	   }
	   p=Elem->siguiente(p);
	}
	if(dir!=-1)
	{
	   Elem->suprime(dir);
	   cant--;
	}
 }
 }
int  ConjuntoLV::muestrea(){
   int lug=rand()%(Elem->longitud());
   int dir=Elem->primero();
   int dirElem=NULL;
   for(int i=1; i< Elem->longitud(); i++)
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
void ConjuntoLV::To_Str()
{
  int aux=Elem->primero();
  cout<<"C<";
  for(int i=0; i<cant; i++){
	cout<<Elem->recupera(i)<<",";
	aux=Elem->siguiente(i);
  }
  cout<<">"<<endl;
}
