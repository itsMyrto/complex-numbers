#include "complex_number.h"
#include <iostream>

using namespace std;

complex_number::complex_number()
{
	a = 1;
	b = 1;
}

complex_number::complex_number(double num1,double num2)
{
	a = num1;
	b = num2;
}

ostream& operator << (ostream& o, complex_number& obj)
{
	
	if (obj.a == 0 && obj.b == 0)
	{
		o << 0 ;
	}
	else if (obj.a == 0 && (obj.b > 1 || obj.b<-1))
	{
		o << obj.b << "i" ;
	}
	else if (obj.a == 0 && obj.b == -1)
	{
		o << "-i" ;
	}
	else if (obj.a == 0 && obj.b == 1)
	{
		o << "i" ;
	}
	else if (obj.b == 0)
	{
		o << obj.a;
	}
	else if (obj.a != 0 && (obj.b > 1 || (obj.b > 0 && obj.b < 0)))
	{
		o << obj.a << "+" << obj.b << "i";
	}
	else if (obj.a != 0 && (obj.b < -1 || (obj.b >-1 && obj.b < 0)))
	{
		o << obj.a << obj.b << "i" ;
	}
	else if (obj.a != 0 && obj.b == 1)
	{
		o << obj.a << "+" << "i";
	}
	else if (obj.a != 0 && obj.b == -1)
	{
		o << obj.a << "-i" ;
	}
	else
	{

	}

	return o;
}	

complex_number& operator + (complex_number& obj,complex_number& obj2)
{
	complex_number* temp = new complex_number();
	temp->a = obj.a + obj2.a;
	temp->b = obj.b + obj2.b;
	return *temp;
}

complex_number& operator * (complex_number& obj, complex_number& obj2)
{
	complex_number* temp = new complex_number();
	temp->a = obj.a * obj2.a - obj.b * obj2.b;
	temp->b = obj.a * obj2.b + obj.b * obj2.a;
	return *temp;
}

complex_number& complex_number::operator = (complex_number& obj)
{
	this->a = obj.a;
	this->b = obj.b;

	return *this;
}

complex_number& complex_number::operator *= (complex_number& obj)
{
	complex_number* temp = new complex_number();
	temp->a = obj.a * this->a - obj.b * this->b;
	temp->b = obj.a * this->b + obj.b * this->a;
	this->a = temp->a;
	this->b = temp->b;
	return *this;
}

complex_number& complex_number::operator += (complex_number& obj)
{
	this->a = obj.a + this->a;
	this->b = obj.b + this->b;
	return *this;
}

double& complex_number::operator [] (int num)
{
	if (num == 0)
	{
		return this->a;
	}
	else 
	{
		return this->b;
	}
}

complex_number& operator / (complex_number& obj1, complex_number& obj2)
{
	complex_number* temp = new complex_number();
	temp->a = (obj1.a * obj2.a + obj1.b * obj2.b) / (obj2.a * obj2.a +obj2.b * obj2.b);
	temp->b = (obj1.b * obj2.a - obj1.a * obj2.b) / (obj2.a * obj2.a + obj2.b * obj2.b);
	return *temp;
}