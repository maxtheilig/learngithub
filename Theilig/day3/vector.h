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
	void setToZero()
	{
		for(unsigned int i=0; i<m_length; ++i)
			m_vec[i] = 0.;
	}
	void printVector()
	{
		for(int i=0; i<m_length; ++i){std::cout << m_vec[i] << "\t";}
		std::cout << std::endl;
	}
	double norm(int p=2)//p-Norm, default 2-Norm
	{
		double res = 0;
		for(int i=0; i<m_length; ++i){res = res + pow(m_vec[i],p);}
		return pow(res,1.0/p);
	}
	int getSize()
	{
		return m_length;///sizeof(*m_vec);
	}
	void resize(const int new_length)
	{
		double* newVector = new double[new_length];
		for(unsigned int i=0; i<new_length; ++i)
			newVector[i] = m_vec[i];
		delete[] m_vec;
		m_vec = new double[new_length];
		m_length = new_length;
		for(unsigned int i=0; i<m_length; ++i)
			m_vec[i] = newVector[i];
		delete[] newVector;
	}
	void doubleVector()
	{
		for(int i=0; i<m_length; ++i){m_vec[i]=2*m_vec[i];}
	}
	double* getVector()//returns pointer to vector
	{
		return m_vec;
	}
	friend Vector operator+(Vector &v1, Vector &v2);//overloading
	friend Vector operator-(Vector &v1, Vector &v2);//overloading
    friend double operator*(Vector &v1, Vector &v2);//scalar product
    friend std::ostream& operator<< (std::ostream &out, Vector &v);//prints class
    friend Vector operator/(Matrix &a, Vector &v);//Ax=b <=> x=A/b
    friend Vector LU(Matrix &a, Vector &v);
	~Vector()//destructor
	{
		delete[] m_vec;
	}
};

double operator*(Vector &v1, Vector &v2)//scalar product
{
    double res = 0.;
    if(v1.m_length != v2.m_length){std::cout << "Dimension Error" << std::endl;}
    for(int i=0; i<v1.m_length; ++i){
        res = res + v1.m_vec[i] * v2.m_vec[i];
    }
    return res;
}

std::ostream& operator<< (std::ostream &out, Vector &v)//print class
{
    out << "length=" << v.m_length << "\n";
    out << "Vector=(";
    for(int i=0; i<v.m_length-1; ++i){
        out << v.m_vec[i] << ",";
    }
    out << v.m_vec[v.m_length-1] << ")" << std::endl;
    return out;
}

Vector operator+(Vector &v1, Vector &v2)//add to vectors with overloading
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

Vector add(Vector &v1, Vector &v2)//add to vectors
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

Vector operator-(Vector &v1, Vector &v2)//subtract: v1-v2
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
