#include "CSMemoria.h"
#include "DICOLAEOAO.h"
int main()
{
int e;
 CSMemoria *mem=new CSMemoria();
 int aux= mem->New_Espacio("EXAMEN,FINAL");
 DiColaEOAO* CEOAO= new DiColaEOAO(mem);
 CEOAO->Poner(100);
 mem->mostrar_memoria();
 CEOAO->Poner(200);
 mem->mostrar_memoria();
 CEOAO->Sacar(e);
 cout<<"ELEMENTO: "<<e<<endl;
 mem->mostrar_memoria();
 return 0;
}