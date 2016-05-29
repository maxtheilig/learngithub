#include <iostream>
#include <cmath>

class Vector
{
private:
	int m_length;
	int* m_vec;

public:
	Vector(){m_length=3; for(int i=0; i<m_length; ++i) m_vec[i]=0;}//default constructor
	Vector(const int length, int* array)//constructor
	{
		m_length = length;
		m_vec = new int[length];
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
			for(int i=m_length-1;i<new_length; ++i) m_vec[i]=0;}
		m_length = new_length;
	}
	int* doubleVector()
	{
		int* res = new int[m_length];
		for(int i=0; i<m_length; ++i){res[i]=2*m_vec[i];}
		return res;
		delete[] res;
	}
	void doubleVector2()
	{
		for(int i=0; i<m_length; ++i){m_vec[i]=2*m_vec[i];}
	}
	int* getVector()
	{
		return m_vec;
	}
	friend Vector operator+(Vector &v1, Vector &v2);//overloading
	friend Vector operator+(Vector &v1, Vector &v2);//overloading
	~Vector()//destructor
	{
		delete[] m_vec;
	}
};

Vector operator+(Vector &v1, Vector &v2)
{
    if(v1.getSize()!=v2.getSize()){
        std::cout << "Error: Vector length has to be equal" << std::endl;
        exit(1);}
    int length = v1.getSize();
    int* sum = new int[length];
    for(int i=0; i<length; ++i){
        sum[i]=v1.getVector()[i]+v2.getVector()[i];}
    Vector sumClass = Vector{length,sum};
    return sumClass;
}

Vector add(Vector &v1, Vector &v2)
{
	if(v1.getSize()!=v2.getSize()){
		std::cout << "Error: Vector length has to be equal" << std::endl;
		exit(1);}
	int length = v1.getSize();
	int* sum = new int[length];
	for(int i=0; i<length; ++i){
		sum[i]=v1.getVector()[i]+v2.getVector()[i];}
	Vector sumClass = Vector{length,sum};
	return sumClass;
}

Vector operator-(Vector &v1, Vector &v2)
{
	if(v1.getSize()!=v2.getSize()){
		std::cout << "Error: Vector length has to be equal" << std::endl;
		exit(1);}
	int length = v1.getSize();
	int* sum = new int[length];
	for(int i=0; i<length; ++i){
		sum[i]=v1.getVector()[i]-v2.getVector()[i];}
	Vector sumClass = Vector{length,sum};
	return sumClass;
}	

int main()
{
	const int length1 = 4;
    const int length2 = 4;
	int vec1[length1] = {1,2,3,4};
    int vec2[length2] = {4,3,2,1};
	Vector vector1{length1,vec1};
    Vector vector2{length2,vec2};
    vector1.printVector();
	vector2.printVector();
	Vector plus = add(vector1, vector2);
	plus.printVector();
	Vector sumvec = vector1 - vector2;
	sumvec.printVector();
	return 0;
}
