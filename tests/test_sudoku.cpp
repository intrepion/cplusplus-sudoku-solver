#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

#include <nlohmann/json.hpp>
#include "../src/lib/sudoku.hpp"

using nlohmann::json;

TEST_CASE("IsValidSudokuContent returns false for json with no initial_grid property") {
  // Arrange
  const json content = R"({})";

  // Act
  const bool actual = is_valid_sudoku_content(content);

  // Assert
  CHECK_FALSE(actual);
}
