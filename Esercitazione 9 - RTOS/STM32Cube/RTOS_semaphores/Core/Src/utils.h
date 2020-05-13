#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <math.h>

void reverse(char* str, int len){
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int itostr(int x, char str[], int d){
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

void ftoa(float n, char* res, int afterpoint){
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = itostr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        itostr((int)fpart, res + i + 1, afterpoint);
    }
}

#endif /* SRC_UTILS_H_ */
