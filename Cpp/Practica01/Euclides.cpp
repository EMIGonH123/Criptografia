#include "Euclides.h"

Euclides::Euclides(){
	this->a = this->b = 0;
}

Euclides::Euclides(int a, int b){
	this->a = a;
	this->b = b;
}

Euclides::~Euclides(){
	cout << "------------------------------------------" << endl;
	cout << "--- Llamando al destructor de Euclides ---" << endl;
	cout << "------------------------------------------" << endl;
}

int Euclides::getA(){
	return a;
}

void Euclides::setA( int a ){
	this->a = a;
}

void Euclides::setB( int b ){
	this->b = b;
}

int Euclides::getB(){
	return b;
}

int Euclides::gcdExtendido( int a, int b, int *x, int *y ){
	// Base Case 
	if (a == 0){ 
	  *x = 0; 
	  *y = 1; 
	  return b; 
	} 

	int x1, y1; // To store results of recursive call 
	int gcd = gcdExtendido(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd;
}
