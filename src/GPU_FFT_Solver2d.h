#ifndef GPU_FFT_SOLVER_H
#define GPU_FFT_SOLVER_H
#include <flgl.h>
#include <flgl/logger.h>
#include "FFT_Solver2d.h"
LOG_MODULE(seqfft);

class GPU_FFT_Solver2d : public FFT_Solver2d {
private:
	// TODO add members
public:
	GPU_FFT_Solver2d(size_t n, float* buff);
	virtual ~GPU_FFT_Solver2d();

	virtual void forward() override final;
	virtual void inverse() override final;
};

#endif
