//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVecDes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ColaDes::ColaDes()
{
ini=0;
fin=-1;
}
bool ColaDes::Vacia()
{
return fin==-1;
}
void ColaDes::Poner(int E)
{
	if(Vacia())
	{
		ini=0;
		fin=0;
		v[fin]=E;
	}
	else if(fin<maximo)
	{
		fin++;
		v[fin]=E;
	}
}
int* desplazar(int *vec, int max)
{
   for(int i=0; i<max; i++)
   {
	   vec[i]=vec[i+1];
	   if(i+1==max)
	   {
		   return vec;
       }
   }
}
void ColaDes::Sacar( int &E)
{
 E=v[ini];
 v=desplazar(v,maximo);
 fin--;
}
int ColaDes::Primero()
{
return v[ini];
}
