#include "ColaPrioridadEOAO.h"

ColaPrioridadEOAO::ColaPrioridadEOAO()
{
colaAct=0;
cant=0;
vc= new CPEOAO*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPEOAO();
		vf[i] = 1;
	}
}
ColaPrioridadEOAO::ColaPrioridadEOAO(CSMemoria *m)
{
colaAct=0;
cant=0;
vc= new CPEOAO*[MAX];
vf = new int[MAX];
for (int i = 0; i < MAX; i++) {
		vc[i] = new CPEOAO(m);
		vf[i] = 1;
	}
}

bool ColaPrioridadEOAO::vacia()
{
	int cont=0;
	for (int i = 0; i < MAX; i++) {

		if (vc[i]->Vacia())
		{
			cont++;
		}
	}
	if(cont==MAX)
	{
        cout<<"LA Cola ESTA VACIA";
		return true;
	}
	else
	{
	return false;

	}
}
int ColaPrioridadEOAO::primero()
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
void ColaPrioridadEOAO::poner( int E, int prioridad)
{
  vc[prioridad]->Poner(E);
}
void ColaPrioridadEOAO::Asignar_frecuencia_Prioridad( int frec, int prioridad)
{
	 vf[prioridad] = frec;
}
void ColaPrioridadEOAO::sacar(int &E )
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