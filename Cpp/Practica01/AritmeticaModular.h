#ifndef ARITMETICAMODULAR_H
#define ARITMETICAMODULAR_H

	#include <iostream>
	#include <list>
	using namespace std;

	class AritmeticaModular{
		private:
			int n;
			int primo1;
			int primo2;
			list<int> lista;
		public:
			AritmeticaModular(int n, int primo1, int primo2 );
			AritmeticaModular(int n);
			AritmeticaModular();
			~AritmeticaModular();
			bool esPrimo();
			int getPrimo1();
			int getPrimo2();
			int getN();
			list<int> getLista();
			void setLista( list<int> lista );
			void setPrimo1( int primo1 );
			void setPrimo2( int primo2 );
			void setN( int n );
			void quitarElementos();
			void llenarLista();
			void imprimirLista();
			void limpiarLista();
			void generarZn();			
	};




#endif
