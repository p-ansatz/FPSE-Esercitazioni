#include <stdlib.h>
#include <stdio.h>
#include "convolve.h"

// Utility Function
void array_fill(float *a, int a_size){
	float val;
	for(int i = 0; i < a_size; ++i){
		printf("Enter element [%d]: ",i);
		scanf("%f", &val);        
		*(a + i) = val;
	}
}
void array_print(float *a, int a_size){
	for (size_t i = 0; i < a_size-1; i++){
		printf("%g | ", a[i]);
	}
	printf("%g", a[a_size-1]);
	printf("\n\n");
}

// 1-D convolution
float* conv(float *f, float *g, int f_size, int g_size, int* C_size){
	int nconv;
	int k;
	float tmp;
	float *C;
	
	// Memory-Alloc
	nconv = f_size+g_size-1;
	C = (float*) calloc(nconv, sizeof(float));
 
	// Convolution process
	for (int i = 0; i < nconv; i++){
		k = i;
		tmp = 0.0;
		for (int j = 0; j < g_size; j++){
			if(k >= 0 && k < f_size){
				tmp = tmp + (f[k]*g[j]);
			}
			k = k-1;
		}
		C[i] = tmp;
	}
 
	(*C_size) = nconv;
 
	return C;
}

int main(){
	// Input Function 1-D
	int f_size, g_size;
	float *f;
	float *g;
	
	printf("Enter number of elements for function f: ");
	scanf("%d", &f_size);

	f = (float*)malloc(f_size*sizeof(float));

	if(f == NULL){
		printf("Error! memory not allocated.");
		return EXIT_FAILURE;
	}
	array_fill(f, f_size);

	printf("Enter number of elements for function g: ");
	scanf("%d", &g_size);

	g = (float*)malloc(g_size*sizeof(float));

	if(g == NULL){
		printf("Error! memory not allocated.");
		return EXIT_FAILURE;
	}
	array_fill(g, g_size);

	// Output function
	float *fcg;
	int fcg_size;
	fcg = conv(f, g, f_size, g_size, &fcg_size);
	
	// Output print
	printf("f: \n");
	array_print(f, f_size);
	printf("g: \n");
	array_print(g, g_size);
	printf("f*c: \n");
	array_print(fcg, fcg_size);

	// Free memory
	free(f);
	free(g);
	free(fcg);

	return EXIT_SUCCESS;
}