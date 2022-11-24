//Oytun Demirbilek
//150150032
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class vector
{
	public:
		vector();
		vector(int);
		vector operator+(vector&);
		vector operator*(int);
		double operator*(vector&);
		void append(double* newvalues);
		friend ostream& operator<<(ostream&, const vector&);
		~vector();
	private:
		int dimension;
		double* vecarray;
};

#endif


