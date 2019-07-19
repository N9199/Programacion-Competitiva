#!/bin/zsh
g++-7 -std=c++11 2914.cpp -O2 -w

for i in {1..30}
do
    echo $i
    time ./a.out < "input/L_$i" > "output/O_$i"
    diff "output/O_$i" "output/L_$i" > "diff/temp_$i"
done