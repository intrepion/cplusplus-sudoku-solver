project('sudoku-solver', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3'])

cpp = meson.get_compiler('cpp')

if cpp.get_id() == 'msvc'
  add_project_arguments('/std:c++latest', language: 'cpp')
else
  add_project_arguments('-std=c++23', language: 'cpp')
endif

cmake = import('cmake')
gtest_proj = cmake.subproject('gtest')
gtest_dep = gtest_proj.dependency('gtest_main')
json_dep = dependency('nlohmann_json', fallback: ['nlohmann_json', 'nlohmann_json_dep'])
inc_dirs = include_directories('src/lib')

lib_sudoku = static_library('sudoku',
  'src/lib/sudoku.cpp',
  dependencies: [json_dep],
  include_directories : inc_dirs,
  install : true)

dep_sudoku = declare_dependency(
  include_directories: inc_dirs,
  link_with : lib_sudoku)

executable('sudoku-solver-app',
  'src/app/main.cpp',
  dependencies : [dep_sudoku, json_dep],
  install : true)

test_exe = executable('test_sudoku',
  'tests/test_sudoku.cpp',
  dependencies : [dep_sudoku, gtest_dep, json_dep])

test('Sudoku Tests', test_exe)
