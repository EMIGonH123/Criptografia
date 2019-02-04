#ifndef CIFRADO_H
#define CIFRADO_H

	#include <iostream>
	using namespace std;

	class Cifrado{
		private:
			string mensajeOriginal;
			string mensajeCifrado;
			int llave;
			int a;
			int b;
		public:
			Cifrado();
			Cifrado( int llave );
			Cifrado( int a, int b );
			Cifrado( string mensajeOriginal );
			~Cifrado();
			void setMensajeOriginal( string mensajeOriginal );
			void setLlave( int llave );
			void setA( int a );
			void setB( int b );
			int getLlave();
			int getA();
			int getB();
			string getMensajeOriginal();
			string getMensajeCifrado();
			void cifradoAfin();
			void cifradoPorCorrimiento();
	};
	

#endif
