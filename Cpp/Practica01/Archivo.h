#ifndef ARCHIVO_H
#define ARCHIVO_H

	#include <string.h>
	#include <iostream>
	#include <fstream>

	using namespace std;

	class Archivo{
		private:
			string ruta;
		public:
			//Constructor
			Archivo();
			Archivo( string ruta );
			~Archivo();

			//Metodos Set y Get de los atributos
			void setRuta( string ruta );
			string getRuta();
			void setContenido( string contenido );
			string getContenido();
	};

#endif
