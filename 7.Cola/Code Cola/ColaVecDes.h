//---------------------------------------------------------------------------

#ifndef ColaVecDesH
#define ColaVecDesH
//---------------------------------------------------------------------------
const int maximo=10;
class ColaDes
{
	private:
		   int *v;
		   int ini, fin;
	public:
		  ColaDes();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
};
#endif
