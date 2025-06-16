# cplusplus-sudoku-solver
a sudoku solver written in C++

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
