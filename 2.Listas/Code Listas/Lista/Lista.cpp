//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaSM::ListaSM() {
	this->mem = new CSMemoria();
	longitud= 0;
	PtrElementos = nulo;
}
ListaSM::ListaSM(CSMemoria *me) {
	this->mem = me;
	longitud = 0;
	ant=0;
	ini=0;
	PtrElementos = nulo;
}
direccion ListaSM::fin(){
   /* int x=0;
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
	}     */
    return PtrElementos;
}

direccion ListaSM::primero(){
if (!vacia())
		return PtrElementos;
	else

        return 0;
}

direccion ListaSM::siguiente(direccion dir){
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
			return mem->obtener_dato(dir, sigL);
	}
}

direccion ListaSM::anterior(direccion dir){
  if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == primero())
			{
            return 0;
			}
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
		mem->Poner_dato(x, antL, x);
		mem->Poner_dato(x, elementoL, e);
		mem->Poner_dato(x, sigL, x);
		if (vacia()) {
			PtrElementos = x;
			longitud = 1;
		}
		else {

			longitud++;
			if (p == primero()) {
				mem->Poner_dato(anterior(p), sigL,x);
                mem->Poner_dato(p, antL,x);
                mem->Poner_dato(x, antL, anterior(p));
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
		if(vacia())
		{
		mem->Poner_dato(x, elementoL, elemento);
		mem->Poner_dato(x, sigL,x);
		mem->Poner_dato(x, antL,x);
		PtrElementos = x;
		ini=x;
		longitud++;
		}
		else
		{
        mem->Poner_dato(PtrElementos, sigL,x );
		mem->Poner_dato(ini, antL,x );
		mem->Poner_dato(ini, sigL,siguiente(ini));
		mem->Poner_dato(x, antL,PtrElementos);
		mem->Poner_dato(x, elementoL, elemento);
		mem->Poner_dato(x, sigL,ini);
        ini=x;
		longitud++;
        }

	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";



}

void ListaSM::ordenar() {
	bool b = false;
	int n = longitud;
	int m = n;
	int aux=ini;
	int vector_numeros[longitud];
	for (int i = 0; i < n; i++) {
	   vector_numeros[i]=mem->obtener_dato(aux,elementoL);
	   aux=siguiente(aux);
	}
	 for(int i=0;i<longitud;i++)
    {
        printf("%d  ", vector_numeros[i]);
    }
    int x, y;
	for(int i=0;i<longitud;i++)
    {
		for(int j=i+1;j<longitud;j++)
        {
            x = vector_numeros[i] - vector_numeros[j];
            if(x>0)
            {
                y = vector_numeros[j];
                vector_numeros[j] = vector_numeros[i];
				vector_numeros[i] = y;
            }
        }
	}
	aux=ini;
	for (int i = 0; i < n; i++) {
	   modifica(aux,vector_numeros[i]);
	   aux=siguiente(aux);
	}
    	 for(int i=0;i<longitud;i++)
    {
        printf("%d  ", vector_numeros[i]);
    }
}
void ListaSM::inserta_ultimo(int e) {
	int x = mem->New_Espacio(datoL);
	if (x != nulo) {
        mem->Poner_dato(PtrElementos, sigL,x);
		mem->Poner_dato(ini, antL,x);
        mem->Poner_dato(x, antL,anterior(x));
		mem->Poner_dato(x, elementoL, e);
		mem->Poner_dato(x, sigL,ini);
		if (vacia())
			PtrElementos = x;
		else
			PtrElementos = x;
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
	string m="K< ";
	int aux=PtrElementos;
	while (aux!=-1){
		int elem=mem->obtener_dato(aux,elementoL);
		m=m+to_string(elem);
		aux = mem->obtener_dato(aux,sigL);
		if (aux!=-1) {
			m=m+",";
		}
	}
	return m + " >";
}
