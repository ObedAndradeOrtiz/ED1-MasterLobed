#include <iostream>
#include <string>
#include "CSMemoria.h"
#include <conio.h>
#include <stdio.h>
using namespace std;
int main()
{   
    /*CSMemoriaEOAO MiMemEOAO;
    int x=MiMemEOAO.New_Espacio("uno");
    MiMemEOAO.Poner_dato(x,"->uno",100);
    int y=MiMemEOAO.New_Espacio("dos");
    MiMemEOAO.Delete_Espacio(x);
    int z=MiMemEOAO.New_Espacio("Esrom,Obed,Andrade,Ortiz");
    MiMemEOAO.Poner_dato(z,"->Esrom",MiMemEOAO.obtener_dato(z,"->Esrom")+5);
    MiMemEOAO.mostrar_memoria();
    return 0;*/
    int opcion=-1;
    string stropcion = "";
    CSMemoria mem;
    while (opcion!=6)
    {
        system("cls");
        cout << "1)CREAR"<<endl;
        cout << "2)PEDIR ESPACIO"<<endl;
        cout << "3)LIBERAR ESPACIO"<<endl;
        cout << "4)PONER DATO"<<endl;
        cout << "5)MOSTRAR LA MEMORIA"<<endl;
        cout << "6)SALIR"<<endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
       if(opcion==1)
        {
                cout <<endl<< "memoria creada";
        }
        if (opcion == 2)
        {
            cout << endl << "INGRESE LA CADENA: ";
            cin >> stropcion;
            mem.New_Espacio(stropcion);

        }
        if (opcion == 3)
        {
            cout << endl << "NUMERO PARA LIBERAR ESPACIO: ";
            int espacio = -1;
            cin >> espacio;
            mem.Delete_Espacio(espacio);
        }
        if (opcion == 4)
        {
            int direccion = -1;
            string cadena = "";
            int valor = -1;
            cout << endl << "INGRESE EL DIRECCION: ";
            cin >> direccion;
            cout << endl << "INGRESE LA CADENA: ";
            cin >> cadena;
            cout << endl << "INGRESE EL VALOR: ";
            cin >> valor;
           mem.Poner_dato(direccion, cadena, valor);
        }
        if (opcion == 5)
        {
            mem.mostrar_memoria();
            system("PAUSE");
        }
    }
}