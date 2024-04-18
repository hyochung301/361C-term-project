#ifndef SEQUENTIAL_FFT_SOLVER_H
#define SEQUENTIAL_FFT_SOLVER_H
#include <flgl.h>
#include <flgl/logger.h>
#include "FFT_Solver2d.h"

/*
	the FFTs should be performed in place
	FFT buffer is of size (n*n*2)

	Where for i,j from 0 to N-1:
	real part of elem i,j: buffer[2 * (i+N*j)    ]
	imag part of elem i,j: buffer[2 * (i+N*j) + 1]
*/

/*
	The base class has members:
		const size_t N;
		float* const buffer;
*/

class Seq_FFT_Solver2d : public FFT_Solver2d {
private:
	// TODO add members
public:
	Seq_FFT_Solver2d(size_t n, float* buff);
	virtual ~Seq_FFT_Solver2d();

	virtual void forward() override final;
	virtual void inverse() override final;
};

#endif
