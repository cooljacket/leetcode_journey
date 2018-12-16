filename=${1:0:${#1}-4}
echo $filename
g++ $1 -std=c++11 -o out
./out < test_cases/${filename}.txt
