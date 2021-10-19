//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaLista.h"
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
 pilaL::pilaL()
{
 L=new ListaP();
}

bool pilaL::vacia(){
return (L==NULL);
}

void pilaL::meter(elemento e)
{
L->inserta(L->primero(),e);
}

elemento pilaL::sacar(elemento e)
{
	e=L->recupera(L->primero());
	L->suprime(L->primero());
	return e;
}

int pilaL::cima(){
	return L->recupera(L->primero());
}