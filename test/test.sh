#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

g++ -std=c++20 "$PROJECT_ROOT/test/gen.cpp" -o "$PROJECT_ROOT/test/gen.out"
g++ -std=c++20 "$PROJECT_ROOT/test/naive.cpp" -o "$PROJECT_ROOT/test/naive.out"
g++ -std=c++20 "$PROJECT_ROOT/abc.cpp" -o "$PROJECT_ROOT/test/main.out"

while true
do
    "$PROJECT_ROOT/test/gen.out" > "$PROJECT_ROOT/test/input.txt"

    "$PROJECT_ROOT/test/naive.out" < "$PROJECT_ROOT/test/input.txt" > "$PROJECT_ROOT/test/out1.txt"
    "$PROJECT_ROOT/test/main.out"  < "$PROJECT_ROOT/test/input.txt" > "$PROJECT_ROOT/test/out2.txt"

    if ! diff -q "$PROJECT_ROOT/test/out1.txt" "$PROJECT_ROOT/test/out2.txt" > /dev/null; then
        echo "WA!"
        cat "$PROJECT_ROOT/test/input.txt"
        echo "--- naive ---"
        cat "$PROJECT_ROOT/test/out1.txt"
        echo "--- main ---"
        cat "$PROJECT_ROOT/test/out2.txt"
        break
    fi
done