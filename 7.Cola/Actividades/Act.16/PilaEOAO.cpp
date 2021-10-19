#include "PilaEOAO.h"
PilaEOAO::PilaEOAO(){
	mem = new CSMemoria();
	tope = -1;
}

PilaEOAO::PilaEOAO(CSMemoria* m){
	mem = m;
	tope = -1;
}

bool PilaEOAO::vacia(){
	return tope == -1;
}

void PilaEOAO::meter(int e){
	int aux = mem->New_Espacio("elementoP,sigP");
	if(aux != -1){
		mem->Poner_dato(aux, "->elementoP", e);
		mem->Poner_dato(aux, "->sigP", tope);
		tope = aux;
	}else
		cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaEOAO::sacar(int& e){
	if(!vacia()){
		int x = tope;
		e = mem->obtener_dato(tope,"->elementoP");
		tope = mem->obtener_dato(tope,"->sigP");
		mem->Delete_Espacio(x);
	}
}

int PilaEOAO::cima(){
	if(!vacia()){
		return mem->obtener_dato(tope, "->elementoP");
	}
}

string PilaEOAO::mostrar(){
	string r ="PILA\n+---+\n";
	PilaEOAO* aux = new PilaEOAO();
	while(!vacia()){
		int e;
		sacar(e);
		r += "| "+to_string(e)+" |\n";
		aux->meter(e);
	}
	while(!aux->vacia()){
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n\n";
	return r;
}