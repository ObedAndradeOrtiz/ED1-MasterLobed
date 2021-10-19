# include <fstream>
# include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using namespace std;
int contadorDigitos();
int main()
{
	int numeroAux=contadorDigitos();
    cout<<endl<<"LA SUMA DE DIGITOS ES: "<<numeroAux<<endl;
    return 0;
}
int contadorDigitos()
{
	ifstream archivo;
	char letra[80];
	string numeroString;
	int i=0;
	int contador=0;
	archivo.open("datos.txt",ios::in);
    if(archivo.fail())
    {
        cout<<"no se puede abrir";
    }
    while(!archivo.eof())
    {
    	 archivo.getline(letra,80,'\0');
    	 while(letra[i]!='\0')
    	 {
    	 	 if((letra[i]>47)&&(letra[i]<58))
    	 	 {
			   numeroString=letra[i]; 
    	 	   contador=contador+ atoi(numeroString.c_str());	
			 }
    	 	i++;
		 }
		 i=0;	 
	}	
	return (contador);
}
