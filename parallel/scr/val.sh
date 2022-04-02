cd /${{ github.workspace }}
cd ./project/build/
valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./IT1
