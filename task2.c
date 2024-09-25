#include <stdio.h>
int main() {
    float num;
    while (1)
    {
        printf("Enter a number: ");
        scanf("%f", &num);
        float *numPtr = &num;
        int *intPtr = (int *)numPtr;
        *intPtr ^= 0x80000000;
        printf("Number with reversed sign: %.9f\n", num);
    }
    return 0;
}