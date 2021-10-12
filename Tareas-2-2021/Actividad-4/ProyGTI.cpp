#include <iostream>
#include <string>
#include "CSMemoriaGTI.h"
#include <stdio.h>
using namespace std;
int main()
{
	CSMemoriaGTI MiMemGTI;
	int x = MiMemGTI.New_Espacio("uno");
	MiMemGTI.Poner_dato(x, "->uno", 100);
	int y = MiMemGTI.New_Espacio("dos");
	MiMemGTI.Delete_Espacio(x);
	int z = MiMemGTI.New_Espacio("gonzalo,tarqui,ignacio");
	MiMemGTI.Poner_dato(z, "->gonzalo", MiMemGTI.obtener_dato(z, "->gonzalo") + 77);
	MiMemGTI.mostrar_memoria();
	return 0;
}


