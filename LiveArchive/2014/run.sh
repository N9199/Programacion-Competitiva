#!/bin/zsh
g++-7 -std=c++11 J.cpp -O2 -w

for i in {1..27}
do
    echo $i
    time ./a.out < "ignore/J/input/J_$i.in" > "ignore/J/output/O_$i"
    diff "ignore/J/output/O_$i" "ignore/J/output/J_$i.sol" > "ignore/J/diff/temp_$i"
done