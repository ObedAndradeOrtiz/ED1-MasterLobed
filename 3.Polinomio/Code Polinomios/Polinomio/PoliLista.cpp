
#pragma hdrstop

#include "PoliLista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
PoliLista::PoliLista() {
	KEOAO = new ListaP();
	nt = 0;
}

bool PoliLista::es_cero() {
	return nt == 0;
}
NodoL* PoliLista::exponente_existe(int exp) {
	NodoL* aux = KEOAO->primero();
	int cont=grado();
	while (aux != NULL) {
	   if(cont==exp)
	   {
		  if(aux->elemento!=0)
		  {
			return aux;
		  }
	   }
       cont--;
		aux = aux->sig;
	}
	return NULL;
}

void PoliLista::poner_termino(int coef, int exp) {

	int cont=0;
	if(KEOAO->vacia()){
	  for (int i=0; i <exp; i++) {
		  KEOAO->inserta_primero(0);
	  }
	  KEOAO->inserta_primero(coef);
	}
	else
	{
	  NodoL* auxiliar=exponente_existe(exp);
	  if(auxiliar==NULL)
	  {
	  NodoL* aux=KEOAO->primero();
	  int cont=0;
	  if(exp<grado())
	  {
	  while(cont<(grado()-exp))
	  {
	   aux=aux->sig;
	   cont++;
	  }
	  KEOAO->modifica(aux,coef);
	  }

	  else{
		   int cont=exp-grado();
		   for(int i=0; i<cont; i++)
		   {
			   KEOAO->inserta_primero(0);
		   }
		   KEOAO->inserta_primero(coef);
	  }
	}
	else
	{
		KEOAO->modifica(auxiliar,(coef+auxiliar->elemento));
    }
	}


}

int PoliLista::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		NodoL* aux = KEOAO->primero();
		while (aux != NULL) {
			if (aux->sig->elemento == exp)
				return aux->elemento;
			aux = aux->sig->sig;
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliLista::exponente(int nro) {
	int c = 0;
	NodoL* aux = KEOAO->primero();
	int res = aux->sig->elemento;
	while (c < nro) {
		aux = aux->sig->sig;
		res = aux->sig->elemento;
		c++;
	}
	return res;

}

int PoliLista::grado() {
	return KEOAO->longitud()-1;
}

int PoliLista::numero_terminos() {
	return nt;
}


void PoliLista::derivada()
{
  int exponente=grado();
  NodoL* aux=KEOAO->primero();
  while(aux!=NULL)
  {
	 if(aux->elemento!=0 && aux->sig!=NULL)
	 {
		 int exp=exponente;
		 int coef=aux->elemento;
		 int deri=exp*coef;
			 KEOAO->modifica(aux,0);
			 KEOAO->modifica(aux->sig,deri);

			 if(exponente==grado())
			 {
				KEOAO->suprime(aux);
			 }
			 aux=aux->sig->sig;
			 exponente=exponente-2;
	 }
	 else
	 {
	 aux=aux->sig;
	 exponente--;

	 }

  }
}
string PoliLista::toStr() {
   string ret = "";
   string str= "";
   NodoL* aux=KEOAO->primero();
   int cont=KEOAO->longitud()-1;
   while(cont>=0)
   {
	  int num=aux->elemento;
	  if(num>=0)
	  {
		 str="+";
	  }
	  else
	  {
		  str="-";
	  }
	  if(aux->elemento!=0)
	  {
	  cout<<num<<"x^"<<cont<<str;
      }
	  aux=aux->sig;
	  cont--;
   }

   cout<<endl<<KEOAO->toStr();
	return ret;
}
