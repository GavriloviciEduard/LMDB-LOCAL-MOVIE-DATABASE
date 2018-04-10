#pragma once
#include "Movie.h"

template <typename T>
class DynamicVector
{
	public:
		T* movies;
		int len;
		int capacity;

	public:

		DynamicVector(int capacity=10);
		DynamicVector(const DynamicVector& v);
		~DynamicVector();

		DynamicVector& operator=(const DynamicVector& v);

		DynamicVector& operator+(const T& mv);
		void remove(int indx);
		void update(int indx, const T& mn);
		int get_size() const { return len; }
		T* get_all_elements() { return movies; }
		
		void resize(int size = 2);


};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->len = 0;
	this->capacity = capacity;
	this->movies = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->len = v.len;
	this->capacity = v.capacity;
	this->movies = new T[capacity];

	for (int i = 0; i < this->len; i++)
		this->movies[i] = v.movies[i];
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->movies;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->len = v.len;
	this->capacity = v.capacity;

	delete[] this->movies;

	this->movies = new T[this->capacity];
	for (int i = 0; i < this->len; i++)
		this->movies[i] = v.movies[i];

	return *this;
}


template<typename T>
DynamicVector<T>& DynamicVector<T>::operator+(const T& mv)
{

	if (this->len == this->capacity)
		this->resize();

	this->movies[this->len++] = mv;

	return *this;

}


template<typename T>
void DynamicVector<T>::resize(int cap)
{
	this->capacity *= cap;

	T* mov = new T[this->capacity];

	for (int i = 0; i < this->len; i++)
		mov[i] = this->movies[i];

	delete[] this->movies;

	this->movies = mov;
}


template<typename T>
void DynamicVector<T>::remove(int indx)
{

	for (int i = indx; i < this->len - 1; i++)
		this->movies[i] = this->movies[i + 1];

	this->len--;
}


template<typename T>
void DynamicVector<T>::update(int indx, const T& mn)
{
	this->movies[indx] = mn;
}

template<typename T>
inline DynamicVector<T> operator+(const T&mv, DynamicVector<T>& V)
{
	if (V.capacity == V.len)
		V.resize();

	V.movies[V.len++] = mv;

	return V;
}


