//---------------------------------------------------------------------------
#pragma hdrstop

#include "ColaPrioridadEHA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
colaPrioridadEHA::colaPrioridadEHA()
{
colaAct=0;
cant=0;
vc= new CPEHA*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPEHA();
		vf[i] = 1;
	}
}
colaPrioridadEHA::colaPrioridadEHA(CSMemoria *m)
{
colaAct=0;
cant=0;
vc= new CPEHA*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPEHA(m);
		vf[i] = 1;
	}
}

bool colaPrioridadEHA::vacia()
{
for (int i = 0; i < MAX; i++) {
		if (!vc[i]->Vacia())
			return false;
	}
	return true;
}
int colaPrioridadEHA::primero()
{
   if (vacia())
		cout << "Cola Vacia" << endl;
	else {
		int colaInicio = colaAct;
		bool termino = false;
		while (!termino) {
			if (!vc[colaAct]->Vacia() && cant < vf[colaAct])
				return vc[colaAct]->Primero();
			colaAct = (colaAct + 1) % MAX;
			cant = 0;
			if (colaAct == colaInicio)
				termino = true;
		}
	}
}
void colaPrioridadEHA::poner( int E, int prioridad)
{
  vc[prioridad]->Poner(E);
}
void colaPrioridadEHA::Asignar_frecuencia_Prioridad( int frec, int prioridad)
{
	 vf[prioridad] = frec;
}
void colaPrioridadEHA::sacar(int &E )
{
if (!vacia()) {
		if (!vc[colaAct]->Vacia()) {
			if (cant < vf[colaAct]) {
				cant++;
				vc[colaAct]->Sacar(E);
				if (cant == vf[colaAct]) {
					colaAct = (colaAct + 1) % MAX;
					cant = 0;
				}
			}
		}
		else {
			colaAct = (colaAct + 1) % MAX;
			cant = 0;
			sacar(E);
		}
	}
}
