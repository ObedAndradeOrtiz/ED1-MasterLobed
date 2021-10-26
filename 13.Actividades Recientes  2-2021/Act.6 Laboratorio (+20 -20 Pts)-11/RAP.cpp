#include <iostream>
#include <string>
#include "RAPCpolinomio.h"
using namespace std;
bool SonOpuestos(RAPCpolinomio* A, RAPCpolinomio* B);
int main()
{
    bool x=false;
    RAPCpolinomio* RAPA = new RAPCpolinomio();
    RAPCpolinomio* RAPB = new RAPCpolinomio();
     
     RAPA->poner_termino(2,2);
     RAPB->poner_termino(5,2);
     RAPB->poner_termino(-3,7);
     
    x = SonOpuestos(RAPA, RAPB);
    if(x)
    {
        cout<<"Son polinomios opuestos";
    }
    else
    {
        cout<<"no son polinomios opuestos";
    }

}
bool SonOpuestos(RAPCpolinomio* A, RAPCpolinomio* B)
{
    if (A->numero_terminos() == B->numero_terminos())
    {
        int contr = 0;
        for (int i = 0; i <A->numero_terminos(); i++) {
            int exp = A->exponente(i);
            int coef = A->coeficiente(exp);
            int cont = 0;
            while (cont<A->numero_terminos())
            {
                int expB = B->exponente(cont);
                int coefB = B->coeficiente(expB);
                if ((expB == exp) && (-coefB == coef))
                {
                    contr++;
                }
                cont++;
            }
            if (contr == 0)
            {
                return false;
            }
        }
        if (contr == A->numero_terminos())
        {
            return true;
        }
    }
    return false;
}