//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaVec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DiColaVec::DiColaVec()
{
ini=-1;
fin=-1;
}
bool DiColaVec::Vacia()
{
return fin==-1;
}
void DiColaVec::Poner(int E)
{
	if(Vacia())
	{
		ini=0;
		fin=0;
		v[fin]=E;
	}
	else if(fin<max)
	{
		fin++;
		v[fin]=E;
	}
}
void DiColaVec::Sacar( int &E)
{
  E=v[ini];
  ini++;
}
int DiColaVec::Primero()
{
 return v[ini];
}
