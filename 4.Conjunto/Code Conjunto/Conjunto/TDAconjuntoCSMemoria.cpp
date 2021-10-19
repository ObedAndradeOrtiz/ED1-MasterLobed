//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include<stdlib.h>
#include<time.h>
ConjuntoSM::ConjuntoSM()
{
	mem=new CSMemoria();
	cant=0;
    ptrConj=nulo;

}
ConjuntoSM::ConjuntoSM(CSMemoria* m){
cant=0;
ptrConj=nulo;
mem=m;
}
bool ConjuntoSM::vacio (){
return(cant==0);
}
bool ConjuntoSM::pertenece(int e){
int pc=ptrConj;
while(pc!=nulo)
{
  if(mem->obtener_dato(pc,"->dato")==e)
  {
	  return true;
  }
  pc=mem->obtener_dato(pc, "->sig");
}
return false;
}
void ConjuntoSM::inserta(int e){
if(vacio())
{
	int dir=mem->New_Espacio("dato,sig");
	if(dir!=nulo)
	{
	   mem->Poner_dato(dir,"->dato",e);
	   mem->Poner_dato(dir,"->sig",ptrConj);
	   ptrConj=dir;
       cant++;
	}
}
else
{
	if(!pertenece(e))
	{
		int dir=mem->New_Espacio("dato,sig");
		if(dir!=nulo)
		{
			mem->Poner_dato(dir,"->dato",e);
			mem->Poner_dato(dir,"->sig",ptrConj);
			ptrConj=dir;
			cant++;
		}
	}
}
}
int ConjuntoSM::cardinal(){
return cant;
}
int ConjuntoSM::ordinal(int e){
int pc=ptrConj;
while(pc!=nulo)
{
	int cont=cont+1;
	if(mem->obtener_dato(pc,"->dato")==e)
	{
	  return cont;
	}
	pc=mem->obtener_dato(pc,"->sig");
}
}
void ConjuntoSM::suprime(int e) {
 if (pertenece(e)) {
  int dir;
  if (e == mem->obtener_dato(ptrConj, "->dato")) {
   dir = ptrConj;
   ptrConj = mem->obtener_dato(ptrConj, "->sig");
  }
  else {
   int pc = ptrConj;
   int ant;
   while (pc != nulo) {
	if (e == mem->obtener_dato(pc, "->dato")) {
	 dir = pc;
	 break;
	}
	ant = pc;
	pc = mem->obtener_dato(pc, "->sig");
   }
   int pc_sig = mem->obtener_dato(pc, "->sig");
   mem->Poner_dato(ant, "->sig", pc_sig);
   mem->Poner_dato(pc, "->sig", nulo);
  }
  cant--;
  mem->Delete_Espacio(dir);
 }
}
int ConjuntoSM::muestrea(){
srand(time(NULL));
int lugBus=1+rand()%(cardinal());
int lug=0;
int pc=ptrConj;
while(pc!=nulo)
{
	lug=lug+1;
	if(lugBus==lug)
	{
	   return(mem->obtener_dato(pc,"->dato"));
	}
    pc=mem->obtener_dato(pc,"->sig");
}
}
void ConjuntoSM::To_Str(){
//mem->mostrar_memoria();
string s = "C{";
 int p = ptrConj;
 int c = 0;
 while (p != nulo) {
  c++;
  int ele = mem->obtener_dato(p, "->dato"); // p->dato;
  s += to_string(ele);
  if (c < cant)
   s += ",";
  p = mem->obtener_dato(p, "->sig"); // p->sig;
 }
 cout<<s + "}"<<endl;
}
