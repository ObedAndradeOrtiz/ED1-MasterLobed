

#include <iostream>
#include <string.h>
#include "Polinomio.h"
using namespace std;
int main()
{
    Polinomio* poli = new Polinomio();
    poli->poner_termino(2, 5);
    poli->AsignarCoeficiente(8,5);
    poli->mostrar();
    return 0;
}

