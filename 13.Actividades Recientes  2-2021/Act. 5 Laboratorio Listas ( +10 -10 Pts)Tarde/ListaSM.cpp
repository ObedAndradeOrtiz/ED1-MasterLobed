#include "ListaSM.h"

ListaSM::ListaSM() {
	this->mem = new RAPCSMemoria();
	longitud= 0;
	PtrElementos = nulo;
}
ListaSM::ListaSM(RAPCSMemoria *me) {
	this->mem = me;
	longitud = 0;
	PtrElementos = nulo;
}
direccion ListaSM::fin(){
    int x=0; 
    int PtrFin=0;
	if (vacia()) {
		cout<<"Lista vacia"<<endl;
	}else{
		 x = PtrElementos;
		while (x!=-1){
		     PtrFin = x;
			x = mem->obtener_dato(x,sigL);
		}
		return PtrFin;
    }
}

direccion ListaSM::primero(){
if (!vacia())
		return PtrElementos;
	else
		cout << "ERROR: LISTA VACIA\n";
}

direccion ListaSM::siguiente(direccion dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return mem->obtener_dato(dir, sigL); 
	}
}

direccion ListaSM::anterior(direccion dir){
  if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			int x = PtrElementos;
			int ant = nulo;
			while (x != nulo) {
				if (x == dir)
					return ant;
				ant = x;
				x = mem->obtener_dato(x, sigL); 
			}
			return nulo;
		}
	}
}

bool ListaSM::vacia(){
	return longitud==0;
}

int ListaSM::recupera(direccion dir){
	if (vacia()) {
		cout<<"Lista vacia"<<endl;
	}else{
		return mem->obtener_dato(dir,elementoL);
    }
}

int ListaSM::Mostrarlongitud(){
	return longitud;
}

void ListaSM::inserta(direccion p, int e)
{
	int x = mem->New_Espacio(datoL); 
	if (x != nulo) {
		mem->Poner_dato(x, elementoL, e); 
		mem->Poner_dato(x, sigL, nulo); 
		if (vacia()) {
			PtrElementos = x;
			longitud = 1;
		}
		else {
			longitud++;
			if (p == primero()) {
				mem->Poner_dato(x, sigL, p); 
				PtrElementos = x;
			}
			else {
				int ant = anterior(p);
				mem->Poner_dato(ant, sigL, x); 
				mem->Poner_dato(x, sigL, p);
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaSM::inserta_primero( int elemento){
   	int x = mem->New_Espacio(datoL); 
	if (x != nulo) {
		mem->Poner_dato(x, elementoL, elemento); 
		mem->Poner_dato(x, sigL, PtrElementos); 
		PtrElementos = x;
		longitud++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}
void ListaSM::inserta_ultimo(int e) {
	int x = mem->New_Espacio(datoL); 
	if (x != nulo) {
		mem->Poner_dato(x, elementoL, e);
		mem->Poner_dato(x, sigL, nulo); 
		if (vacia())
			PtrElementos = x;
		else
			mem->Poner_dato(fin(), sigL, x);
		longitud++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaSM::suprime(direccion dir){
	if (longitud == 0) {
		cout<<"Lista vacia"<<endl;
	}else{
		if (dir==PtrElementos) {
			int x=PtrElementos;
			PtrElementos=mem->obtener_dato(PtrElementos, "->sig");
			mem->Delete_Espacio(x);
		}else{
			int ant=anterior(dir);
			mem->Poner_dato(ant,sigL,siguiente(dir));
			mem->Delete_Espacio(dir);
		}
		longitud--;
	}
}

void ListaSM::modifica(direccion dir, int elemento){
	if (vacia()) {
		cout<<"Lista vacia"<<endl;
	} else{
		mem->Poner_dato(dir,elementoL,elemento);
	}
}

string ListaSM::Mostrar(){
	string m="L < ";
	int aux=PtrElementos;
	while (aux!=-1){
		int elem=mem->obtener_dato(aux,elementoL);
		m=m+to_string(elem);
		aux = mem->obtener_dato(aux,sigL);
		if (aux!=-1) {    //1,2,
			m=m+",";
		}
	}
	return m + " >";
}