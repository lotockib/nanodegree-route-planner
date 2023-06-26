// Simple and isolated test to exercise google test macros

#include <gtest/gtest.h>
#include <math.h>

int Squared(int n) {
// Returns the factorial of n
    return pow(n, 2);
}; 

// Tests factorial of 0.
TEST(SquaredTest, HandlesZeroInput) {
  EXPECT_EQ(Squared(0), 0);
}

// Tests factorial of positive numbers.
TEST(SquaredTest, HandlesPositiveInput) {
  EXPECT_EQ(Squared(1), 1);
  EXPECT_EQ(Squared(2), 4);
  EXPECT_EQ(Squared(3), 9);
  EXPECT_EQ(Squared(8), 64);
}