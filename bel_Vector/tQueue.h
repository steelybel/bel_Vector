// tQueue.h
#pragma once
#include "tVector.h"
#include <stdlib.h>

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue();                             // default initializes the queue
	tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();                           // returns the front-most element

	size_t size() const;                  // returns current number of elements
};

template<typename T>
inline tQueue<T>::tQueue()
{
	vec = new tVector();
}

template<typename T>
inline tQueue<T>::tQueue(size_t count, const T & value)
{
	vec = new tVector();
}

template<typename T>
inline void tQueue<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
inline void tQueue<T>::pop()
{
	vec[0] = NULL;
	for (int v = 1; v < size; v++)
	{
		vec[v - 1] = vec[v];
		vec[v] = NULL;
	}
}

template<typename T>
inline T & tQueue<T>::front()
{
	return vec[0];
}
