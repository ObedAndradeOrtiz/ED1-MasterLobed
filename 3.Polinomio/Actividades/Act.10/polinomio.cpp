#include "polinomio.h"
polinomio::polinomio() {
	nt = 0;
}
void eliminar_posicion(int *v,int k,int nt){
	for(int i = k;i < nt - 1;i++){
		v[i] = v[i+1];
    }
}
int existe_exponente(int Exp, int ve[maxV], int nt ) {
	for (int i = 0; i < nt; i++) {
		if (ve[i] == Exp)
			return i;
	}
	return -1;
}

bool polinomio::es_cero() {
	return nt == 0;
}
void polinomio::asignarCoeficiente(int Exp, int coef)
{
    int lug = existe_exponente(Exp,ve, nt);
    if(lug!=-1)
    {
        vc[lug]=coef;
        if(vc[lug]==0)
        {
         	eliminar_posicion(vc, lug, nt);
			eliminar_posicion(ve, lug, nt);
			nt--;
        }
        
    }
    else
    {
    cout<<"POLINOMIO NO TIENE ESE TERMINO CON ESE EXP.";
    }
}
void polinomio::poner_termino(int coef, int Exp) {
	int lug = existe_exponente(Exp, ve,nt);
	if (lug != -1) {
		vc[lug] = vc[lug] + coef;
		if (vc[lug] == 0) {
			eliminar_posicion(vc, lug, nt);
			eliminar_posicion(ve, lug, nt);
			nt--;
		}
	}
	else {
		nt++;
		vc[nt - 1] = coef;
		ve[nt - 1] = Exp;
	}
}

int polinomio::coeficiente(int exp) {
	if (exp >= 0 && exp <= grado()) {
		for (int i = 0; i < nt; i++) {
			if (ve[i] == exp)
				return vc[i];
		}
	}
	cout << "ERROR NO EXISTE TERMINO CON ESE EXPONENTE\n";
}

int polinomio::exponente(int nro) {
	if (nro < nt)
		return ve[nro];
	else
		cout << "ERROR FUERA DE RANGO\n";
}

int polinomio::grado() {
	if (nt > 0) {
		int max = ve[0];
		for (int i = 0; i < nt; i++) {
			if (ve[i] > max)
				max = ve[i];
		}
		return max;
	}
	else
		cout << "NO EXISTEN TERMINOS\n";
}

int polinomio::numero_terminos() {
	return nt;
}

void polinomio::suma(polinomio otro) 
{
	for (int i = 0; i < otro.numero_terminos(); i++) {
		
		int Exp1 = otro.exponente(i);
		int coef1 = otro.coeficiente(Exp1);
		poner_termino(coef1, Exp1);
	}
}

void polinomio::resta(polinomio otro) {
	for (int i = 0; i < otro.numero_terminos(); i++) {
	
		int exp2 = otro.exponente(i);
		int coef2 = -otro.coeficiente(exp2);
		poner_termino(coef2, exp2);
	}
}
void polinomio::multiplica(polinomio otro)
{
    
    	for (int i = 0; i < otro.numero_terminos(); i++) 
    	{
	      for(int j=0; j<nt; j++)
	      {
	         int exp1 =this->exponente(i);
		     int coef1 = this->coeficiente(exp1);
		     int Exp2= otro.exponente(j);
		     int coef2=otro.coeficiente(Exp2);
		     int coef3=coef1*coef2;
		     int Exp3=exp1+Exp2;
		     poner_termino(coef3,Exp3);
	      }
		
	    }
    
}


void polinomio::toStr() {
	string ret = "";
	for (int i = 0; i < nt; i++) {
		int exp = this->exponente(i);
		int coef = this->coeficiente(exp);
		string signo;
		if (coef > 0)
			signo = "+";
		else {
			signo = "-";
			coef = coef*-1;
		}
		ret = ret + signo + to_string(coef) + "x^" + to_string(exp);
	}

	cout<< ret<<endl;
}