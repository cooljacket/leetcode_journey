filename=${1:6:${#1}-10}
echo "Start to build "$filename
g++ $1 -std=c++11 -I. -o out
echo "Done build "$filename", start to run"
./out < test_cases/${filename}.txt
