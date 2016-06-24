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
			m_vector = 0.;      				// default constructor
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
		
		void int identity( const unsigned int length )
		{
			delete[] m_vector;
			m_vector = new double[length];
			m_length = length;
			for (unsigned int i=0; i<length; ++i)
			{
				m_vector[i]=1;
			}
		}
		
		void int resize(const int rezisedLength)
		{
			if(resizedLength==m_length)
			{
				return;
			}
			else if(resizedLength<m_length)
			{	
				double *copyvector= new double[resizedLength];
				for (unsigned int i=0; i<resizedLength; ++i)
				{
					copyvector[i]=m_vector[i];
				}
				delete[] m_vector;
				m_vector[] = new double[resizedLength];
				for (unsigned int i=0; i<resizedLength; ++i)
                                {
                                        m_vector[i]=copyvector[i];
                                }
				delete [] copyvector
				m_length=rezisedLength;
			} 
			else 
			{
				double *copyvector= new double[m_length];
                                for (unsigned int i=0; i<m_length; ++i)
                                {
                                        copyvector[i]=m_vector[i];
                                }
                                delete[] m_vector;
                                m_vector = new double[resizedLength];
				m_vector[] = {0};
                                for (unsigned int i=0; i<m_length; ++i)
                                {
                                        m_vector[i]=copyvector[i];
                                }
                                delete [] copyvector
                                m_length=rezisedLength;
			}
		}

		int getSize()
		{
			return m_length;
		}


		~Vector ()						// destructor
		{
			delete[] m_vector;
		}
};
