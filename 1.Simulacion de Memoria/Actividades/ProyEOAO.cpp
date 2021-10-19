#include <iostream>
#include <string>
#include "CSMemoriaEOAO.h"
using namespace std;

int main()
{   
    CSMemoriaEOAO MiMemEOAO;
    int x=MiMemEOAO.New_Espacio("uno");
    MiMemEOAO.Poner_dato(x,"->uno",100);
    int y=MiMemEOAO.New_Espacio("dos");
    MiMemEOAO.Delete_Espacio(x);
    int z=MiMemEOAO.New_Espacio("Esrom,Obed,Andrade,Ortiz");
    MiMemEOAO.Poner_dato(z,"->Esrom",MiMemEOAO.obtener_dato(z,"->Esrom")+5);
    MiMemEOAO.mostrar_memoria();
    return 0;
}