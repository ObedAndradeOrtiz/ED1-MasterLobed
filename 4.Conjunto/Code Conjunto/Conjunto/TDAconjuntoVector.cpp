//---------------------------------------------------------------------------

#pragma hdrstop

#include "TDAconjuntoVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <cstdlib>
ConjuntoV::ConjuntoV(){
for(int i=0; i<max; i++)
{
   v[i]=0;
}
cant=0;
}
bool ConjuntoV::vacio (){
return(cant==0);
}
bool ConjuntoV::pertenece(int e){
for(int i=0; i<max; i++)
{
	if(v[i]==e)
	{
		return true;
	}
}
   return false;
}

void ConjuntoV::inserta(int e){
if(vacio())
{
	v[0]=e;
    cant++;
}
else
{  if(!pertenece(e))
  {
	v[cant]=e;
    cant++;
  }
}
}
int ConjuntoV::cardinal(){
return(cant);
}
int ConjuntoV::ordinal(int e){
for(int i=0; i<cant; i++)
{
 if(v[i]==e)
 {
	 return(i+1);
 }
}
return 0;
}
void ConjuntoV::suprime(int e){
if(!vacio())
{
for(int i=0; i<cant; i++)
{

	if(v[i]==e)
	{
       if(i==max)
	   {
		 v[max]=0;
	   }
	   else
	   {
		for(int j=i; j<cant; j++)
		{
			v[j]=v[j+1];
		}
	   }
	}
}
}
cant--;
}
int ConjuntoV::muestrea(){
 int lug=rand()%cant;
 return(v[lug-1]);
}
void ConjuntoV::To_Str(){
cout<<"C<";
for(int i=0; i<cant; i++)
{
	cout<<v[i]<<",";
}
cout<<">";
}
