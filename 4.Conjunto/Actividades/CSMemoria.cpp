#include "CSMemoria.h"

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
 mem = new NodoMem[MAX];
 for (int i = 0; i < MAX; i++) {
  mem[i].link = i + 1;
 }
 mem[MAX - 1].link = -1;
 this->libre = 0;
}


int CSMemoria::new_espacio(string cadena) {
 int num = cantidad_ids(cadena);
 if (num <= espacio_disponible()) {
  int d = this->libre;
  int dir = d;
  int aux;
  while (cadena.length() > 0) {
   int pos = cadena.find_first_of(",");
   if (pos == -1) {
    pos = cadena.length();
    aux = d;
   }
   string id = cadena.substr(0, pos);
   mem[d].id = id;
   d = mem[d].link;
   cadena.erase(0, pos + 1);
  }
  this->libre = mem[aux].link;
  mem[aux].link = -1;
  return dir;
 }
 else {
  cout << "ERROR: ESPACIOS INSUFICIENTES\n";
  return NULO;
 }
}

void CSMemoria::delete_espacio(int dir) {
 int x = dir;
 while (mem[x].link != -1)
  x = mem[x].link;
 mem[x].link = libre;
 libre = dir;
}

void CSMemoria::poner_dato(int dir, string cadena_id, int valor) {
 int z = dir;
 cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
 // Elimina la flecha
 while (z != NULO) {
  if (mem[z].id == cadena_id) {
   mem[z].dato = valor;
   break;
  }
  z = mem[z].link;
 }
}

int CSMemoria::obtener_dato(int dir, string cadena_id) {
 int z = dir;
 cadena_id = cadena_id.substr(2, cadena_id.length() - 2);
 // Elimina la flecha
 while (z != NULO) {
  if (mem[z].id == cadena_id)
   return mem[z].dato;
  z = mem[z].link;
 }
}

int CSMemoria::espacio_disponible() {
 int x = libre;
 int c = 0;
 while (x != -1) {
  c++;
  x = mem[x].link;
 }
 return c;
}

int CSMemoria::espacio_ocupado() {
 int c = MAX - espacio_disponible();
 return c;
}

bool CSMemoria::dir_libre(int dir) {
 int x = libre;
 bool c = false;
 while (x != -1 && c == false) {
  if (x == dir)
   c = true;
  x = mem[x].link;
 }
 return c;
}



void CSMemoria::mostrar() {
 string cab = "| DIR |  DATO  |    ID    | LINK |\n";
 string lin = "+" + string(cab.length() - 3, '-') + "+\n";
 string out = lin + cab + lin;
 int edir = 3, edat = 8, eid = 10; // eid lo cambian
 for (int i = 0; i < MAX; i++) {
  int rel = edir - to_string(i).length();
  string dir = " " + string(rel, '0') + to_string(i) + " ";
  rel = edat - to_string(mem[i].dato).length();
  string dat = string(rel, ' ') + to_string(mem[i].dato);
  rel = eid - mem[i].id.length();
  string id = string(rel, ' ') + mem[i].id;
  rel = edir - to_string(mem[i].link).length();
  string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
  out += "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
 }
 out += lin;
 out += "Libre = " + to_string(libre) + "\n";
 cout << out;
}