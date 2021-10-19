#ifndef ListaSMH
#define ListaSMH
#include <iostream>
#include <string>
#include "RAPCSMemoria.h"
using namespace std;
typedef int direccion;

const string datoL = "elemento,sig";
const string elementoL="->elemento";
const string sigL="->sig";



class ListaSM{
	private:
		direccion PtrElementos;
		int longitud;
		RAPCSMemoria* mem;
	public:
		ListaSM();
		ListaSM(RAPCSMemoria *);
		direccion fin();
		direccion primero();
		direccion siguiente(direccion dir);
		direccion anterior(direccion dir);
		bool vacia();
		int recupera(direccion dir);
		int Mostrarlongitud();
		void inserta(direccion p, int e);
		void inserta_primero( int e);
		void inserta_ultimo(int e);
		void suprime(direccion dir);
		void modifica(direccion dir, int elemento);
		string Mostrar();
};
#endif