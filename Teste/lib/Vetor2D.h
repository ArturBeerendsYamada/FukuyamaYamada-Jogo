#ifndef _VETOR2D_H_
#define _VETOR2D_H_

template <typename T>
class Vetor2D
{
public:
	T x, y;

	Vetor2D(T x = 0.0, T y = 0.0);
	~Vetor2D();
	bool operator==(Vetor2D v);
	Vetor2D operator+(Vetor2D v);
	Vetor2D operator-(Vetor2D v);
	Vetor2D operator*(int i);
	Vetor2D operator*(float f);
	Vetor2D operator*(double d);
	void operator+=(Vetor2D v);
	T operator*(Vetor2D v);
	T modulo();
	Vetor2D versor();
	Vetor2D projOrtogonal(Vetor2D v);
};

typedef Vetor2D<float> Vetor2F;
typedef Vetor2D<unsigned> Vetor2U;

#include "Vetor2Dimplementacao.h"

#endif