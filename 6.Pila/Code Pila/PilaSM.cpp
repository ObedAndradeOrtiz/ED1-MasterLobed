//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 pilaSM::pilaSM(CSMemoria *m){
	mem=m;
	tope=-1;
 }
 bool  pilaSM::vacia(){
   return tope==-1;
 }
 void  pilaSM::meter(Elemento e){
 int aux=mem->New_Espacio("elemento,sig");
 if(aux!=nulo)
 {
	 mem->Poner_dato(aux,"->elemento",e);
	 mem->Poner_dato(aux,"->sig",e);
	 tope=aux;
 }
 }
 void  pilaSM::sacar(Elemento &e){
 if(!vacia())
 {
	 int x=tope;
	 e=mem->obtener_dato(tope,"->elemento");
	 tope=mem->obtener_dato(tope,"->sig");
	 mem->Delete_Espacio(x);
 }
 }
 Elemento  pilaSM::cima(){
 if(!vacia())
 {
	 return mem->obtener_dato(tope,"->elemento");
 }
 }
