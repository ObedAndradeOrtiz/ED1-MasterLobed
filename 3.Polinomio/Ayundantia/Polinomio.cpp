#include "Polinomio.h"
Polinomio::Polinomio()
{
	nt = -1;
	for (int i = 0; i < Max; i++)
	{
		VE[i] = 0;
		VC[i] = 0;
	}
}
bool Polinomio::EsCero()
{
	return(nt == -1);
	//devuelve(booleano)
}
int Polinomio::Grado()
{
	if (nt > 0)
	{
		int max = VE[0];
		for (int i=0; i<nt; i++ )
		{
			if (VE[i] > max)
			{
				max = VE[i];
			}
		}
		return max;
	}
	cout<< "ERROR NO EXISTE";
	return -1;
	// devuelve(Grado del Polinomio)
}
int Polinomio::coeficiente(int Exp)
{
	if (!EsCero()&&(Exp>0)&&(Exp<=Grado()))
	{
		for (int i = 0; i < nt; i++)
		{
			if (VE[i] == Exp)
			{
				return VC[i];
			}
		}
		return -1;
	}
	return -1;
	// devuelve(Coeficiente de Termino)
}
int lugar(int exp,int Ve[20],int nt)
{
	for (int i = 0; i < nt; i++)
	{
		if (Ve[i]== exp)
		{
			return i;
		}
	}
	return -1;
}
void Polinomio::AsignarCoeficiente(int coef, int exp)
{
	int lug = lugar(exp,VE,nt);
	if (lug != -1)
	{
		VC[lug] = coef;
		if (VC[lug] == 0)
		{
			for (int i = lug; i < nt; i++)
			{

				VC[i] = VC[i + 1];
				VE[i] = VE[i + 1];
			}
			nt--;
		}
		return;

	}
	cout << "NO EXISTE EXPONENTE";

}
void Polinomio::poner_termino(int coef, int exp)
{
	int lug;
	if (!EsCero())
	{
	 lug = lugar(exp, VE, nt);
	}
	else
	{
		nt++;
		lug = 0;
	}
	if (lug != -1)
	{
		VC[lug] = VC[lug] + coef;
		VE[lug] = exp;
		if (VC[lug] == 0)
		{
			for (int i = lug; i < nt; i++)
			{

				VC[i] = VC[i + 1];
				VE[i] = VE[i + 1];
			}
			nt--;
			return;
		}
	
	}
	
	VC[nt] = coef;
	VE[nt] = exp;
	nt++;
}
int Polinomio::numero_terminos()
{
	return nt;
}//devuelve(Nro.Terminos)
int Polinomio::exponente(int nroter)
{
	return VE[nroter];
}//devuelve(Grado)
void Polinomio::mostrar()
{
	for (int i = 0; i < nt; i++)
	{
		cout << VC[i];
		cout << "X^";
		cout << VE[i];
		cout << ",";
	}
}