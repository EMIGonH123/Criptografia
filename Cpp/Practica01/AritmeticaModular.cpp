#include "AritmeticaModular.h"

AritmeticaModular::AritmeticaModular(int n, int primo1, int primo2 ){
	this->n = n;
	this->primo1 = primo1;
	this->primo2 = primo2;
}

AritmeticaModular::AritmeticaModular(int n){
	this->n = n;
	this->primo1 = this->primo2 = 0;
}

AritmeticaModular::AritmeticaModular(){
	this->n = this->primo1 = this->primo2 = 0;
}

AritmeticaModular::~AritmeticaModular(){
	cout << "----------------------------------------------------" << endl;
	cout << "--- Llamando al destructor de Aritmetica Modular ---" << endl;
	cout << "----------------------------------------------------" << endl;
}

bool AritmeticaModular::esPrimo(){
	int contador = 0;
	int i = 1;
	while( i <= n ){
		if( n%(i++) == 0 ){
			contador++;
		}
	}
	if( contador != 2 ){
		return false;
	}return true;
}

int AritmeticaModular::getPrimo1(){
	return primo1;			
}

int AritmeticaModular::getPrimo2(){
	return primo2;			
}

int AritmeticaModular::getN(){
	return n;			
}

list<int> AritmeticaModular::getLista(){
	return lista;
}
void AritmeticaModular::setLista( list<int> lista ){
	this->lista = lista;
}
void AritmeticaModular::setPrimo1( int primo1 ){
	this->primo1 = primo1;			
}
void AritmeticaModular::setPrimo2( int primo2 ){
	this->primo2 = primo2;			
}
void AritmeticaModular::setN( int n ){
	this->n = n;			
}

void AritmeticaModular::imprimirLista(){
	for( auto item : lista ){
		cout << item << ",";
	}cout << endl;
}

void AritmeticaModular::llenarLista(){
	register int i;
	for(i=1; i<n; i++){
		lista.push_back(i);
	}
}

void AritmeticaModular::limpiarLista(){
	
}

void AritmeticaModular::generarZn(){
	
	if( !esPrimo() ){
		cout << "-------------------------------" << endl;
		cout << "--- El numero N no es primo ---" << endl;
		cout << "-------------------------------" << endl;
		quitarElementos();
	}
	cout << "----------------------------" << endl;
	cout << "--- El numero N es primo ---" << endl;
	cout << "----------------------------" << endl;
	imprimirLista();

	int tamLista = lista.size();
	
	cout << "------------------------------------------------" << endl;
	cout << "   El tamaño del arreglo es de " << tamLista << " elementos." << endl;	
	cout << "------------------------------------------------" << endl;

	int aux[tamLista];
	lista.sort();

	int i = 0, j = 0;

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
			if( (matriz[i][j]/10) != 0 ){
				cout << matriz[i][j] <<"  ,"; 			
			}else{
				cout << matriz[i][j] <<"   ,";			
			}
 
		}cout << endl;
	}
}

void AritmeticaModular::quitarElementos( ){
	int i = 1,j = 1;	
	int aux = 1;
	while( aux < n ){
		aux = primo1*(i++);
		if( aux < n ){
			lista.remove(aux);
		}		
		aux = primo2*(j++);
		if( aux < n ){
			lista.remove(aux);
		}	
	}
}
