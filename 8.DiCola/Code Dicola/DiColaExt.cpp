//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaExt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>
using namespace std;
int DiColaExtrem::siguiente(int e)
{
if(e<maxim)
{
   return e+1;
}
else
{
	return 0;
}

}

DiColaExtrem::DiColaExtrem()
{
ini=0;
fin=-1;
}

bool DiColaExtrem::Vacia()
{
return siguiente(fin)==ini;
}
void DiColaExtrem::Poner(char E)
{
if(Vacia())
{
   fin=siguiente(fin);
   v[fin]=E;
}
else if(siguiente(fin)!=ini)
{

   fin=siguiente(fin);
   v[fin]=E;
}
}
void DiColaExtrem::Sacar(char &E)
{
   E=v[ini];
   ini=siguiente(ini);
}
char DiColaExtrem::Primero()
{
return v[ini];
}
char DiColaExtrem::ultimo()
{
   return v[fin];
}
void DiColaExtrem::poner_frente(char E)
{
	if(fin+1<maxim)
	{
		for(int i=fin+1; i>ini; i--)
		{
			v[i]=v[i-1];
		}
		v[ini]=E;
		fin++;
	}
}
void DiColaExtrem::sacar_final(char &E)
{
	E=ultimo();
	fin--;
}
string DiColaExtrem::mostrarD() {
  string s = "DICOLA\n+---+\n";
  char e;
  DiColaExtrem* aux = new DiColaExtrem();
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
