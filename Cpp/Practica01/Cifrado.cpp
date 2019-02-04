#include "Cifrado.h"

Cifrado::Cifrado(){
	this->mensajeOriginal = "";
	this->mensajeCifrado = "";
	this->llave = this->a = this->b = 0;
}

Cifrado::Cifrado( int llave ){
	this->mensajeOriginal = "";
	this->mensajeCifrado = "";
	this->a = this->b = 0;
	this->llave = llave; 
}

Cifrado::Cifrado( int a, int b ){
	this->mensajeOriginal = "";
	this->mensajeCifrado = "";
	this->llave = llave; 
	this->a = a;
	this->b = b;
}

Cifrado::Cifrado( string mensajeOriginal ){
	this->mensajeOriginal = mensajeOriginal;
	this->mensajeCifrado = "";
	this->llave = this->a = this->b = 0;
}

Cifrado::~Cifrado(){
	cout << "-----------------------------------------" << endl;
	cout << "--- Llamando al destructor de Cifrado ---" << endl;
	cout << "-----------------------------------------" << endl;
}

void Cifrado::setMensajeOriginal( string mensajeOriginal ){
	this->mensajeOriginal = mensajeOriginal;
}

string Cifrado::getMensajeOriginal(){
	return mensajeOriginal;
}

string Cifrado::getMensajeCifrado(){
	return mensajeCifrado;
}

void Cifrado::setLlave( int llave ){
	this->llave = llave;
}

void Cifrado::setA( int a ){
	this->a = a;
}

void Cifrado::setB( int b ){
	this->b = b;
}

int Cifrado::getLlave(){
	return llave;
}

int Cifrado::getA(){
	return a;
}

int Cifrado::getB(){
	return b;
}
void Cifrado::cifradoAfin(){
	int i,j,k;
	int tam = mensajeOriginal.size();	
	char nuevoMensaje[tam];
	char aux; 
	//Quitamos saltos de linea dentro del mensaje
	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] == '\n' ){
			mensajeOriginal[i] = ' ';
		}
	}	

	//Pasamos a mayusculas todo el mensaje
	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] != ' ' ){
			mensajeOriginal[i] = toupper(mensajeOriginal[i]);
		}else{
			mensajeOriginal[i] = ' ';
		}
	}

	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] != ' ' ){
			j = int(mensajeOriginal[i]);
			k = ( (j-65)*a + b) % 26;
			k +=65;
			aux = char(k);
			nuevoMensaje[i] = aux;
		}else{
			nuevoMensaje[i] = ' ';
		}
	}
	mensajeCifrado = string( nuevoMensaje );
	cout << mensajeOriginal << endl;
	cout << mensajeCifrado << endl;
}

void Cifrado::cifradoPorCorrimiento(){
	int i,j,k;
	int tam = mensajeOriginal.size();	
	char nuevoMensaje[tam];
	char aux; 
	//Quitamos saltos de linea dentro del mensaje
	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] == '\n' ){
			mensajeOriginal[i] = ' ';
		}
	}	

	//Pasamos a mayusculas todo el mensaje
	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] != ' ' ){
			mensajeOriginal[i] = toupper(mensajeOriginal[i]);
		}else{
			mensajeOriginal[i] = ' ';
		}
	}

	for( i=0; i<tam ; i++){
		if( mensajeOriginal[i] != ' ' ){
			j = int(mensajeOriginal[i]);
			k = ( (j-65) + llave) % 26;
			k +=65;
			aux = char(k);
			nuevoMensaje[i] = aux;
		}else{
			nuevoMensaje[i] = ' ';
		}
	}
	mensajeCifrado = string( nuevoMensaje );
	cout << mensajeOriginal << endl;
	cout << mensajeCifrado << endl;
}







