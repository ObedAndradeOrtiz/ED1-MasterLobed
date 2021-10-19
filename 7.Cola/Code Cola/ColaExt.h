//---------------------------------------------------------------------------

#ifndef ColaExtH
#define ColaExtH
//---------------------------------------------------------------------------
const int maxim=10;
class ColaExt
{
    private:
		   int *v;
		   int ini, fin;
		   int siguiente(int e);
	public:
		  ColaExt();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
          void mostrar();
};
#endif
