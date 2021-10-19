#pragma hdrstop

#include "TDAPoliSm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PoliSm::PoliSm() {
	mem = new CSMemoria();
	ptr_poli = nulo;
	nt = 0;
}

PoliSm::PoliSm(CSMemoria* m) {
	mem = m;
	ptr_poli = nulo;
	nt = 0;
}
int PoliSm::buscar_exponente(int exp) {
	int dir = ptr_poli;
	if (dir != nulo) {
		int dir_ex = nulo;
		while (dir != nulo && dir_ex == nulo) {
			if (mem->obtener_dato(dir, expP) == exp)
					dir_ex = dir;
			dir = mem->obtener_dato(dir, sigP);
		}
		return dir_ex;
	}
	else {
		return nulo;
	}
}
int PoliSm::buscar_termino_n(int i) {
	int dir = ptr_poli;
	if (dir != nulo) {
		int dir_ter = nulo;
		int nt = 0;
		while (dir != nulo && dir_ter == nulo) {
			nt++;
			if (nt == i)
				dir_ter = dir;
			dir = mem->obtener_dato(dir, sigP);
		}
		return dir_ter;
	}
	else {
		cout << "EXCEPTION NO EXISTE ESE TERMINO\n";
		return nulo;
	}
}
bool PoliSm::es_cero() {
	return nt == 0;

}
int PoliSm::grado() {
	int dir = ptr_poli;
	if (dir != nulo) {
		int max_grado = mem->obtener_dato(dir, expP);
		while (dir != nulo) {
			if (mem->obtener_dato(dir, expP) > max_grado)

					max_grado = mem->obtener_dato(dir, expP);
			dir = mem->obtener_dato(dir, sigP);
		}
		return max_grado;
	}
	else
		cout << "POLINOMIO NO TIENE TERMINOS\n";
}
int PoliSm::coeficiente(int exp) {
	int dir = buscar_exponente(exp);
	if (dir != nulo)
		return mem->obtener_dato(dir, coefP);
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";

}
int PoliSm::anterior(int dir) {
	int x = ptr_poli; ;
	int ant = nulo;
	while (x != nulo) {
		if (x == dir)
			return ant;
		ant = x;
		x = mem->obtener_dato(x, sigP);
	}
	return nulo;
}
void PoliSm::asignar_coeficiente(int coef, int exp) {
	int dir = buscar_exponente(exp);
	if (dir != nulo) {
		mem->Poner_dato(dir, coefP, coef);
		if (coef == 0) {
			if (dir == ptr_poli) {
				ptr_poli = mem->obtener_dato(ptr_poli, sigP);
			}
			else {
				int ant = anterior(dir);
				int dir_sig = mem->obtener_dato(dir, sigP);
				mem->Poner_dato(ant, sigP, dir_sig);
			}
			mem->Delete_Espacio(dir);
			nt--;
		}
	}
	else
		cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}
void PoliSm::poner_termino(int coef, int exp) {
	if (coef != 0 && exp >= 0) {
		int existe = buscar_exponente(exp);
		if (existe == nulo) {
			int aux = mem->New_Espacio(datosP);
			if (aux != nulo) {
				mem->Poner_dato(aux, coefP, coef);
				mem->Poner_dato(aux, expP, exp);
				mem->Poner_dato(aux, sigP, ptr_poli);
				ptr_poli = aux;
				nt++;
			}
			else
				cout << "NO EXISTE ESPACIO MEMORIA\n";
		}
		else {
			int nuevo_coef = mem->obtener_dato(existe, coefP) + coef;
			mem->Poner_dato(existe, coefP, nuevo_coef);
			if (nuevo_coef == 0) {
				if (existe == ptr_poli) {
					ptr_poli = mem->obtener_dato(ptr_poli, sigP);

				}
				else {
					int ant = anterior(existe);
					int existe_sig = mem->obtener_dato(existe, sigP);
					mem->Poner_dato(ant, sigP, existe_sig);

				}
				mem->Delete_Espacio(existe);
				nt--;
			}
		}
	}
}

int PoliSm::numero_terminos() {
	return nt;
}
int PoliSm::exponente(int nro) {
	int dir = buscar_termino_n(nro);
	if (dir != nulo)
		return mem->obtener_dato(dir, expP);
	else
		cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
}

void PoliSm::sumar(PoliSm* p1, PoliSm* p2, PoliSm* &pr) {
	pr = new PoliSm();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
}

void PoliSm::restar(PoliSm* p1, PoliSm* p2, PoliSm* &pr) {
	pr = new PoliSm();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(ex, co);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(-ex, co);
	}
}

void PoliSm::multiplicar(PoliSm* p1, PoliSm* p2, PoliSm* &pr) {
	pr = new PoliSm();
}

void PoliSm::derivar() {
	int n = numero_terminos();
	int* exn = new int[n];
	int* con = new int[n];
	int c = 0;
	while (!es_cero()) {
		int ex = exponente(1);
		int co = coeficiente(ex);
		poner_termino(-co, ex);
		exn[c] = ex;
		con[c] = co;
		c++;
	}
	for (int i = 0; i < n; i++) {
		int ex = exn[i];
		int co = con[i];
		poner_termino(co*ex, ex - 1);
	}
}

string PoliSm::to_str() {
	string s = "";
	for (int i = 1; i <= numero_terminos(); i++) {
		int ex = exponente(i);
		int co = coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}
