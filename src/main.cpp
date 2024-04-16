#include <flgl.h>
#include <flgl/tools.h>
#include <flgl/logger.h>
#include "SolverToy.h"
#include "FFT_Solver2d.h"
LOG_MODULE(testmain);
using namespace glm;

#define N (128)

int main() {

	glconfig.set_flgl_path("fluid-solver-toy/lib/flgl/");
	glconfig.set_shader_path("fluid-solver-toy/shaders/");

	FFTW_FFT_Solver2d* fft;
	SolverToy toy(N);

	toy.set_fft_type(fft);

	toy.run();

	return 0;
}
