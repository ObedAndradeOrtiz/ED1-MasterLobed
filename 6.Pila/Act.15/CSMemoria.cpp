#include "CSMemoria.h"

#include <iostream>
#include <string>
using namespace std;
int cantidad_ids(string id) {
	int ce = 0;
	int le = id.length();
	for (int i = 0; i < le; i++) {
		char c = id[i];
		if (c == ',')
			ce++;
	}
	if (id[le - 1] != ',')
		ce++;
	return ce;
}
string *vector_ids(string ids) {
	int cantidad = cantidad_ids(ids);
	string *vect = new string[cantidad];
	int c = 0;
	string copia = ids;
	while (copia.length() > 0) {
		int pos = copia.find_first_of(",");
		pos = pos == -1 ? copia.length() : pos;
		string id = copia.substr(0, pos);
		if (c + 1 < cantidad)
			copia = copia.substr(pos + 1, copia.length() - pos - 1);
		else
			copia = "";
		vect[c] = id;
		c++;
	}
	return vect;
}

string repetir(unsigned int cantidad, char c) {
	return std::string(cantidad, c);
}


CSMemoria::CSMemoria() {
	for (int i = 0; i < MAXIMO; i++) {
		mem[i].link = i + 1;
		mem[i].dato=0;
		mem[i].id="";
	}
	mem[MAXIMO- 1].link = nulo;
	libre = 0;
}

Direccion CSMemoria::New_Espacio(string cad) {
	int x = 0;
	int cant = cantidad_ids(cad); //
	if (cant <= Espacio_Disponible()) {
		int dir = libre;
		int d = libre;
		string *ides = vector_ids(cad);
		for (int i = 0; i < cant - 1; i++) {
			mem[d].id = ides[i];
			d = mem[d].link;
		}
		libre = mem[d].link;
		mem[d].link = nulo;
		mem[d].id = ides[cant - 1];
		return dir;
	}
	else
		cout << "MEMORIA INSUFICIENTE\n";
}

void CSMemoria::Delete_Espacio(Direccion dir) {
	int x = dir;
	while (mem[x].link != nulo) {
		x = mem[x].link;
	}
	mem[x].link = libre;
	libre = dir;
}
void CSMemoria::Poner_dato(Direccion dir, string id, int valor) {
	if (id.substr(0, 2) == "->") //
			id.erase(0, 2);
	int z = dir;
	while (z != nulo) {
		if (mem[z].id == id) { //
			mem[z].dato = valor;
			z = nulo;
		}
		else
			z = mem[z].link;
	}
}

int CSMemoria::obtener_dato(Direccion dir, string id) {
	if (id.substr(0, 2) == "->")
		id.erase(0, 2);
	int z = dir;
	while (z != nulo) {
		if (mem[z].id == id)
			return mem[z].dato;
		else
			z = mem[z].link;
	}
	return 0;
}

int CSMemoria::Espacio_Disponible() {
	int x = libre;
	int c = 0;
	while (x != nulo) {
		c++;
		x = mem[x].link;
	}
	return c;
}

int CSMemoria::Espacio_ocupado() {
	return MAXIMO - Espacio_Disponible();
}

bool CSMemoria::dir_libre(Direccion dir) {
	int x = libre;
	bool c = false;
	while (x != nulo && c == false) {
		if (x == dir)
			c = true;
		x = mem[x].link;
	}
	if (c == false)
		return true;
	else
		return false;
}
string rellenar(string s, int espacios) {
	if (espacios <= s.length()) {
		return s;
	}
	int relleno = espacios - s.length();
	return s + repetir(relleno, ' ');
}
 void CSMemoria::mostrar() {
 int esp = 10;
 string cab_dir = rellenar("dir", esp);
 string cab_id = rellenar("id", esp);
 string cab_dato = rellenar("dato", esp);
 string cab_link = rellenar("link", esp);
 string esp7 = "";
 string cabecera = esp7 + "|" + cab_dir + "|" + cab_dato + "|" + cab_id +
 "|" + cab_link + "|";
 string linea = esp7 + repetir(cabecera.length() - esp7.length(), '-');
 cout << endl<<cabecera << endl;
 cout << linea << endl;
 for (int i = 0; i < MAXIMO; i++) {
 string ocup;
 string dir = rellenar(to_string(i), esp);
 string id = rellenar(mem[i].id, esp);
 string dato = rellenar(to_string(mem[i].dato), esp);
 string link = rellenar(to_string(mem[i].link), esp);
 cout << ocup << "|" << dir << "|" << dato << "|" << id << "|" << link <<
 "|" << endl;
 }
 cout << linea << endl;
 cout << esp7 << "Libre = " << to_string(libre) << endl<<endl;
 }

