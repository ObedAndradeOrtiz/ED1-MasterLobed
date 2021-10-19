#include <stdio.h>
#include <iostream>
#include "CSMemoria.h"
#include "PilaEOAO.h"
int main()
{
    CSMemoria * m=new CSMemoria();
	PilaEOAO * pEOAO=new  PilaEOAO(m);
	int elem;
	int x=m->New_Espacio("ESROM OBED,ANDRADE,ORTIZ");
	m->Poner_dato(x,"->ANDRADE",666);
	pEOAO->poner(10);
	pEOAO->poner(20);
	m->mostrar();
	pEOAO->mostrar();
	pEOAO->sacar(elem);
	cout<<endl<<"ELEM="<<elem<<endl<<endl;  //Puse elem para diferenciar la pila con el elemento
	m->mostrar();
	pEOAO->mostrar();
	return 0;
}