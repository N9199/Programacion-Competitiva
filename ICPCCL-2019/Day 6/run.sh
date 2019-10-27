#!/bin/zsh
g++-7 -std=c++11 D.cpp -O2 -w
g++-7 -std=c++11 Dtest.cpp -o test.out -O2 -w

for i in {1..30}
do
    echo $i
    python3 asdfdg.py > "input/L_$i"
    time ./a.out < "input/L_$i" > "output/O_$i"
    time ./test.out < "input/L_$i" > "output/L_$i"
    diff "output/O_$i" "output/L_$i" > "diff/temp_$i"
done