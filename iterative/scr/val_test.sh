cd /${{ github.workspace }}
cd ./project/build/tests
valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./test_IT1
