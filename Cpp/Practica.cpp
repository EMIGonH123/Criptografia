#include <iostream>
#include <string.h>
#include <fstream>
#include <ctype.h>
#include <list>
//#include "GeneracionZn.h"
//#include "Archivo.h"

using namespace std;


string getMensajePorConsola();
void escribirEnArchivo( string mensaje );
string getMensajePorArchivo(); 
void encriptarMensaje( string mensaje, int llave );
void encriptarMensaje( string mensaje, int a, int b );
void quitarElementos( int n, int primo, list<int> &lista );
void llenarLista( int n, list<int> &lista );
void imprimirLista( list<int> lista );
void generarTablaZn();

void menuGeneral();
int getTipoCifrado();
int getTipoFormato();

int main(){
	menuGeneral();

	return 0;
}

void generarTablaZn(){
	int n, primo1, primo2, tamLista;
	register int i,j;
	list<int> lista;

	cout << "-----------------------------" << endl;
	cout << "--- BIENVENIDO AL SISTEMA ---" << endl;
	cout << "-----------------------------" << endl;

	cout << "Valor de N: " << endl;
	cin >> n;
	
	llenarLista(n,lista);

	cout << "Valor del primo 1: " << endl;
	cin >> primo1;

	cout << "Valor del primo 2: " << endl;
	cin >> primo2;

	imprimirLista( lista );

	//Quitamos lo multiplos de los factores dentro de la lista
	quitarElementos(n,primo1, lista);
	quitarElementos(n,primo2, lista);

	imprimirLista( lista );

	tamLista = lista.size();
	
	cout << "-----------------------------------------" << endl;
	cout << "El tamaño del arreglo es de " << tamLista << " elementos." << endl;	
	cout << "-----------------------------------------" << endl;

	int aux[tamLista];
	lista.sort();

	i=0;

	//Asignamos los valores de la lista a el vector auxiliar
	for(list<int>::iterator m=lista.begin(); m != lista.end(); m++){
		aux[i++] = *m;
	}

	//Declaramos la matriz
	int matriz[tamLista][tamLista];

	cout << "-----------------------------" << endl;
	cout << "--- DATOS DE LA TABLA Zn* ---" << endl;
	cout << "-----------------------------" << endl;
	//fflush(stdin);
	i=0;
	for(i=0;i<tamLista;i++){
		j=0;		
		for(j=0;j<tamLista;j++){
			matriz[i][j] = (aux[i] * aux[j]) % n;
			cout << matriz[i][j] <<","; 
		}cout << endl;
	}
}


void imprimirLista( list<int> lista ){
	cout << "-------------------------" << endl;
	cout << "--- DATOS DE LA LISTA ---" << endl;
	cout << "-------------------------" << endl;
	for( auto item : lista ){
		cout << item << ",";
	}cout << endl;
}

void llenarLista( int n, list<int> &lista ){
	register int i;
	for(i=1; i<n; i++){
		lista.push_back(i);
	}
}

void quitarElementos( int n, int primo, list<int> &lista){
	int i = 1;	
	int aux = 1;
	while( aux < n ){
		aux = primo*(i++);
		if( aux < n ){
			lista.remove(aux);
		}	
	}
}

void encriptarMensaje( string mensaje, int a, int b ){
	int i,j,k;
	int tam =mensaje.size();	
	char nuevoMensaje[tam];
	char aux; 
	//Quitamos saltos de linea dentro del mensaje
	for( i=0; i<tam ; i++){
		if( mensaje[i] == '\n' ){
			mensaje[i] = ' ';
		}
	}	

	//Pasamos a mayusculas todo el mensaje
	for( i=0; i<tam ; i++){
		if( mensaje[i] != ' ' ){
			mensaje[i] = toupper(mensaje[i]);
		}else{
			mensaje[i] = ' ';
		}
	}

	for( i=0; i<tam ; i++){
		if( mensaje[i] != ' ' ){
			j = int(mensaje[i]);
			k = ( (j-65)*a + b) % 26;
			k +=65;
			aux = char(k);
			nuevoMensaje[i] = aux;
		}else{
			nuevoMensaje[i] = ' ';
		}
	}
	cout << mensaje<< endl;
	cout << nuevoMensaje << endl;
}

void encriptarMensaje( string mensaje, int llave ){
	int i,j,k;
	int tam =mensaje.size();	
	char nuevoMensaje[tam];
	char aux; 
	//Quitamos saltos de linea dentro del mensaje
	for( i=0; i<tam ; i++){
		if( mensaje[i] == '\n' ){
			mensaje[i] = ' ';
		}
	}	

	//Pasamos a mayusculas todo el mensaje
	for( i=0; i<tam ; i++){
		if( mensaje[i] != ' ' ){
			mensaje[i] = toupper(mensaje[i]);
		}else{
			mensaje[i] = ' ';
		}
	}

	for( i=0; i<tam ; i++){
		if( mensaje[i] != ' ' ){
			j = int(mensaje[i]);
			k = ( (j-65) + llave) % 26;
			k +=65;
			aux = char(k);
			nuevoMensaje[i] = aux;
		}else{
			nuevoMensaje[i] = ' ';
		}
	}
	cout << mensaje<< endl;
	cout << nuevoMensaje << endl;
}

string getMensajePorArchivo(){
	ifstream archivo;
	string texto = "", aux, ruta; 
	
	cout << "--------------------------------" << endl;
	cout << "--- DAME LA RUTA DEL ARCHIVO ---" << endl;
	cout << "--------------------------------" << endl;
	//cin.ignore(); //Limpiamos el buffer			
	getline(cin, ruta);

	archivo.open( ruta.c_str(), ios::in );
	if( archivo.fail() ){
		cout << "No se pudo abrir el archivo." << endl;
		exit(1);
	}
	
	while( !archivo.eof() ){
		getline( archivo, aux );
		texto += (aux+"\n");
	}
	archivo.close();
	return texto;
}

string getMensajePorConsola(){
	string mensaje;
	cout << "--------------------------" << endl;
	cout << "--- INGRESA EL MENSAJE ---" << endl;
	cout << "--------------------------" << endl;
	//cin.ignore();
	getline(cin, mensaje);
	return mensaje;
}

void escribirEnArchivo( string mensaje ){
	ofstream archivo;
	archivo.open("prueba.txt",ios::out);
	if( archivo.fail() ){
		exit(0);
	}
	archivo << mensaje;
	archivo.close();
}

void menuGeneral(){
	int opcion1, llave,a,b;
	string mensajeOriginal;	
	do{
		cout << "-----------------------------" << endl;
		cout << "--- BIENVENIDO AL SISTEMA ---" << endl;
		cout << "-----------------------------" << endl;
		cout << "----- Elige una opcion ------" << endl;
		cout << "Cifrados..................(1)" << endl;
		cout << "Generacion de 'Zn*'.......(2)" << endl;
		cin >> opcion1;		
		cin.ignore();
	}while( opcion1<1 || opcion1>2 );

	switch( opcion1 ){
		//Cifrados
		case 1:
			switch( getTipoFormato() ){
				//Consola
				case 1:
					mensajeOriginal = getMensajePorConsola();
					cout << "El mensaje es: "<< mensajeOriginal<< endl;
				break;

				//Archivo
				case 2:
					mensajeOriginal = getMensajePorArchivo();
				break;
			}

			switch( getTipoCifrado() ){
				//Cifrado				
				case 1:
					cout << "Dame la llave para encriptar el mensaje: " << endl;
					cin >> llave;
					encriptarMensaje(mensajeOriginal, llave);
				break;

				//Decifrado
				case 2:
					cout << "Dame el valor de a: " << endl;
					cin >> a;

					cout << "Dame el valor de b: " << endl;
					cin >> b;

					encriptarMensaje( mensajeOriginal, a,b);
				break;
			}		
		break;

		//Generacion de la tabla Zn*
		case 2:
			generarTablaZn();
		break;
	}
}

int getTipoCifrado(){
	int opcion1;
	do{
		cout << "------------------------" << endl;
		cout << "--- MENU DE CIFRADOS ---" << endl;
		cout << "------------------------" << endl;
		cout << "--- Elige una opcion ---" << endl;
		cout << "Cifrado1.............(1)" << endl;
		cout << "Cifrado2.............(2)" << endl;
		cin >> opcion1;	
		cin.ignore();	
	}while( opcion1<1 || opcion1>2 );
	return opcion1;
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

