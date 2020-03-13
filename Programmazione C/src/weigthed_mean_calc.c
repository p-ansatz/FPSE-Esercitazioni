#include <stdio.h>

float weighted_mean(int x[], int w[], int n) { 
    int w_sum = 0, num = 0; 
  
    for (int i = 0; i < n; i++){ 
        num = num + x[i] * w[i]; 
        w_sum = w_sum + w[i]; 
    } 
  
    return (float)(num / w_sum);
} 
  
int main(){ 

    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
  
    int n = sizeof(x)/sizeof(x[0]); 
    int m = sizeof(w)/sizeof(w[0]); 
 
    if (n == m){ 
        float result = weighted_mean(x, w, n); 
        printf("Weigthed mean: %g\n",result);
    }else{
        printf("n!=m\n");
        return -1;
    }
    return 0; 
}  
