#pragma once
#include "Vetor2D.h"
#include <cmath>

template <typename T>
Vetor2D<T>::Vetor2D(T X, T Y) :
	x { X },
	y { Y }
{
}

template <typename T>
Vetor2D<T>::~Vetor2D()
{
}

template <typename T>
bool Vetor2D<T>::operator==(Vetor2D<T> v)
{
	return (x == v.x && y == v.y);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator+(Vetor2D<T> v)
{
	return Vetor2D<T>(x + v.x, y + v.y);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator-(Vetor2D<T> v)
{
	return Vetor2D<T>(x - v.x, y - v.y);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator*(int i)
{
	return Vetor2D<T>(x * i, y * i);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator*(float f)
{
	return Vetor2D<T>(x * f, y * f);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator*(double d)
{
	return Vetor2D<T>(x * d, y * d);
}

template <typename T>
void Vetor2D<T>::operator+=(Vetor2D<T> v)
{
	x += v.x;
	y += v.y;
}

template <typename T>
T Vetor2D<T>::operator*(Vetor2D<T> v)
{
	return x * v.x + y * v.y;
}

template <typename T>
T Vetor2D<T>::modulo()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

template <typename T>
Vetor2D<T> Vetor2D<T>::versor()
{
	return this->operator*(1.0 / modulo());
}

template <typename T>
Vetor2D<T> Vetor2D<T>::projOrtogonal(Vetor2D<T> v)
{
	return v * (this->operator*(v) / pow(v.modulo(), 2));
}