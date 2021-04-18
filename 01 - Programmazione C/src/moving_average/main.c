#include <stdio.h>
#include <stdlib.h>
#include "moving_average_filter.h"

int main(void){
	int n_obs, current_measure, filter_size;
	struct maf fltr;

	printf("Filter size: ");
	scanf("%d", &filter_size);
	int* fltr_arr = (int*)calloc(filter_size,sizeof(int));
	
	// Filter Creation
	fltr = moving_average_filter_create(fltr_arr, filter_size);

	printf("Observation period: ");
	scanf("%d", &n_obs);

	for(short i = 0; i < n_obs; i++){
		printf("Current measure [%d]: ", i+1);
		scanf("%d", &current_measure);
		// Filter Update
		moving_average_filter_update(&fltr, current_measure);
		printf("Total: %d, Average: %.2f, Measure index: %d\n",
			fltr.total, fltr.avg, fltr.idx);
	}
	
	return EXIT_SUCCESS;
}