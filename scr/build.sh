cd /${{ github.workspace }}
cd ./project/
rm -r ./build
mkdir ./build
cd ./build
cmake ..
cmake --build .