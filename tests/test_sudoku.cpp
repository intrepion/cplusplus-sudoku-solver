#include <gtest/gtest.h>
#include "../src/lib/sudoku.hpp" // Include the header for the code we want to test

// TEST is a macro from Google Test to define a test case.
// First argument is the test suite name (group of related tests).
// Second argument is the specific test's name.
TEST(HelloTest, BasicCheck) {
    // We expect the get_hello_message() function to return "Hello from the library!".
    // EXPECT_EQ checks for equality. The test passes if they are equal.
    EXPECT_EQ(get_hello_message(), "Hello from the library!");
}

// You can add more tests here
TEST(HelloTest, NotEmpty) {
    // We can also check that the string is not empty.
    EXPECT_FALSE(get_hello_message().empty());
}
