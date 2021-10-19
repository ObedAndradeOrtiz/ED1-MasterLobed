//---------------------------------------------------------------------------

#pragma hdrstop

#include "pilaDicola.h"
#include "DiColaExt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
pilaDicola::pilaDicola(){

tope=0;
}
bool pilaDicola::vacia(){
return tope==0;
}
void pilaDicola::meter(elemento e){
if(tope==max)
{
   return;
}
tope++;
}

int pilaDicola::sacar(elemento e)
{
if(!vacia())
	  {

		  tope--;
	  }
return e;

}

int pilaDicola::cima(){

}