#include <iostream>
#include <string>
#include "GITCSMemoria.h"
#include "ListaSM.h"
#include <stdio.h>
using namespace std;
int main()
{
	GITCSMemoria *MiMemGIT= new GITCSMemoria();
	ListaSM* LGIT= new ListaSM(MiMemGIT);
	int z = MiMemGIT->New_Espacio("GONZALO,IGNACIO,TARQUI");
	MiMemGIT->Poner_dato(z, "->GONZALO",MiMemGIT->obtener_dato(z,"->GONZALO")+2);
	LGIT->inserta_primero(100);
	LGIT->inserta_ultimo(200);
	LGIT->inserta(LGIT->fin(),150);
	MiMemGIT->mostrar_memoria();

	return 0;
}