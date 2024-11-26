#include <assert.h>
#include "c_vector.h"

void test_vector() {
    Vector* vector = create(4);
    assert(vector != NULL);
    assert(vector->get_size(vector) == 0);
    assert(vector->get_capacity(vector) == 4);

    vector->push_back(vector, 1);
    vector->push_back(vector, 2);
    vector->push_back(vector, 3);
    vector->push_back(vector, 4);

    assert(vector->get_size(vector) == 4);
    assert(vector->get_capacity(vector) == 4);

    vector->push_back(vector, 5);
    assert(vector->get_size(vector) == 5);
    assert(vector->get_capacity(vector) == 8);

    vector->pop_back(vector);
    assert(vector->get_size(vector) == 4);
    assert(vector->get_capacity(vector) == 8);

    vector->clear(vector);
    assert(vector->get_size(vector) == 0);
    assert(vector->get_capacity(vector) == 8);

    vector->destroy(vector);
}

int main() {
    test_vector();
    printf("All tests passed successfully.\n");
    return 0;
}
