#include <stdio.h>
#include <iostream>
#include "CSMemoria.h"
#include "ColaPrioridadEOAO.h"
int main()
{
 int elem;
 CSMemoria *m= new CSMemoria();
 ColaPrioridadEOAO* PEOAO=new ColaPrioridadEOAO(m);
 PEOAO->poner(10,1);
 PEOAO->poner(200,2);
 PEOAO->poner(1000,3);
 PEOAO->poner(300,2);
 PEOAO->Asignar_frecuencia_Prioridad(2,1);
 PEOAO->Asignar_frecuencia_Prioridad(2,2);
 PEOAO->Asignar_frecuencia_Prioridad(1,3);
 m->mostrar_memoria();
 PEOAO->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 PEOAO->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 PEOAO->sacar(elem);
 cout<<"Elemento= "<<elem<<endl;
 m->mostrar_memoria();
 return 0;
}