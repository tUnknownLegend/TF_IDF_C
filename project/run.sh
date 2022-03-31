cat "" > ./logs/get_metr.log
bash ../files/get_in_list.sh
rm -r ./build
mkdir build
cd build
cmake ..
cmake --build .
valgrind --tool=memcheck --leak-check=yes ./IT1
cd ./tests
#./test_IT1
#cd ..
#lcov -t "tests/test_IT1" -o coverage.info -c -d src/
#genhtml -o report coverage.info
#cd ./report
#python3 -m http.server 8000
#cd ../
#make check
