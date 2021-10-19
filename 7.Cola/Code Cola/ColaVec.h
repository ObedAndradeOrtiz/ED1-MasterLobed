//---------------------------------------------------------------------------

#ifndef ColaVecH
#define ColaVecH
const int max=10;
//---------------------------------------------------------------------------
class ColaVec
{
	private:
	 int v[max];
	 int ini, fin;
	public:
		  ColaVec();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
};
#endif
