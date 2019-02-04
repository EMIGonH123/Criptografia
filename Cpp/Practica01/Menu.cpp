#include "Menu.h"
#include "Cifrado.h"
#include "Archivo.h"
#include "Euclides.h"
#include "AritmeticaModular.h"

int getTipoDeCifrado(){
	int opcion1;
	do{
		cout << "-----------------------------" << endl;
		cout << "----- TIPOS DE CIFRADOS -----" << endl;
		cout << "-----------------------------" << endl;
		cout << "----- Elige una opcion ------" << endl;
		cout << "Cifrado por corrimiento...(1)" << endl;
		cout << "Cifrado a fin.............(2)" << endl;
		cin >> opcion1;		
		cin.ignore();
	}while( opcion1<1 || opcion1>2 );
	return opcion1;
}


void menuGeneral(){
	int opcion1, llave, a, b, n, primo1, primo2, x, y, gcd;
	string mensajeOriginal;
	Cifrado *cifrado;	
	Archivo *archivo;
	Euclides *euclides;

	AritmeticaModular *zn;
	do{
		cout << "-----------------------------" << endl;
		cout << "--- BIENVENIDO AL SISTEMA ---" << endl;
		cout << "-----------------------------" << endl;
		cout << "----- Elige una opcion ------" << endl;
		cout << "Cifrados..................(1)" << endl;
		cout << "Decifrados................(2)" << endl;
		cout << "Generacion de 'Zn*'.......(3)" << endl;
		cout << "Inverso multiplicativo....(4)" << endl;
		cin >> opcion1;		
		cin.ignore();
	}while( opcion1<1 || opcion1>4 );

	switch( opcion1 ){
		//Menu de los tipo de cifrado
		case 1:

			cifrado = new Cifrado();
			archivo = new Archivo();
			switch( getTipoFormato() ){
				//Consola
				case 1:
					cifrado->setMensajeOriginal( getMensajePorConsola() );					
				break;

				//Archivo
				case 2:
					archivo->setRuta( getRutaDelArchivo() );
					cifrado->setMensajeOriginal( archivo->getContenido() );
				break;
			} 

			
			switch( getTipoDeCifrado() ){
				//Cifrado por corrimiento				
				case 1:
					cout << "-------------------------------" << endl;
					cout << "--- CIFRADO POR CORRIMIENTO ---" << endl;
					cout << "-------------------------------" << endl;
					cout << "Dame la llave para encriptar el mensaje: " << endl;
					cin >> llave;
					cifrado->setLlave( llave );
					cifrado->cifradoPorCorrimiento();
				break;

				//Cifrado afin
				case 2:
					cout << "--------------------" << endl;
					cout << "--- CIFRADO AFIN ---" << endl;
					cout << "--------------------" << endl;
					cout << "Dame el valor de a: " << endl;
					cin >> a;
					cout << "Dame el valor de b: " << endl;
					cin >> b;
					cifrado->setA( a );
					cifrado->setB( b );
					cifrado->cifradoAfin();
				break;
			}		
		break;
		
		//Decifrados
		case 2:
			cout << "Decifrados" << endl;
		break;

		//Generacion de la tabla Zn*
		case 3:
			cout << "--------------------------" << endl;
			cout << "--- ARITMETICA MODULAR ---" << endl;
			cout << "--------------------------" << endl;
			cout << "Valor de N: " << endl;
			cin >> n;

			cout << "Valor del primo 1: " << endl;
			cin >> primo1;

			cout << "Valor del primo 2: " << endl;
			cin >> primo2;
			zn = new AritmeticaModular( n,primo1, primo2 );
			zn->llenarLista();			
			zn->generarZn();
		break;

		//Inverso multiplicativo(Algoritmo de Euclides)
		case 4:
			cout << "-----------------------------" << endl;
			cout << "--- ALGORITMO DE EUCLIDES ---" << endl;
			cout << "-----------------------------" << endl;
			cout << "Valor de a: " << endl;
			cin >> a;
			cout << "Valor de b: " << endl;
			cin >> b;
			
			euclides = new Euclides( a,b );
			gcd = euclides->gcdExtendido( euclides->getA(), euclides->getB(), &x,&y);
			cout << "GCD: " << gcd << endl;
			cout << gcd << " = (" << euclides->getA() << ")(" <<x<< ") + (" << euclides->getB() << ")(" << y << ")" << endl;
		break;
	}
}

string getMensajePorConsola(){
	string mensaje;
	cout << "--------------------------" << endl;
	cout << "--- INGRESA EL MENSAJE ---" << endl;
	cout << "--------------------------" << endl;
	getline(cin, mensaje);
	return mensaje;
}

string getRutaDelArchivo(){
	string ruta;
	cout << "-----------------------------------" << endl;
	cout << "--- INGRESA LA RUTA DEL ARCHIVO ---" << endl;
	cout << "-----------------------------------" << endl;
	getline(cin, ruta);
	return ruta;
}


int getTipoFormato(){
	int opcion1;
	do{
		cout << "-----------------------" << endl;
		cout << "--- TIPO DE FORMATO ---" << endl;
		cout << "-----------------------" << endl;
		cout << "-- Elige una opcion ---" << endl;
		cout << "Consola.............(1)" << endl;
		cout << "Archivo.............(2)" << endl;
		cin >> opcion1;
		cin.ignore();		
	}while( opcion1<1 || opcion1>2 );
	return opcion1;
}


