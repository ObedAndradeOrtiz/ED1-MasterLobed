//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaExt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
using namespace std;
int ColaExt::siguiente(int e)
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
ColaExt::ColaExt()
{
ini=0;
fin=-1;
}
bool ColaExt::Vacia()
{
return siguiente(fin)==ini;
}
void ColaExt::Poner(int E)
{
if(siguiente(fin)!=ini)
{

   fin=siguiente(fin);
   v[fin]=E;
}
}
void ColaExt::Sacar( int &E)
{
   E=v[ini];
   ini=siguiente(ini);
}
int ColaExt::Primero()
{
return v[ini];
}
void ColaExt::mostrar()
{
	int* aux=v;
	for(int i=0; i<fin; i++)
	{
	  cout<<aux[i]<<endl;
    }
}
