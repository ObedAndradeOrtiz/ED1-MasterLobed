#include <stdio.h>
#include <iostream>
#include "ColaEOAO.h"
#include "PilaEOAO.h"
#include "CSMemoria.h"
void invertir(ColaEOAO *c) {
  if (!c->Vacia()) {
	int e;
	c->Sacar(e);
	invertir(c);
	c->Poner(e);
  }
}
int main()
{
	int valor;
	CSMemoria* m;
	PilaEOAO* PEOAO;
	ColaEOAO * CEOAO;
	while(valor!=10)
	{
		cout<<"1. CREAR MEMORIA"<<endl;
		cout<<"2. CREAR COLA"<<endl;
		cout<<"3. PONER EN LA COLA"<<endl;
		cout<<"4. MOSTRAR COLA"<<endl;
		cout<<"5. CREAR PILA"<<endl;
		cout<<"6. PONER EN LA PILA"<<endl;
		cout<<"7. MOSTRAR PILA"<<endl;
		cout<<"8. INVERTIR COLA"<<endl;
		cout<<"9. MOSTRAR MEMORIA"<<endl;
		cout<<"10. SALIR"<<endl;
		cout<<endl<<"SELECIONE OPCION: ";
		cin>>valor;
		switch(valor)
		{
		   case 1:cout<<endl<<"MEMORIA CREADA"<<endl<<endl;
				 m=new CSMemoria();
				 break;
		   case 2:cout<<endl<<"COLA CREADA"<<endl<<endl;
				 CEOAO= new ColaEOAO(m);
				 break;
		  case 3:int x;
				 cout<<endl<<"INGRESE VALOR:"; cin>>x;
				 CEOAO->Poner(x);
				 cout<<endl;
				 break;
		  case 4:cout<<CEOAO->mostrar();
				 break;
		  case 5:cout<<endl<<"PILA CREADA"<<endl<<endl;
				 PEOAO=new PilaEOAO(m);
				 break;
		  case 6:int y;
				 cout<<endl<<"INGRESE VALOR: ";
				 cin>>y;
                 cout<<endl;
				 PEOAO->meter(y);
				 break;
		  case 7:cout<<endl<<PEOAO->mostrar();
				 break;
		  case 8:cout<<endl<<"COLA INVERTIDA"<<endl<<endl;
				 invertir(CEOAO);
				 break;
		  case 9: m->mostrar_memoria();
				 break;
		  case 10:cout<<endl<<endl<<"PROGRAMA FINALIZADO"<<endl<<endl; break;
		};
	 }
	system("PAUSE");
	return 0;
}