# cplusplus-sudoku-solver
a sudokpy -m u solver written in C++

[![C/C++ CI](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml)

## build

```bash
meson setup builddir
```

## compile

```bash
meson compile -C builddir
```

## test

```bash
meson test -C builddir --verbose
```

## run

```bash
./builddir/sudoku-solver-app examples/classic/leetcode/testcase1.json
```

