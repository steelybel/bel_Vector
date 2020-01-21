//tVector.h

#pragma once
#include <stdlib.h>

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;
	size_t arrSize;
	size_t arrCapacity;

public:
	tVector();
	~tVector();

	tVector(const tVector &vec);              // copy constructs a vector from another vector

	tVector& operator=(const tVector &vec);   // copies the contents of the provided vector into this vector

	T& operator[] (size_t index); // returns the object at the given index

	T *data();

	void reserve(size_t newCapacity);

	void push_back(const T &value);
	void pop_back();

	T &at(size_t index);
	size_t size() const;
	size_t capacity() const;

	bool empty() const;   // Returns true if the vector contains no elements.
	void resize(size_t);  // Resizes the vector to contain the given number of elements.
	void shrink_to_fit(); // Resizes the vector's capacity to match its size.
	void clear();         // Empties the vector (all elements are destroyed in this process)
};

template<typename T>
inline tVector<T>::tVector()
{
	arrSize = 0;
	arrCapacity = 1;
	arr = new T[1];
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete arr;
	arrSize = 0;
	arrCapacity = 0;
}

template<typename T>
inline tVector<T>::tVector(const tVector & vec)
{
	arrSize = vec.size();
	arrCapacity = vec.capacity();
	arr = const_cast<tVector&>(vec).data();
}

template<typename T>
inline tVector<T> & tVector<T>::operator=(const tVector & vec)
{
	return new tVector(vec);
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	if (index >= arrCapacity || index < 0)
	{
		return NULL;
	}
	else
	{
		return arr[index];
	}
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	
	T * newArr = new T[newCapacity];
	for (int i = 0; i < arrCapacity; i++)
	{
		newArr[i] = arr[i];
	}
	arr = newArr;
	arrCapacity = newCapacity;
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrCapacity == arrSize)
	{
		reserve(arrCapacity*GROWTH_FACTOR);
	}
	arr[arrSize] = value;
	arrSize++;
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arr[arrSize - 1] = NULL;
	arrSize--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

template<typename T>
inline bool tVector<T>::empty() const
{
	return (arrSize == 0);
}

template<typename T>
inline void tVector<T>::resize(size_t)
{

}

template<typename T>
inline void tVector<T>::shrink_to_fit()
{
	arrCapacity = arrSize;
}

template<typename T>
inline void tVector<T>::clear()
{
}
