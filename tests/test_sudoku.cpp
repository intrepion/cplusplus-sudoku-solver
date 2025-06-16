#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "../src/lib/sudoku.hpp"

using nlohmann::json;

TEST(IsValidSudokuContent, GivenNoInitialGridPropertyShouldBeFalse) {
  // Arrange
  const json content = R"(
)";

  // Act
  const bool actual = is_valid_sudoku_content(content);

  // Assert
  EXPECT_FALSE(actual);
}
