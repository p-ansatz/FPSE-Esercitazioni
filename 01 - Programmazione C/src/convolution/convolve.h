#ifndef CONVOLVE_H_INCLUDED_

#define CONVOLVE_H_INCLUDED_

void array_fill(float *a, int a_size);
void array_print(float *a, int a_size);
float* conv(float *f, float *g, int f_size, int g_size, int* C_size);

#endif