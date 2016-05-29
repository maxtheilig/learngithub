#include <iostream>
#include <cmath> //for pow-function
#include <utility> //for std::swap-function

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
	double** getMatrix()
	{
		return m_mat;
	}
	friend Matrix operator+(Matrix &a1, Matrix &a2);//overloading
	friend Matrix operator*(Matrix &a1, Matrix &a2);//overloading
	~Matrix()//destructor
	{
        for(int i=0; i<m_rows; ++i){delete[] m_mat[i];}
		delete[] m_mat;
	}
};

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
				prod[i][j]=prod[i][j]+a1.getMatrix()[i][k]*a2.getMatrix()[k][j];}}}
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
			sum[i][j] = a1.getMatrix()[i][j]+a2.getMatrix()[i][j];}}
	Matrix sumClass = Matrix(rows,cols,sum);
	return sumClass;
}

int main()
{
	const int rows1 = 2; const int cols1 = 2;
    double a1[rows1][cols1] = { {1,2},{4,5} };
	const int rows2 = 2; const int cols2 = 2;
	double a2[rows2][cols2] = { {1,2},{4,5} };
	double** ptr_a1 = new double* [rows1];
	for(int i=0; i<rows1; ++i){ptr_a1[i]= new double[cols1];
		for(int j=0; j<cols1; ++j){ptr_a1[i][j]=a1[i][j];}}
	Matrix matrix1{rows1,cols1,ptr_a1};
	matrix1.print();
	double** ptr_a2 = new double* [rows2];
	for(int i=0; i<rows2; ++i){ptr_a2[i]= new double[cols2];
		for(int j=0; j<cols2; ++j){ptr_a2[i][j]=a2[i][j];}}
	Matrix matrix2{rows2,cols2,ptr_a2};
	matrix2.print();
	Matrix summat = matrix1 + matrix2;
	summat.print();
	return 0;
}


