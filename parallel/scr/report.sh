cd /${{ github.workspace }}
cd ./project/build
lcov -t "tests/test_IT1" -o coverage.info -c -d src/
genhtml -o report coverage.info 