
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Matrix;

class Vector
{
private:
	int m_length;
	double* m_vec;

public:
	Vector(){m_length=3; for(int i=0; i<m_length; ++i) m_vec[i]=0.;}//default constructor
	Vector(const int length, double* array)//constructor
	{
		m_length = length;
		m_vec = new double[length];
		for(int i=0; i<m_length; ++i){m_vec[i]=array[i];}
	}
	void printVector()
	{
		for(int i=0; i<m_length; ++i){std::cout << m_vec[i] << "\t";}
		std::cout << std::endl;
	}
	double norm(int p)
	{
		double res = 0;
		for(int i=0; i<m_length; ++i){res = res + pow(m_vec[i],p);}
		return pow(res,1.0/p);
	}
	int getSize()
	{
		return m_length;///sizeof(*m_vec);
	}
	void resize(int new_length)
	{
		if(new_length>m_length){
			for(int i=m_length-1;i<new_length; ++i) m_vec[i]=0.;}
		m_length = new_length;
	}
	double* doubleVector()
	{
		double* res = new double[m_length];
		for(int i=0; i<m_length; ++i){res[i]=2*m_vec[i];}
		return res;
		delete[] res;
	}
	void doubleVector2()
	{
		for(int i=0; i<m_length; ++i){m_vec[i]=2*m_vec[i];}
	}
	double* getVector()
	{
		return m_vec;
	}
	friend Vector operator+(Vector &v1, Vector &v2);//overloading
	friend Vector operator-(Vector &v1, Vector &v2);//overloading
    friend std::ostream& operator<< (std::ostream &out, Vector &v);
    friend Vector operator/(Matrix &a, Vector &v);
    friend Vector LU(Matrix &a, Vector &v);
	~Vector()//destructor
	{
		delete[] m_vec;
	}
};

std::ostream& operator<< (std::ostream &out, Vector &v)
{
    out << "length=" << v.m_length << "\n";
    out << "Vector=(";
    for(int i=0; i<v.m_length-1; ++i){
        out << v.m_vec[i] << ",";
    }
    out << v.m_vec[v.m_length-1] << ")" << std::endl;
    return out;
}

Vector operator+(Vector &v1, Vector &v2)
{
    if(v1.m_length!=v2.m_length){
        std::cout << "Error: Vector length has to be equal" << std::endl;
        exit(1);}
    int length = v1.m_length;
    double* sum = new double[length];
    for(int i=0; i<length; ++i){
        sum[i]=v1.m_vec[i]+v2.m_vec[i];}
    Vector sumClass = Vector{length,sum};
    return sumClass;
}

Vector add(Vector &v1, Vector &v2)
{
	if(v1.getSize()!=v2.getSize()){
		std::cout << "Error: Vector length has to be equal" << std::endl;
		exit(1);}
	int length = v1.getSize();
	double* sum = new double[length];
	for(int i=0; i<length; ++i){
		sum[i]=v1.getVector()[i]+v2.getVector()[i];}
	Vector sumClass = Vector{length,sum};
	return sumClass;
}

Vector operator-(Vector &v1, Vector &v2)
{
	if(v1.m_length!=v2.m_length){
		std::cout << "Error: Vector length has to be equal" << std::endl;
		exit(1);}
	int length = v1.m_length;
	double* sum = new double[length];
	for(int i=0; i<length; ++i){
		sum[i]=v1.getVector()[i]-v2.getVector()[i];}
	Vector sumClass = Vector{length,sum};
	return sumClass;
}	

#endif
