#include "Archivo.h"	

//Constructores
Archivo::Archivo(){
	this->ruta = "";
}

Archivo::Archivo( string ruta ){
	this->ruta = ruta;  
}

//Destructor
Archivo::~Archivo(){
	cout << "-----------------------------------------" << endl;
	cout << "--- Llamando al destructor de Archivo ---" << endl;
	cout << "-----------------------------------------" << endl;
}


void Archivo::setRuta( string ruta ){
	this->ruta = ruta;
}

string Archivo::getRuta(){
	return ruta;
}

void Archivo::setContenido( string contenido ){
	ofstream archivo;
	archivo.open(ruta,ios::out);
	if( archivo.fail() ){
		exit(0);
	}
	archivo << contenido;
	archivo.close();
}

string Archivo::getContenido(){
	ifstream archivo;
	string aux,contenido; 
	
	archivo.open( "./Archivos/prueba.txt"/*+ruta.c_str()*/, ios::in );
	if( archivo.fail() ){
		cout << "No se pudo abrir el archivo." << endl;
		exit(1);
	}
	
	while( !archivo.eof() ){
		getline( archivo, aux );
		contenido += (aux + "\n");
	}
	archivo.close();
	return contenido;
}


