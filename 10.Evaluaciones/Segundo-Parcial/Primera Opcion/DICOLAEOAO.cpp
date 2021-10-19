//---------------------------------------------------------------------------

#pragma hdrstop

#include "DICOLAEOAO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DiColaEOAO::DiColaEOAO()
{
	 mem= new  CSMemoria();
	 ini=-1;
	 fin=-1;
}
DiColaEOAO::DiColaEOAO(CSMemoria *m)
{
   mem=m;
   ini=-1;
   fin=-1;
}
bool DiColaEOAO::Vacia()
{
	return ini==nulo;
}
void DiColaEOAO::Poner(int E)
{
 int aux= mem->New_Espacio("ant,elemento,sig");
	if(aux!=nulo)
	{
	   mem->Poner_dato(aux,elementoS,E);
	   mem->Poner_dato(aux,sigS,aux);
	   mem->Poner_dato(aux,anteriorS,aux);
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
void DiColaEOAO::Sacar( int &E)
{
 if (!Vacia()) {
		E = mem->obtener_dato(ini, elementoS); // ini->elemento;
		int x = ini;
		if (ini == fin) {
			ini = nulo;
			fin = nulo;
		}
		else {
			ini = mem->obtener_dato(ini, sigS); // ini->sig;
			mem->Poner_dato(ini, anteriorS,fin);
			mem->Poner_dato(fin, sigS,ini);

		}
		mem->Delete_Espacio(x);
	}

}
int DiColaEOAO::Primero()
{
	 if(!Vacia())
	 {
		 return mem->obtener_dato(ini,elementoS);
	 }
}
int DiColaEOAO::ultimo()
{
  int e;
  int numret;
  DiColaEOAO* aux = new DiColaEOAO();
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
void DiColaEOAO::poner_frente(int E)
{
  int e;
  DiColaEOAO* aux = new DiColaEOAO();
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
void DiColaEOAO::sacar_final(int &E)
{
  int e;
  DiColaEOAO* aux = new DiColaEOAO();
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
string DiColaEOAO::mostrar() {
  string s = "DiColaEOAO \n+---+\n";
  int e;
  DiColaEOAO* aux = new DiColaEOAO();
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