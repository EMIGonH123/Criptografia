#ifndef EUCLIDES_H
#define EUCLIDES_H

	#include <iostream>
	using namespace std;

	class Euclides{
		private:
			int a,b;
		public:
			Euclides();
			Euclides(int a, int b);
			~Euclides();
			void setA( int a );
			void setB( int b );
			int getB();
			int getA();
			int gcdExtendido( int a, int b, int *x, int *y );
	};

#endif
