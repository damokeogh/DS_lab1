#include "pch.h"
#include "UnorderedArray.h"


//Constructor
//creates Array of the size passed and gives a grow size. Array is empty?
template<typename T>
UnorderedArray<T>::UnorderedArray(int size, int growBy) :
	m_array(0), m_maxSize(0),
	m_growSize(0), m_numElements(0) {

	if (size) 
	{
		m_maxSize = size;
		m_array = new T[m_maxSize];
		// memset is short for 'memory set'
		// It sets a specified block of memory to a specified character, overwriting the original data.			
		memset(m_array, 0, sizeof(T) * m_maxSize);
		m_growSize = ((growBy > 0) ? growBy : 0);
	}
}

//Destructor
template<typename T>
UnorderedArray<T>::~UnorderedArray()
{
	if (m_array != 0) {
		delete[] m_array;
		m_array = 0;
	}
}


//adds another element on to end of array
//only way to add elements?
template <typename T>
void UnorderedArray<T>::push(T val) 
{
	assert(m_array != 0);

	if (m_numElements >= m_maxSize) 
	{
		expand();
		// If growSize is 0, this assert should fail.
		assert(m_numElements < m_maxSize);
	}

	m_array[m_numElements] = val;
	m_numElements++;
}

//removes an element from array
template <typename T>
void UnorderedArray<T>::pop() 
{
	if (m_numElements > 0) 
	{
		m_numElements--;
	}
}

//returns value at passed index
template <typename T>
T & UnorderedArray<T>::operator[](int index) 
{
	assert(m_array != 0 && index <= m_numElements);
	return m_array[index];
}



//Q2 Implementation
template <typename T>
int UnorderedArray<T>::search(T val)
{
	bool present = false;
	for (int i = 0; i < m_numElements - 1; i++)
	{
		if (val == m_array[i] && present != true) 
		{
			return i;
			//i = m_numElements;
			present = true;
		}
	}
	if (present == false)
	{
		return -1;
	}


}

//Q3 Implementation
template <typename T>
void UnorderedArray<T>::remove(int index)
{


}


template <typename T>
void UnorderedArray<T>::clear()
{ 
	m_numElements = 0; 
}

template <typename T>
int UnorderedArray<T>::getSize()
{ 
	return m_numElements; 
}

template <typename T>
int UnorderedArray<T>::getMaxSize()  
{ 
	return m_maxSize; 
}

template <typename T>
int UnorderedArray<T>::getGrowSize() {
	return m_growSize; 
}

template <typename T>
void UnorderedArray<T>::setGrowSize(int val) 
{
	assert(val >= 0);
	m_growSize = val;
}


//
template <typename T>
bool UnorderedArray<T>::expand() 
{
	if (m_growSize <= 0)
	{
		return false;
	}

	T *temp = new T[m_maxSize + m_growSize];
	assert(temp != 0);

	// Copies the values of num bytes from the location pointed by source directly to the 
	//  memory block pointed by destination.
	// Parameters are destination, source and num.
	memcpy(temp, m_array, sizeof(T) * m_maxSize);

	delete[] m_array;
	m_array = temp;

	m_maxSize += m_growSize;

	return true;
}

// Explicit template instantiation
template class UnorderedArray<int>;



