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
		Vector();
		{
			m_length = 1;
			m_vector = 0.;      				// default constructor
		}
		
		Vector( int length, double *array)			// user constructor
		{
			m_length=length;
			for (unsigned int i=0; i<length; ++i)
			{
				m_vector[i]=array[i];
			}
		}

		
		
  
};
