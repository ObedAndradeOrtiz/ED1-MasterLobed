//---------------------------------------------------------------------------

#ifndef ColaPrioridadH
#define ColaPrioridadH
#include "ColaEOAO.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const int MAX=10;
class colaPrioridad
{
private:
 ColaEOAO** vc;
 int *vf;
 int colaAct;
 int cant;
 public:
 colaPrioridad();
 colaPrioridad(CSMemoria *m);
 bool vacia();
 int primero();
 void poner( int E, int prioridad);
 void Asignar_frecuencia_Prioridad( int frec, int prioridad);
 void sacar(int &E );
};
#endif
