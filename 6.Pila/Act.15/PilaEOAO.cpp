#include "PilaEOAO.h"
#include <iostream>
using namespace std;
PilaEOAO::PilaEOAO(CSMemoria * m)
{
 L=new ListaSM(m);
}

bool PilaEOAO::vacia(){
return (L->Mostrarlongitud()==0);
}

void PilaEOAO::poner(elemento e)
{
if(vacia())
{
 L->inserta_primero(e);
 return;
}else
{
L->inserta_ultimo(e);

}
}

elemento PilaEOAO::sacar(elemento &e)
{
	e=L->recupera(L->fin());
	L->suprime(L->fin());
	return e;
}

int PilaEOAO::cima(){
	return L->recupera(L->fin());
}
void PilaEOAO::mostrar()
{
 int num=L->fin();
 int cont=L->Mostrarlongitud();
 while(cont>0)
 {
	 cout<<L->recupera(num)<<endl;
	 num=L->anterior(num);
     cont--;
 }
}