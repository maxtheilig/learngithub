#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath> //for pow-function
#include <utility> //for std::swap-function
#include "vector.h"

class Vector;

class Matrix
{
private:
	int m_rows; int m_cols; double** m_mat;
public:
	Matrix()//default constructor: 3x3 unity matrix
	{
		m_rows=3; m_cols=3;
		m_mat = new double* [m_rows];
		for(int i=0; i<m_rows; ++i)
		{
			m_mat[i]=new double[m_cols];
			for(int j=0; j<m_cols; ++j){
				m_mat[i][j] = 0.; if(i==j){m_mat[i][j] = 1.0;}}
		}
	}
	/*Matrix(int rows, int cols, double* array)
	{
		m_rows = rows; m_cols = cols;
		m_mat = new double* [m_rows];
		for(int i=0; i<m_rows; ++i)
        {
			m_mat[i]=new double[m_cols];
			for(int j=0; j<m_cols; ++j)
				m_mat[i][j] = array[i*m_cols+j];
		}
	}*/
    Matrix(int rows, int cols, double** array)
    {
        m_rows = rows; m_cols = cols;
        m_mat = new double* [m_rows];
        for(int i=0; i<m_rows; ++i)
        {
            m_mat[i]=new double[m_cols];
            for(int j=0; j<m_cols; ++j)
                m_mat[i][j] = array[i][j];
        }
    }
	void transpose()
	{
		double **result;
		result = new double*[m_cols];
		for (int i=0; i<m_cols; ++i){result[i]= new double[m_rows];}
		for(int i=0; i<m_rows; ++i){
			for(int j=0; j<m_cols; ++j){
				result[j][i] = m_mat[i][j];}}
        m_mat = new double*[m_cols];
        for (int i=0; i<m_cols; ++i){m_mat[i]= new double[m_rows];}
        std::swap(m_rows,m_cols);
        for(int i=0; i<m_rows; ++i){
			for(int j=0; j<m_cols; ++j){
                m_mat[i][j] = result[i][j];}}
        for(int i=0; i<m_rows; ++i){delete[] result[i];}
		delete[] result;
	}
	void print()
	{
		for(int i=0; i<m_rows; ++i)
		{
			for(int j=0; j<m_cols; ++j){
				std::cout << m_mat[i][j] << "\t";}
			std::cout << std::endl;
		}
	}
	int size()
	{
		return m_cols*m_rows;
	}
	void resize(int new_rows, int new_cols)
    {
		double** new_mat = new double* [new_rows];
		for(int i=0; i<new_rows; ++i){
			new_mat[i]=new double[new_cols];
			for(int j=0; j<new_cols; ++j){
				if(i<m_rows && j<m_cols){
					new_mat[i][j] = m_mat[i][j];}
				else{ new_mat[i][j] = 0.;}}}
		m_rows = new_rows; m_cols = new_cols;
		m_mat = new double*[m_rows];
		for(int i=0; i<m_rows; ++i){
			m_mat[i] = new double[m_cols];
			for(int j=0; j<m_cols; ++j){
				m_mat[i][j] = new_mat[i][j];}}
        for(int i=0; i<m_rows; ++i){delete[] new_mat[i];}
		delete[] new_mat;
	}
	friend Matrix operator+(Matrix &a1, Matrix &a2);//overloading
	friend Matrix operator*(Matrix &a1, Matrix &a2);//overloading
	friend Matrix operator*(Matrix &a, int x);
	friend Matrix operator*(int x, Matrix &a);
    friend Vector operator/(Matrix &a, Vector &v);
	friend std::ostream& operator<< (std::ostream &out, Matrix &a);
	double& operator()(int row, int col);//overloading as member function
	//Matrix& operator= (Matrix &source);//overloading assignment op
	friend Vector LU(Matrix &a, Vector &v);
	~Matrix()//destructor
	{
        for(int i=0; i<m_rows; ++i){delete[] m_mat[i];}
		delete[] m_mat;
	}
};

Vector operator/(Matrix &a, Vector &v)//Ax=b <=> b=A/x
{
    return LU(a,v);
}

Vector LU(Matrix &a, Vector &v)//Solve LGS using LU method
{
	if(a.m_cols != a.m_rows){// || a.m_rows != v.m_length){
		std::cout << "Dimension Error" << std::endl;}
	int n = a.m_rows;
	double* res = new double[n];
	for(int j=0; j<n-1; ++j){
		if(a.m_mat[j][j]==0){std::cout<<"Error: Pivot=0"<<std::endl;}
		for(int k=j+1; k<n; ++k){
			a.m_mat[k][j]=a.m_mat[k][j]/a.m_mat[j][j];
			for(int i=j+1; i<n; ++i){
				a.m_mat[k][i]=a.m_mat[k][i]-a.m_mat[k][j]*a.m_mat[j][i];}
		}
	}
	double** L = new double*[n]; double** R = new double*[n];
	for(int i=0; i<n; ++i){L[i]=new double[n]; R[i]=new double[n];}
	for(int i=0; i<n; ++i){
		for(int j=0; j<i+1; ++j){
			if(i==j){L[i][j]=1.0;}
			else{L[i][j]=a.m_mat[i][j];}}}
	for(int j=0; j<n; ++j){
		for(int i=0; i<j+1; ++i){
			R[i][j]=a.m_mat[i][j];}}
	
	/*Matrix resultClass{a.m_rows,a.m_cols,L};
	return resultClass;*/
	double* x = new double[n]; for(int i=0;i<n;++i){x[i]=0.;}
	for(int i=0; i<n; ++i){//Vorsub
		double c = 0;
		if(i==0){}
		else{
			for(int j=0; j<i; ++j){
				c = c + L[i][j] * x[j];}}
		x[i]=(1/L[i][i])*(v.m_vec[i]-c);}
	for(int i=n-1; i>=0; --i){
		double c = 0;
		if(i==n-1){}
		else{
			for(int j=i+1; j<n; ++j){
                c = c + R[i][j] * res[j];}}
		res[i] = (1/R[i][i])*(x[i]-c);}
	Vector resultClass{n,res};
	return resultClass;
}


/*Matrix& Matrix::operator= (Matrix &source)
{
	m_rows = source.m_rows; m_cols = source.m_cols;
	double** m_mat = new double*[m_rows];
	for(int i=0; i<m_rows; ++i){
		m_mat[i] = new double[m_cols];
		for(int j=0; j<m_cols; ++j){
			m_mat[i][j] = source.m_mat[i][j];}}
	return *this;
}*/ //malloc error=????

double& Matrix::operator()(int row, int col)
{
	if(row < 0 || row >= m_rows|| col < 0 || col >= m_cols){
		std::cout << "Error: Wrong matrix-index" << std::endl;}
	return m_mat[row][col];
}

std::ostream& operator<< (std::ostream &out, Matrix &a)
{
	out << "#rows=" << a.m_rows << ", " << "#cols=" << a.m_cols << "\n";
	out << "Matrix:" << std::endl;
	for(int i=0; i<a.m_rows; ++i){
		for(int j=0; j<a.m_cols; ++j){
			out << a.m_mat[i][j] << "\t";}
		out << "\n";}
	return out;
}

Matrix operator*(int x, Matrix &a)
{
    double** result = new double*[a.m_rows];
    for(int i=0; i<a.m_rows; ++i){
        result[i] = new double[a.m_cols];
        for(int j=0; j<a.m_cols; ++j){
            result[i][j] = x * a.m_mat[i][j];}}
    Matrix resultClass = Matrix{a.m_rows,a.m_cols,result};
    return resultClass;
}

Matrix operator*(Matrix &a, int x)
{
	double** result = new double*[a.m_rows];
	for(int i=0; i<a.m_rows; ++i){
		result[i] = new double[a.m_cols];
		for(int j=0; j<a.m_cols; ++j){
			result[i][j] = x * a.m_mat[i][j];}}
	Matrix resultClass = Matrix{a.m_rows,a.m_cols,result};
	return resultClass;
}			

Matrix operator*(Matrix &a1, Matrix &a2)
{
	if(a1.m_cols!=a2.m_rows){
		std::cout << "Error: Matrices must have same dimension" <<std::endl;
		exit(1);}
	int rows=a1.m_rows; int cols=a2.m_cols;
	double** prod = new double*[rows];
	for(int i=0; i<rows; ++i){
		prod[i] = new double[cols];
		for(int j=0; j<cols; ++j){
			prod[i][j] = 0.;
			for(int k=0; k<a1.m_cols; ++k){
				prod[i][j]=prod[i][j]+a1.m_mat[i][k]*a2.m_mat[k][j];}}}
	Matrix prodClass = Matrix{rows,cols,prod};
	return prodClass;
}

Matrix operator+(Matrix &a1, Matrix &a2)
{
	if(a1.m_rows!=a2.m_rows || a1.m_cols!=a2.m_cols){
		std::cout << "Error: Matrices must have same dimension" <<std::endl;
		exit(1);}
	int rows = a1.m_rows; int cols = a1.m_cols;
	double** sum = new double*[rows];
	for(int i=0; i<rows; ++i){
		sum[i] = new double[cols];
		for(int j=0; j<cols; ++j){
			sum[i][j] = a1.m_mat[i][j]+a2.m_mat[i][j];}}
	Matrix sumClass = Matrix(rows,cols,sum);
	return sumClass;
}

#endif
