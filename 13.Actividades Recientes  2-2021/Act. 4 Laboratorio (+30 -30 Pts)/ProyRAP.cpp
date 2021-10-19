#include <iostream>
#include <string>
#include "CSMemoriaRAP.h"
#include <stdio.h>
using namespace std;
int main()
{
	CSMemoriaRAP MiMemRAP;
	int x = MiMemRAP.New_Espacio("uno");
	MiMemRAP.Poner_dato(x, "->uno", 100);
	int y = MiMemRAP.New_Espacio("dos");

	int z = MiMemRAP.New_Espacio("Ruben,Andrade,Porcel");
	MiMemRAP.Delete_Espacio(x);
	MiMemRAP.Poner_dato(z, "->Ruben", MiMemRAP.obtener_dato(z, "->Ruben") + 77);
	MiMemRAP.mostrar_memoria();

	return 0;
}