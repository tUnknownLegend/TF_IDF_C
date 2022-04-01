#!/bin/bash
cur_dir=$(pwd)
cat "" > ./logs/get_metr.log
cat "" > ./logs/get_tf_idf.log
cat "" > ./logs/get_idf.log
cd ../
rm -r ./files_report
mkdir files_report
cd ./files
chmod a+x ./get_in_list.sh
bash ./get_in_list.sh
cd $cur_dir
rm -r ./build
mkdir build
cd build
cmake ..
cmake --build .
valgrind --tool=memcheck --leak-check=yes ./IT1
#./IT1
cd ./tests
#./test_IT1
#cd ..
#lcov -t "tests/test_IT1" -o coverage.info -c -d src/
#genhtml -o report coverage.info
#cd ./report
#python3 -m http.server 8000
#cd ../
#make check
