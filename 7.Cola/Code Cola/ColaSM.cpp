//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ColaSM::ColaSM()
{
	 mem= new  CSMemoria();
	 ini=-1;
	 fin=-1;
}
ColaSM::ColaSM(CSMemoria *m)
{
   mem=m;
   ini=-1;
   fin=-1;
}
bool ColaSM::Vacia()
{
	return ini==nulo;
}
void ColaSM::Poner(int E)
{
int aux= mem->New_Espacio("ant,elemento,sig");
	if(aux!=nulo)
	{
	   mem->Poner_dato(aux,elemento,E);
	   mem->Poner_dato(aux,sig,aux);
	   mem->Poner_dato(aux,anterior,nulo);
	   if(Vacia())
	   {
			ini=aux;
			ant=aux;
			fin=aux;
	   }
	   else
	   {
			mem->Poner_dato(ini,anterior,aux);
			mem->Poner_dato(fin,sig,aux);
            mem->Poner_dato(aux,sig,ini);
			if(fin!=ini)
			{
				mem->Poner_dato(fin,anterior,ant-3);
				mem->Poner_dato(aux,anterior,ant);
			}
			else
			{
                	mem->Poner_dato(aux,anterior,ant);
            }
            ant=aux;
			fin=aux;
	   }
	}
}
void ColaSM::Sacar( int &E)
{
   if(!Vacia())
   {
	   E=mem->obtener_dato(ini,elemento);
	   int x=ini;
	   ini=mem->obtener_dato(ini,sig);
	   mem->Delete_Espacio(x);
   }

}
int ColaSM::Primero()
{
	 if(!Vacia())
	 {
		 return mem->obtener_dato(ini,elemento);
     }
}
