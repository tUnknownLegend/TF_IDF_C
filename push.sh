cd ./iterative/project
rm -r ./build
cd ../../parallel/project
rm -r ./build
git add -A
git commit -m "ci"
git push origin