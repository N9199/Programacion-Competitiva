#!/bin/zsh
g++-7 -std=c++11 2905B.cpp -O2 -w

for i in {1..19}
do
    echo $i
    time ./a.out < "ignore/C/input/C_$i" > "ignore/C/output/O_$i"
    diff "ignore/C/output/O_$i" "ignore/C/output/C_$i" > "ignore/C/diff/temp_$i"
done