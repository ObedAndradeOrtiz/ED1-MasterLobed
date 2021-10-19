//---------------------------------------------------------------------------

#pragma hdrstop

#include "pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

pila::pila(){
topeOPDR=max-1;
for(int i=max-1; i>=0; i--)
{
	VOPDR[i]=0;
}
}
bool pila::vacia(){
return topeOPDR==max;
}
void pila::meter(elemento e){
	for (int i=max-1; i > 0; i--) {
	   VOPDR[i-1]=VOPDR[i];
	}
	VOPDR[max-1]=e;

}
void pila::sacar(elemento &e)
{
if(!vacia())
	  {
		e=VOPDR[topeOPDR+1];
	  }
return ;
}

int pila::cima(){
int num;
num=VOPDR[topeOPDR];
return num;
}
