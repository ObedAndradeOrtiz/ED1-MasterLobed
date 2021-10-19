//---------------------------------------------------------------------------

#ifndef ColaPrioridadEHAH
#define ColaPrioridadEHAH
#include "CPEHA.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const int MAX=10;
class colaPrioridadEHA
{
private:
 CPEHA** vc;
 int *vf;
 int colaAct;
 int cant;
 public:
 colaPrioridadEHA();
 colaPrioridadEHA(CSMemoria *m);
 bool vacia();
 int primero();
 void poner( int E, int prioridad);
 void Asignar_frecuencia_Prioridad( int frec, int prioridad);
 void sacar(int &E );
};
#endif
