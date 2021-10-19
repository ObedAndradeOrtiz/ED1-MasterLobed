//---------------------------------------------------------------------------

#ifndef ColaPunteroH
#define ColaPunteroH
//---------------------------------------------------------------------------
struct NodoC{
int dato;
NodoC* sig;
};
class ColaP
{
   private:
		   NodoC* cola;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  ColaP();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
};
#endif
