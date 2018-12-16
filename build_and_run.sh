filename=${1:0:${#1}-4}
echo "Start to build "$filename
g++ $1 -std=c++11 -o out
echo "Done build "$filename", start to run"
./out < test_cases/${filename}.txt
