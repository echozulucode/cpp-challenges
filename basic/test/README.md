# Basic GoogleTest

## Build - Manual
```
mkdir /path/to/basic/test/build_test
mkdir /path/to/basic/test/build_test/bin
cd /path/to/basic/test/build_test
cmake -B"." -S".." -G"Unix Makefiles"
cmake --build .
```

## Run Tests - Manual
```
ctest -VV
```
