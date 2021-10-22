# ifndef PolinomioH
# define PolinomioH
#include <string.h>
#include <iostream>
using namespace std;
const int Max = 20;
class Polinomio
{
private:
    int VC[Max];  //estatico
    int VE[Max];
    int nt;
public:
        Polinomio();
        bool EsCero(); //devuelve(booleano)
        int Grado(); // devuelve(Grado del Polinomio)
        int coeficiente(int Exp );// devuelve(Coeficiente de Termino)
        void AsignarCoeficiente(int coef, int exp);
        void poner_termino(int coef, int exp);
        int numero_terminos(); //devuelve(Nro.Terminos)
        int exponente(int nroter); //devuelve(Grado)
        void mostrar();
};
#endif

