//----------- ----------------------------------------------------------------

#ifndef pilaH
#define pilaH
//---------------------------------------------------------------------------
typedef int elemento;
const int max=7;
class pila
{
   private:
   int VOPDR[max];
		  int topeOPDR;
   public:
		  pila();
		  bool vacia();
		  void meter(elemento e);
		 void sacar(elemento &e);
		  int cima();
};
#endif
