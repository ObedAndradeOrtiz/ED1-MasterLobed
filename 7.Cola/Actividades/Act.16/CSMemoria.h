#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
typedef int Direccion;
const int MAXIMO = 20, nulo = -1;
struct NodoMem{
	int dato;
	string id;
	Direccion link;
};

class CSMemoria {
private:
	NodoMem mem[MAXIMO]; //vector estatico con memoria ya creada
	Direccion libre;

public:
	CSMemoria();
	Direccion New_Espacio(string cad);
	void Delete_Espacio(Direccion dir);
	void Poner_dato(Direccion dir, string id, int valor);
	int  obtener_dato(int dir, string id);
	int  Espacio_Disponible();
	int  Espacio_ocupado();
	bool dir_libre(Direccion dir);
   	void mostrar_memoria();
};
#endif