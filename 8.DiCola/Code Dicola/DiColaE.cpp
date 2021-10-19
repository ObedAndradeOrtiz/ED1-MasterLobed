//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DiColaSM::DiColaSM()
{
	 mem= new  CSMemoria();
	 ini=-1;
	 fin=-1;
}
DiColaSM::DiColaSM(CSMemoria *m)
{
   mem=m;
   ini=-1;
   fin=-1;
}
bool DiColaSM::Vacia()
{
	return ini==nulo;
}
void DiColaSM::Poner(int E)
{
   int aux= mem->New_Espacio("ant,elemento,sig");
	if(aux!=nulo)
	{
	   mem->Poner_dato(aux,elementoS,E);
	   mem->Poner_dato(aux,sigS,aux);
	   mem->Poner_dato(aux,anteriorS,nulo);
	   if(Vacia())
	   {
			ini=aux;
			fin=aux;
	   }
	   else
	   {
			mem->Poner_dato(ini,anteriorS,aux);
			mem->Poner_dato(fin,sigS,aux);
			mem->Poner_dato(aux,sigS,ini);
			if(fin!=ini)
			{
				mem->Poner_dato(fin,anteriorS,fin-3);
				mem->Poner_dato(aux,anteriorS,fin);
			}
            	else
			{
                	mem->Poner_dato(aux,anteriorS,fin);
			}
			fin=aux;
	   }
	}
}
void DiColaSM::Sacar( int &E)
{
   if(!Vacia())
   {
	   E=mem->obtener_dato(ini,elementoS);
	   int x=ini;
	   ini=mem->obtener_dato(ini,sigS);
	   mem->Delete_Espacio(x);
   }

}
int DiColaSM::Primero()
{
	 if(!Vacia())
	 {
		 return mem->obtener_dato(ini,elementoS);
	 }
}
int DiColaSM::ultimo()
{
  int e;
  int numret;
  DiColaSM* aux = new DiColaSM();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
	if(Vacia())
	{
		numret=e;
	}
  }

  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
  return numret;

}
void DiColaSM::poner_frente(int E)
{
  int e;
  DiColaSM* aux = new DiColaSM();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
  }
  Poner(E);
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }

}
void DiColaSM::sacar_final(int &E)
{
  int e;
  DiColaSM* aux = new DiColaSM();
  while (!Vacia()) {
	Sacar(e);
	if(!Vacia())
	{
       aux->Poner(e);
	}
	else
	{
        E=e;
    }
  }
  while (!aux->Vacia()) {
    aux->Sacar(e);
	Poner(e);
  }
}
string DiColaSM::mostrar() {
  string s = "DICOLASM \n+---+\n";
  int e;
  DiColaSM* aux = new DiColaSM();
  while (!Vacia()) {
	Sacar(e);
	aux->Poner(e);
	s += "| "+to_string(e)+" |\n";
  }
  while (!aux->Vacia()) {
	aux->Sacar(e);
	Poner(e);
  }
  return  "\n"+s+"+---+\n\n";
}
