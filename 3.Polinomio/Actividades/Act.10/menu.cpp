#include <stdio.h>
#include <iostream>
#include "polinomio.h"
bool espolinomiocompleto( polinomio poli )
{
    bool completo=false;
    for(int i=poli.grado();i>=0; i--)
    {
        for(int j=0; j<poli.numero_terminos(); j++)
        {
            if(poli.exponente(j)==i)
            {
                completo=true;
                j=poli.numero_terminos();
                
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
    return completo;
}

int main()
{
     polinomio p;
     p.poner_termino(15,2);
     p.poner_termino(23,1);
     p.poner_termino(2,0);
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