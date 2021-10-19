#include <iostream>
#include <string>
using namespace std;

typedef int direccion_mem;

const int max_memoria = 20, nulo = -1;

struct NodoM {
	int dato;
	string id;
	direccion_mem link;
};

class CSMemoriaEOAO {
private:
    NodoM mem[max_memoria]; //vector estatico con memoria ya creada
	direccion_mem libre;

public:
	CSMemoriaEOAO();
	direccion_mem New_Espacio(string cad);
	void Delete_Espacio(direccion_mem dir);
	void Poner_dato(direccion_mem dir, string id, int valor);
	int  obtener_dato(direccion_mem dir, string id);
	int  Espacio_Disponible();
	int  Espacio_ocupado();
	bool dir_libre(direccion_mem dir);
   	void mostrar_memoria();
};


