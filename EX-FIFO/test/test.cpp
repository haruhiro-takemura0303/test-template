#include <gtest/gtest.h>
#include "fifo.h"

// Test class for FIFO
class FIFOTest : public ::testing::Test {
protected:
    FIFO<int, 5> fifo; // Instance of FIFO for testing
};

// Test for Enqueue and Dequeue
TEST_F(FIFOTest, EnqueueDequeueTest) {
    EXPECT_TRUE(fifo.Enqueue(1));  // Enqueue should succeed
    EXPECT_TRUE(fifo.Enqueue(2));  // Enqueue should succeed
    EXPECT_TRUE(fifo.Enqueue(3));  // Enqueue should succeed
    
    int item;
    EXPECT_TRUE(fifo.Dequeue(&item));  // Dequeue should succeed
    EXPECT_EQ(item, 1);                 // Check if the dequeued item is correct
    EXPECT_TRUE(fifo.Dequeue(&item));  // Dequeue should succeed
    EXPECT_EQ(item, 2);                 // Check if the dequeued item is correct
}

// Test for IsEmpty
TEST_F(FIFOTest, IsEmptyTest) {
    EXPECT_TRUE(fifo.IsEmpty());  // Queue should be empty initially
    fifo.Enqueue(1);
    EXPECT_FALSE(fifo.IsEmpty());  // Queue should not be empty after enqueue
}

// Test for IsFull
TEST_F(FIFOTest, IsFullTest) {
    for (int i = 0; i < 5; ++i) {
        EXPECT_TRUE(fifo.Enqueue(i));  // Enqueue should succeed for each item
    }
    EXPECT_FALSE(fifo.Enqueue(5)); // Should return false, queue is full now
}

// Test for GetSize
TEST_F(FIFOTest, GetSizeTest) {
    EXPECT_EQ(fifo.GetSize(), 0);  // Size should be 0 initially
    fifo.Enqueue(1);
    EXPECT_EQ(fifo.GetSize(), 1);  // Size should be 1 after one enqueue
    fifo.Enqueue(2);
    EXPECT_EQ(fifo.GetSize(), 2);  // Size should be 2 after another enqueue
    int item;
    fifo.Dequeue(&item);
    EXPECT_EQ(fifo.GetSize(), 1);  // Size should be 1 after one dequeue
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // Run all the tests
}
