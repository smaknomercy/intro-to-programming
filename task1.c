#include <stdio.h>
int main() {
    // (2 - 2^-23)
    float mantissa = 2.0f - (1.0f / (1 << 23));
    printf("Maximum possible mantissa value: %.10f\n", mantissa);
    return 0;
}