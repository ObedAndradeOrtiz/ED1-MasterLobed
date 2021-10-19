#include <stdio.h>
#include <iostream>
#include "PoliSm.h"
bool espolinomiocompleto( PoliSm* poli )
{
    bool completo=false;
    if(poli->numero_terminos()>1)
    {
    for(int i=poli->grado();i>=0; i--)
    {
        for(int j=0; j<poli->numero_terminos(); j++)
        {
            if(poli->exponente(j)==i)
            {
                completo=true;
                j=poli->numero_terminos();
                
            }
            else
            {
                completo=false;
            }
        }
        if(completo==false)
        {
            i=-1;
        }
        
    }
        
    }
    else
    {
        return true;
    }
    return completo;
}

int main()
{
     CSMemoria* mem= new CSMemoria();
     PoliSm* p=new PoliSm(mem);
     
     p->poner_termino(15,8);
     p->poner_termino(23,0);
     p->poner_termino(2,1);
     p->toStr();
     //ES COMPLETO DE 0 AL MAYOR GRADO COMO DICE LA TEORIA
    if(espolinomiocompleto( p ))
    {
        cout<<"es polinomio completo";
    }
    else
    {
        cout<<"no esta completo";
    }
 
    return 0;
}