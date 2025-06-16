project('sudoku-solver', 'cpp',
  version: '0.1.0',
  default_options: ['warning_level=3', 'cpp_std=c++23'])

gtest_dep = dependency('gtest', fallback: ['gtest', 'gtest_dep'])
nlohmann_json_dep = subproject('nlohmann_json').get_variable('nlohmann_json_dep')

inc_dirs = include_directories('src/lib')
lib_sudoku = library('sudoku',
  'src/lib/sudoku.cpp',
  include_directories: inc_dirs,
  dependencies: [nlohmann_json_dep],
  install: true)

dep_sudoku = declare_dependency(
  include_directories: inc_dirs,
  link_with: lib_sudoku)

executable('sudoku-solver-app',
  'src/app/main.cpp',
  dependencies: [dep_sudoku, nlohmann_json_dep],
  install: true)

test_exe = executable('test_sudoku',
  [
    'tests/test_main.cpp',
    'tests/test_sudoku.cpp'
  ],
  dependencies : [dep_sudoku, gtest_dep, nlohmann_json_dep])

test('Sudoku Tests', test_exe)
