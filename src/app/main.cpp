#include <fstream>
#include <iostream>
#include <span>
#include <string>
#include <nlohmann/json.hpp>
#include "../lib/sudoku.hpp"

using nlohmann::json;
using std::cerr;
using std::endl;
using std::ifstream;
using std::span;
using std::string;

int main(int argc, char* argv[]) {
  const span<char*> args{argv, static_cast<size_t>(argc)};

  if (args.size() < 2) {
    cerr << "Error: Please provide an sudoku puzzle filename." << endl;
    cerr << "Usage: " << args[0] << " <input_puzzle.json>" << endl;

    return 1;
  }

  const string filename = args[1];

  ifstream file(args[1]);

  if (!file.is_open()) {
      cerr << "Error: Could not open file: " << args[1] << endl;

      return 1;
  }

  json puzzle_json;

  try {
    file >> puzzle_json;
  } catch (const json::parse_error& e) {
    cerr << "Error: Invalid JSON format in " << filename << ": " << e.what() << endl;

    return 1;
  }

  if (!is_valid_sudoku_content(puzzle_json)) {
    cerr << "Error: invalid sudoku content in " << args[1] << endl;

    return 1;
  }

  return 0;
}
