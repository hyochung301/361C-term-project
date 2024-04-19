#include "GPU_FFT_Solver2d.h"
LOG_MODULE(gpufft);


__global__ void hellocuda(int i) {

}

GPU_FFT_Solver2d::GPU_FFT_Solver2d(size_t n, float* buff) : FFT_Solver2d(n, buff) {
	// TODO constructor
	hellocuda<<<1,16>>>(6);
}

GPU_FFT_Solver2d::~GPU_FFT_Solver2d() {
	// TODO destructor
}

void GPU_FFT_Solver2d::forward() {
	// TODO fwd
}

void GPU_FFT_Solver2d::inverse() {
	// TODO inv
}

