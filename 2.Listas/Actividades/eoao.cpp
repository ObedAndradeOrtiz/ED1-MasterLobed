#include <stdio.h>
#include "ListaSM.h"
#include "eoaoCSMemoria.h"
#include <iostream>
int main()
{
     eoaoCSMemoria *MiMEmeoao;
     MiMEmeoao=new eoaoCSMemoria();
     ListaSM *Leoao= new ListaSM(MiMEmeoao);
     int z=MiMEmeoao->New_Espacio("esrom,obed,andrade,ortiz");
     MiMEmeoao->Poner_dato(z,"->esrom",MiMEmeoao->obtener_dato(z,"->esrom")+2);
     Leoao->inserta_primero(100);
     Leoao->inserta_ultimo(200);
     Leoao->inserta(Leoao->fin(),150);
     MiMEmeoao->mostrar_memoria();
    return 0;
}