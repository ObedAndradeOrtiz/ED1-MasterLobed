//---------------------------------------------------------------------------

#ifndef DiColaVecH
#define DiColaVecH
//---------------------------------------------------------------------------
const int max=10;
//---------------------------------------------------------------------------
class DiColaVec
{
	private:
	 int v[max];
	 int ini, fin;
	public:
		  DiColaVec();
		  bool Vacia();
		  void Poner(int E);
		  void Sacar( int &E);
		  int Primero();
		  int  ultimo();
		  void poner_frente(int E);
		  void sacar_final(int E);
};
#endif
