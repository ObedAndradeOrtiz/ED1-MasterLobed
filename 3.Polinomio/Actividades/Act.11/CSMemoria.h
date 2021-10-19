#ifndef CSMemoriaH
#define CSMemoriaH
#include <iostream>
#include <string>
using namespace std;
typedef int Direccion;
const int MAXIMO = 20, nulo = -1;
struct NodoM {
	int dato;
	string id;
	Direccion link;
};



class CSMemoria {
private:
    NodoM mem[MAXIMO]; //vector estatico con memoria ya creada
	Direccion libre;

public:
	CSMemoria();
	Direccion new_espacio(string cad);
	void delete_espacio(Direccion dir);
	void poner_dato(Direccion dir, string id, int valor);
	int  obtener_dato(int dir, string id);
	int  Espacio_Disponible();
	int  Espacio_ocupado();
	bool dir_libre(Direccion dir);
   	void mostrar_memoria();
};
#endif

