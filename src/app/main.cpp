#include "../lib/sudoku.hpp"

#include <iostream>
#include <span>

using std::cerr;
using std::span;

int main(int argc, char* argv[]) {
  const span<char*> args{argv, static_cast<size_t>(argc)};

  if (args.size() < 2) {
    cerr << "Error: Please provide an sudoku puzzle filename.\n";
    cerr << "Usage: " << args[0] << " <input_puzzle.json>\n";

    return 1;
  }

  return 0;
}
