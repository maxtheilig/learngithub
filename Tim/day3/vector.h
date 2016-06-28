#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector
{
  private:
		int m_length;
		double *m_vector;
  
  public:
		Vector()
		{
			m_length = 1;
			m_vector[1] = 0.;      				// default constructor
		}
		
		Vector( int length, double *array)			// user constructor
		{
			m_length=length;
			m_vector= new double[length];
			for (unsigned int i=0; i<length; ++i)
			{
				m_vector[i]=array[i];
			}
		}
		
		void identity(const int length )
		{
			delete[] m_vector;
			m_length = length;
			m_vector = new double[length];
			for (unsigned int i=0; i<length; ++i)
			{
				m_vector[i]=1;
			}
		}
		
		void resize(const int resizedLength)
		{
			if(resizedLength == m_length)
			{
				return;
			}
			else if(resizedLength < m_length)
			{	
				double *copyvector= new double[resizedLength];
				for (unsigned int i=0; i < resizedLength; ++i)
				{
					copyvector[i]=m_vector[i];
				}
				delete[] m_vector;
				m_vector = new double[resizedLength];
				for (unsigned int i=0; i < resizedLength; ++i)
                                {
                                        m_vector[i]=copyvector[i];
                                }
				delete[] copyvector;
				m_length=resizedLength;
			} 
			else 
			{
				double *copyvector = new double[m_length];
                                for (unsigned int i=0; i < m_length; ++i)
                                {
                                        copyvector[i]=m_vector[i];
                                }
                                delete[] m_vector;
                                m_vector = new double[resizedLength];
                                for (unsigned int i=0; i < m_length; ++i)
                                {
                                        m_vector[i] = copyvector[i];
                                }
				for (unsigned int i=m_length; i < resizedLength; ++i)
				{
					m_vector[i] = 0;
				}
                                delete[] copyvector;
                                m_length=resizedLength;
			}
		}

		int getSize()
		{
			return m_length;
		}

		void setToZero()
		{
			for (unsigned int i=0; i < m_length ; ++i)
			{
				m_vector[i]=0;
			}
		}

		double norm(int p)
		{
			double result = 0.;
			for(unsigned int i=0; i<m_length; ++i)
			{
				result += pow(m_vector[i], p);
			}
			result = pow(result, 1.0/p);  
			return result;	 
		}
		
		~Vector ()						// destructor
		{
			delete[] m_vector;
		}

		friend Vector operator+(Vector &vector1, Vector &vector2);
		friend Vector operator-(Vector &vectorleft, Vector &vectorright);
		friend double operator*(Vector &vector1, Vector &vector2);
		friend Vector operator*(Vector &vector, double multiplier);
		friend Vector operator*(double multiplier, Vector &vector);
		friend std::ostream& operator<< (std::ostream &out, const Vector &vector);
		friend std::istream& operator>> (std::istream &in, Vector &vector);
		double& operator()(int index);
};

Vector operator+(Vector &vector1, Vector &vector2)
{
	double* summedArray= new double[vector1.m_length];
	for( unsigned int i=0; i<vector1.m_length; ++i)
	{
		summedArray[i]=vector1.m_vector[i]+vector2.m_vector[i];
	}
	Vector summedVector = Vector(vector1.m_length, summedArray);
	delete[] summedArray ;
	return summedVector;
}

Vector operator-(Vector &vectorleft, Vector &vectorright)
{
	double* subtractedArray= new double[vectorleft.m_length];
        for( unsigned int i=0; i<vectorleft.m_length; ++i)
        {
                subtractedArray[i]=vectorleft.m_vector[i]-vectorright.m_vector[i];
        }
        Vector subtractedVector = Vector(vectorleft.m_length, subtractedArray);
        delete[] subtractedArray;
	return subtractedVector;	
}

double operator*(Vector &vector1, Vector &vector2)
{
	double result=0.;
	for( unsigned int i=0; i< vector1.m_length; ++i)
	{
		result+=vector1.m_vector[i]*vector2.m_vector[i];
	}
	return result;
}

Vector operator*(Vector &vector, double multiplier)
{
	double* scalarMultipliedArray = new double[vector.m_length];
	for(unsigned int i=0; i<vector.m_length ; ++i)
	{
		scalarMultipliedArray[i]= multiplier*vector.m_vector[i];
	}
	Vector scalarMultipliedVector =Vector(vector.m_length, scalarMultipliedArray);
	delete[] scalarMultipliedArray;
	return scalarMultipliedVector;
}

Vector operator*(double multiplier, Vector &vector)
{
	double* scalarMultipliedArray = new double[vector.m_length];
        for(unsigned int i=0; i<vector.m_length ; ++i)
        {
                scalarMultipliedArray[i]= multiplier*vector.m_vector[i];
        }
        Vector scalarMultipliedVector =Vector(vector.m_length, scalarMultipliedArray);
        delete[] scalarMultipliedArray;
        return scalarMultipliedVector;
}

std::ostream& operator<< (std::ostream &out, const Vector &vector)
{
    	out << "(" ; 
	for (unsigned int i=0; i < vector.m_length-1; ++i)
	{
		out << vector.m_vector[i] << ", ";
	}
	out << vector.m_vector[vector.m_length-1] << ")" << '\n' ;
	return out;
}

std::istream& operator>> (std::istream &in, Vector &vector)
{	
	in >> vector.m_length;
	for( unsigned int i=0; i<vector.m_length; ++i)
	{
		in >> vector.m_vector[i];
	}
    	return in;
}

double& Vector::operator()(int index)
{
	if(index < 1 || index > m_length)
	{
		std::cout << "error: wrong vector index" << std::endl;
	}

	return m_vector[index-1];
}

#endif
