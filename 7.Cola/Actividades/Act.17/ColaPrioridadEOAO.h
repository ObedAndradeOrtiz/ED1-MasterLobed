//---------------------------------------------------------------------------

#ifndef ColaPrioridadEOAOH
#define ColaPrioridadEOAOH
#include "CPEOAO.h"
#include "CSMemoria.h"
//---------------------------------------------------------------------------
const int MAX=10;
class ColaPrioridadEOAO
{
private:
 CPEOAO** vc;
 int *vf;
 int colaAct;
 int cant;
 public:
 ColaPrioridadEOAO();
 ColaPrioridadEOAO(CSMemoria *m);
 bool vacia();
 int primero();
 void poner( int E, int prioridad);
 void Asignar_frecuencia_Prioridad( int frec, int prioridad);
 void sacar(int &E );
};
#endif