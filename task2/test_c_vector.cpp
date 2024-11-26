#include "gtest/gtest.h"
#include "c_vector.h"

TEST(VectorTest, CreateVector) {
    Vector* vector = create(4);
    ASSERT_NE(vector, nullptr);
    EXPECT_EQ(vector->get_size(vector), 0);
    EXPECT_EQ(vector->get_capacity(vector), 4);
    vector->destroy(vector);
}

TEST(VectorTest, PushBack) {
    Vector* vector = create(2);
    vector->push_back(vector, 10);
    vector->push_back(vector, 20);
    vector->push_back(vector, 30);

    EXPECT_EQ(vector->get_size(vector), 3);
    EXPECT_EQ(vector->get_capacity(vector), 4);
    EXPECT_EQ(vector->data[0], 10);
    EXPECT_EQ(vector->data[1], 20);
    EXPECT_EQ(vector->data[2], 30);

    vector->destroy(vector);
}

TEST(VectorTest, PopBack) {
    Vector* vector = create(2);
    vector->push_back(vector, 10);
    vector->push_back(vector, 20);
    vector->push_back(vector, 30);
    vector->pop_back(vector);

    EXPECT_EQ(vector->get_size(vector), 2);
    EXPECT_EQ(vector->data[0], 10);
    EXPECT_EQ(vector->data[1], 20);

    vector->destroy(vector);
}

TEST(VectorTest, Clear) {
    Vector* vector = create(2);
    vector->push_back(vector, 10);
    vector->push_back(vector, 20);
    vector->clear(vector);

    EXPECT_EQ(vector->get_size(vector), 0);
    EXPECT_EQ(vector->get_capacity(vector), 2);

    vector->destroy(vector);
}

TEST(VectorTest, Destroy) {
    Vector* vector = create(4);
    vector->push_back(vector, 10);
    vector->push_back(vector, 20);
    vector->destroy(vector);

    SUCCEED();
}