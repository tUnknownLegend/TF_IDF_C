cd /${{ github.workspace }}
cd ./project/build/
valgrind --tool=memcheck --leak-check=yes ./IT1
