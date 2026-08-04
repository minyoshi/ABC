#!/bin/zsh

g++ -std=c++20 gen.cpp -o gen.out
g++ -std=c++20 naive.cpp -o naive.out
g++ -std=c++20 ../abc.cpp -o main.out

while true
do
    ./gen.out > input.txt

    ./naive.out < input.txt > out1.txt
    ./main.out  < input.txt > out2.txt

    if ! diff -q out1.txt out2.txt > /dev/null; then
        echo "WA!"
        cat input.txt
        echo "--- naive ---"
        cat out1.txt
        echo "--- main ---"
        cat out2.txt
        break
    fi
done