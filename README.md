# cplusplus-sudoku-solver
a sudoku solver written in C++

[![C/C++ CI](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml)

## build

```bash
meson setup builddir -Db_ndebug=true
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
./builddir/cplusplus-sudoku-solver input_puzzle.json
```
