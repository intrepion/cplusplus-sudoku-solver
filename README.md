# cplusplus-sudoku-solver
a sudokpy -m u solver written in C++

[![C/C++ CI](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/intrepion/cplusplus-sudoku-solver/actions/workflows/c-cpp.yml)

## install Meson

```bash
py -m pip install meson ninja
```

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
./builddir/cplusplus-sudoku-solver examples/classic/leetcode1.json
```
