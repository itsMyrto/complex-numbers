#pragma once
#include <iostream>
using namespace std;

class complex_number
{
private:
	double a;
	double b;
public:
	complex_number();
	complex_number(double, double);
	//void print();
	friend ostream& operator << (ostream&, complex_number&);
	friend complex_number& operator + (complex_number&,complex_number&);
	friend complex_number& operator * (complex_number&, complex_number&);
	complex_number& operator = (complex_number&);
	complex_number& operator *= (complex_number&);
	complex_number& operator += (complex_number&);
	double& operator [] (int);
	friend complex_number& operator / (complex_number&, complex_number&);
};
