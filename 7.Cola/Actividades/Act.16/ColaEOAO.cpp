#include "ColaEOAO.h"
ColaEOAO::ColaEOAO()
{
	 mem= new  CSMemoria();
	 ini=-1;
	 fin=-1;
}
ColaEOAO::ColaEOAO(CSMemoria *m)
{
   mem=m;
   ini=-1;
   fin=-1;
}
bool ColaEOAO::Vacia()
{
	return ini==nulo;
}
void ColaEOAO::Poner(int E)
{
int aux= mem->New_Espacio("elementoC,sigC");
	if(aux!=nulo)
	{
	   mem->Poner_dato(aux,elemento,E);
	   mem->Poner_dato(aux,sig,nulo);
	   if(Vacia())
	   {
			ini=aux;
			fin=aux;
	   }
	   else
	   {
		   mem->Poner_dato(fin,sig,aux);
		   fin=aux;
	   }
	}
}
void ColaEOAO::Sacar( int &E)
{
   if(!Vacia())
   {
	   E=mem->obtener_dato(ini,elemento);
	   int x=ini;
	   ini=mem->obtener_dato(ini,sig);
	   mem->Delete_Espacio(x);
   }

}
int ColaEOAO::Primero()
{
	 if(!Vacia())
	 {
		 return mem->obtener_dato(ini,elemento);
	 }
}
string ColaEOAO::mostrar() {
  string s = "COLA\n+---+\n";
  int e;
  ColaEOAO* aux = new ColaEOAO();
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