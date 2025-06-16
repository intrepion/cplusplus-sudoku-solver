#include "sudoku.hpp"
#include <fstream>      // For file operations
#include <iostream>     // For error output
#include <nlohmann/json.hpp> // Include the JSON library

using std::cerr;
using std::endl;
using std::ifstream;

// Function to validate a Sudoku JSON file
bool is_valid_sudoku_json(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return false; // File not found or couldn't be opened
    }

    nlohmann::json puzzle_json;
    try {
        file >> puzzle_json; // Parse the JSON from the file
    } catch (const nlohmann::json::parse_error& e) {
        cerr << "Error: Invalid JSON format in " << filename << ": " << e.what() << endl;
        return false; // Invalid JSON
    }

    // A valid Sudoku puzzle is a 9x9 grid, represented as an array of 9 arrays.
    // Each inner array should contain 9 integers (0-9).

    if (!puzzle_json.is_array() || puzzle_json.size() != 9) {
        cerr << "Error: Sudoku puzzle must be an array of 9 rows. Actual size: " << puzzle_json.size() << endl;
        return false;
    }

    for (const auto& row : puzzle_json) {
        if (!row.is_array() || row.size() != 9) {
            cerr << "Error: Each row in Sudoku puzzle must be an array of 9 columns." << endl;
            return false;
        }
        for (const auto& cell : row) {
            if (!cell.is_number_integer() || cell.get<int>() < 0 || cell.get<int>() > 9) {
                cerr << "Error: Sudoku cell values must be integers between 0 and 9." << endl;
                return false;
            }
        }
    }

    return true; // All validations passed
}
