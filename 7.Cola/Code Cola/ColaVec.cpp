//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVec.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ColaVec::ColaVec()
{
ini=-1;
fin=-1;
}
bool ColaVec::Vacia()
{
return fin==-1;
}
void ColaVec::Poner(int E)
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
void ColaVec::Sacar( int &E)
{
  E=v[ini];
  ini++;
}
int ColaVec::Primero()
{
 return v[ini];
}

