//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaDes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DiColaDes::DiColaDes()
{
ini=0;
fin=-1;
}
bool DiColaDes::Vacia()
{
return fin==-1;
}
void DiColaDes::Poner(int E)
{
	if(Vacia())
	{
		ini=0;
		fin=0;
		v[0]=E;
	}
	else if(fin<maximo)
	{
		fin++;
		v[fin]=E;
	}
}
void desplazar(int vec[], int max)
{
   for(int i=0; i<max; i++)
   {
	   vec[i]=vec[i+1];
	   if(i+1==max)
	   {
           break;
	   }
   }
}
void DiColaDes::Sacar( int &E)
{
 E=v[ini];
 desplazar(v,maximo);
 fin--;
}
int DiColaDes::Primero()
{
return v[ini];
}
int DiColaDes::ultimo()
{
   return v[fin];
}
void DiColaDes::poner_frente(int E)
{
	if(fin+1<maximo)
	{
		for(int i=fin+1; i>ini; i--)
		{
			v[i]=v[i-1];
		}
		v[ini]=E;
		fin++;
	}
}
void DiColaDes::sacar_final(int &E)
{
	E=ultimo();
    fin--;
}
string DiColaDes::mostrar() {
  string s = "DICOLA\n+---+\n";
  int e;
  DiColaDes* aux = new DiColaDes();
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
