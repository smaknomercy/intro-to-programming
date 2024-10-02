#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    int numKey, key;
    char letter, enLetter;
    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &numKey) != 1 || numKey <= 0) {
        printf("Invalid input: must be a positive number.\n");
        return 1;
    }

    srand(time(0));
    key = (rand() % 513) - 256; 
    printf("Generated encryption key: %d\n", key);

    for (int i = 0; i < numKey; i++) {
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &letter);

        if (!isalpha(letter)) {
            printf("Invalid input: must be a valid alphabetic character\n");
            i--;
            continue;
        }

        letter = tolower(letter);
        enLetter = ((letter - 'a' + key) % 26 + 26) % 26 + 'a';
        printf("Encrypted character: %c\n", enLetter);
    }

    return 0;
}
