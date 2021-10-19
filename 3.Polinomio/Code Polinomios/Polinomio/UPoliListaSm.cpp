

#pragma hdrstop

#include "UPoliListaSm.h"

#pragma package(smart_init)

PoliListaSm::PoliListaSm(CSMemoria * mem) {
	KDCDS = new ListaSM(mem);
	nt = 0;
}

bool PoliListaSm::es_cero() {
	return nt == 0;
}
int PoliListaSm::exponente_existe(int exp) {
	ListaSM *Aux=KDCDS;
	int aux = KDCDS->primero();
	int cont=grado();
	while (aux != nulo) {
	   if(cont==exp)
	   {
		  if(KDCDS->recupera(aux)!=0)
		  {
			return aux;
		  }
	   }
	   cont--;
		aux =Aux->siguiente(aux);
	}
	return -1;
}
void PoliListaSm::poner_termino(int coef, int exp) {
    int cont=0;
	ListaSM* Aux=KDCDS;
	if(KDCDS->vacia()){
	  for (int i=0; i <exp; i++) {
		  KDCDS->inserta_primero(0);
	  }
	  KDCDS->inserta_primero(coef);
	}
	else
	{
	  int auxiliar=exponente_existe(exp);
	  if(auxiliar==nulo)
	  {
	  int aux=KDCDS->primero();
	  int cont=0;
	  if(exp<grado())
	  {
	  while(cont<(grado()-exp))
	  {
	   aux=KDCDS->siguiente(aux);
	   cont++;
	  }
	  KDCDS->modifica(aux,coef);
	  }

	  else{
		   int cont=exp-grado();
		   int i=0;
		   while(i<cont-1)
		   {
				 KDCDS->inserta_primero(0);
                 i++;
           }
		   KDCDS->inserta_primero(coef);
	  }
	}
	else
	{
		KDCDS->modifica(auxiliar,(coef+Aux->recupera(auxiliar)));
	}
	}

}
int PoliListaSm::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		int aux = KDCDS->primero();
		while (aux != nulo) {
			int aux_sig = KDCDS->siguiente(aux);
			int aux_sig_elem = KDCDS->recupera(aux_sig);
			if (aux_sig_elem == exp)
				return KDCDS->recupera(aux);
			aux = KDCDS->siguiente(aux_sig);
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}
int PoliListaSm::exponente(int nro) {
	int c = 0;
	int aux = KDCDS->primero();
	int aux_sig = KDCDS->siguiente(aux);
	int aux_sig_elem = KDCDS->recupera(aux_sig);
	int res = aux_sig_elem;
	while (c < nro) {
		aux = KDCDS->siguiente(aux_sig);
		aux_sig = KDCDS->siguiente(aux);
		aux_sig_elem = KDCDS->recupera(aux_sig);
		res = aux_sig_elem;
		c++;
	}
	return res;
}
int PoliListaSm::grado() {
	return KDCDS->Mostrarlongitud()-1;
}

int PoliListaSm::numero_terminos() {
	return nt;
}
void PoliListaSm::Derivada()
{
  ListaSM* Aux=KDCDS;
  int exponente=grado();
  int aux=KDCDS->primero();
  while(aux!=NULL)
  {
	 if(Aux->recupera(aux)!=0 && Aux->siguiente(aux)!=nulo)
	 {
		 int exp=exponente;
		 int coef=Aux->recupera(aux);
		 int deri=exp*coef;
			 KDCDS->modifica(aux,0);
			 KDCDS->modifica(Aux->siguiente(aux),deri);
			 if(exponente==grado())
			 {
				KDCDS->suprime(aux);
			 }
			 aux=Aux->siguiente(aux);
			 aux=Aux->siguiente(aux);
			 exponente=exponente-2;
	 }
	 else
	 {
	 aux=Aux->siguiente(aux);
	 exponente--;

	 }
  }
}
void PoliListaSm::toStr() {
	string ret = "";
   string str= "";
   ListaSM* Aux=KDCDS;
   int  aux=KDCDS->primero();
   int cont=KDCDS->Mostrarlongitud()-1;
   while(cont>=0)
   {
	  int num=Aux->recupera(aux);
	  if(num>=0)
	  {
		 str="+";
	  }
	  else
	  {
		  str="-";
	  }
	  if(Aux->recupera(aux)!=0)
	  {
	  cout<<num<<"x^"<<cont<<str;
	  }
	  aux=Aux->siguiente(aux);
	  cont--;
   }

   cout<<endl<<KDCDS->Mostrar()<<endl;
   cout<<ret<<endl;

}
