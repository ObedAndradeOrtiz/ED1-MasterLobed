#include "TDAconjuntoCSMemoria.h"
#include "CSMemoria.h"
#include "UPoliListaSm.h"
#include "UPoliListaSm.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    CSMemoria* mem=new CSMemoria();
	ListaSM* LEOAO=new ListaSM(mem);
	ConjuntoSM* CEOAO=new ConjuntoSM(mem);
	PoliListaSm* PEOAO=new PoliListaSm(mem);
	int A=mem->New_Espacio("Esrom Obed");
	int B=mem->New_Espacio("Andrade");
	int C=mem->New_Espacio("Ortiz");
	mem->Delete_Espacio(A);
	LEOAO->inserta(LEOAO->primero(),100);
	LEOAO->inserta(LEOAO->primero(),90);
	mem->Delete_Espacio(B);
	CEOAO->inserta(88);
	PEOAO->poner_termino(11,3);
	PEOAO->poner_termino(5,1);
	PEOAO->poner_termino(4,7);
	LEOAO->inserta(LEOAO->fin(),95);
	mem->mostrar_memoria();
	 cout<<PEOAO->toStr()<<endl;
	 PEOAO-> derivada();
	 cout<<PEOAO->toStr()<<endl;
     CEOAO->To_Str();
     mem->mostrar_memoria();


	return 0;
}