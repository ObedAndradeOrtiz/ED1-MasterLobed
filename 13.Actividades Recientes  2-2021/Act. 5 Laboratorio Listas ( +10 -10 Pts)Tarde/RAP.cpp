#include <iostream>
#include <string>
#include "RAPCSMemoria.h"
#include "ListaSM.h"
#include <stdio.h>
using namespace std;
int  main ()
{
	RAPCSMemoria* MiMemRAP = new  RAPCSMemoria ();
	ListaSM * LRAP = new  ListaSM (MiMemRAP);
	int z = MiMemRAP->New_Espacio ( "RUBEN,ANDRADE,PORCEL" );
	MiMemRAP->Poner_dato (z, "->RUBEN" , MiMemRAP-> obtener_dato (z,"->RUBEN" ) + 2 );
	LRAP->inserta_primero (100);
	LRAP->inserta_ultimo (200);
	LRAP->inserta(LRAP->fin(),150);
	MiMemRAP-> mostrar_memoria ();
}