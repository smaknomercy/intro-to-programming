#include <stdio.h>
int main() {
    int n, binary_num = 0, i = 1, binary_calc, reversed_binary = 0, palindrome_calc, orig_num, orig_binary;

    printf("Enter an integer: ");
    scanf("%d", &n);
    orig_num = n;
    while (n != 0) {
        binary_calc = n % 2;
        n /= 2;
        binary_num += binary_calc * i;
        i *= 10;
    }
    orig_binary = binary_num;

    while (binary_num != 0) {
        palindrome_calc = binary_num % 10;
        reversed_binary = reversed_binary * 10 + palindrome_calc;
        binary_num /= 10;
    }

    if (orig_binary == reversed_binary)
        printf("%d in binary form is %d and it is a palindrome.\n", orig_num, orig_binary);
    else
        printf("%d in binary form is %d and it is NOT a palindrome.\n", orig_num, orig_binary);

    return 0;

}