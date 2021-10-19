// ---------------------------------------------------------------------------



#include "UPoliListaSm.h"
// ---------------------------------------------------------------------------


PoliListaSm::PoliListaSm(CSMemoria * mem) {
	KEOAO = new ListaSM(mem);
	nt = 0;
}

bool PoliListaSm::es_cero() {
	return nt == 0;
}
int PoliListaSm::exponente_existe(int exp) {
	ListaSM *Aux=KEOAO;
	int aux = KEOAO->primero();
	int cont=grado();
	while (aux != nulo) {
	   if(cont==exp)
	   {
		  if(KEOAO->recupera(aux)!=0)
		  {
			return aux;
		  }
	   }
	   cont--;
		aux =Aux->siguiente(aux);
	}
	return nulo;
}

void PoliListaSm::poner_termino(int coef, int exp) {
int cont=0;
ListaSM* Aux=KEOAO;
	if(KEOAO->vacia()){
	  for (int i=0; i <exp; i++) {
		  KEOAO->inserta_primero(0);
	  }
	  KEOAO->inserta_primero(coef);
	}
	else
	{
	  int auxiliar=exponente_existe(exp);
	  if(auxiliar==nulo)
	  {
	  int aux=KEOAO->primero();
	  int cont=0;
	  if(exp<grado())
	  {
	  while(cont<(grado()-exp))
	  {
	   aux=KEOAO->siguiente(aux);
	   cont++;
	  }
	  KEOAO->modifica(aux,coef);
	  }

	  else{
		   int cont=exp-grado();
		   for(int i=0; i<cont-1; i++)
		   {
			   KEOAO->inserta_primero(0);
		   }
		   KEOAO->inserta_primero(coef);
	  }
	}
	else
	{
		KEOAO->modifica(auxiliar,(coef+Aux->recupera(auxiliar)));
	}
	}

}

int PoliListaSm::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		int aux = KEOAO->primero();
		while (aux != nulo) {
			int aux_sig = KEOAO->siguiente(aux); // aux->sig
			int aux_sig_elem = KEOAO->recupera(aux_sig); // aux->sig->elemento
			if (aux_sig_elem == exp)
				return KEOAO->recupera(aux); // return aux->elemento
			aux = KEOAO->siguiente(aux_sig);
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliListaSm::exponente(int nro) {
	int c = 0;
	int aux = KEOAO->primero();
	int aux_sig = KEOAO->siguiente(aux); // aux->sig
	int aux_sig_elem = KEOAO->recupera(aux_sig); // aux->sig->elemento
	int res = aux_sig_elem;
	while (c < nro) {
		aux = KEOAO->siguiente(aux_sig); // aux = aux->sig->sig;
		aux_sig = KEOAO->siguiente(aux); // aux->sig
		aux_sig_elem = KEOAO->recupera(aux_sig); // aux->sig->elemento
		res = aux_sig_elem;
		c++;
	}
	return res;
}

int PoliListaSm::grado() {
	return KEOAO->Mostrarlongitud()-1;
}

int PoliListaSm::numero_terminos() {
	return nt;
}

void PoliListaSm::derivada()
{
  ListaSM* Aux=KEOAO;
  int exponente=grado();
  int aux=KEOAO->primero();
  while(aux!=nulo)
  {
	 if(Aux->recupera(aux)!=0 && Aux->siguiente(aux)!=nulo)
	 {
		 int exp=exponente;
		 int coef=Aux->recupera(aux);
		 int deri=exp*coef;
			 KEOAO->modifica(aux,0);
			 KEOAO->modifica(Aux->siguiente(aux),deri);

			 if(exponente==grado())
			 {
				KEOAO->suprime(aux);
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
string PoliListaSm::toStr() {
    cout<<endl<<KEOAO->Mostrar()<<endl;
	string ret = "";
   string str= "";
   ListaSM* Aux=KEOAO;
   int  aux=KEOAO->primero();
   int cont=KEOAO->Mostrarlongitud()-1;
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

  

	return ret;
}