cd /${{ github.workspace }}
cd ./project/build/tests
valgrind --tool=memcheck --leak-check=yes ./test_IT1
