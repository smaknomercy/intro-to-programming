#include <stdio.h>
#include "c_vector.h"

int main() {
    Vector* vector = create(4);
    if (!vector) {
        printf("Failed to create vector.\n");
        return 1;
    }

    vector->push_back(vector, 10);
    vector->push_back(vector, 20);
    vector->push_back(vector, 30);
    vector->push_back(vector, 40);
    vector->push_back(vector, 50);

    printf("Vector elements after push_back: ");
    vector->print(vector);

    printf("Size: %d\n", vector->get_size(vector));
    printf("Capacity: %d\n", vector->get_capacity(vector));

    vector->pop_back(vector);
    printf("Vector elements after pop_back: ");
    vector->print(vector);

    vector->clear(vector);
    printf("Vector elements after clear: ");
    vector->print(vector);

    vector->destroy(vector);
    return 0;
}
