#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TEST_DIR="$PROJECT_ROOT/test"
CASE_DIR="$TEST_DIR/testcases"
TMP_DIR="$TEST_DIR/tmp"

mkdir -p "$CASE_DIR" "$TMP_DIR"

g++ -std=c++20 "$TEST_DIR/gen.cpp" -o "$TMP_DIR/gen.out"
g++ -std=c++20 "$TEST_DIR/naive.cpp" -o "$TMP_DIR/naive.out"
g++ -std=c++20 "$PROJECT_ROOT/abc.cpp" -o "$TMP_DIR/main.out"

while true
do
    "$TMP_DIR/gen.out" > "$CASE_DIR/input.txt"

    "$TMP_DIR/naive.out" < "$CASE_DIR/input.txt" > "$CASE_DIR/expected.txt"
    "$TMP_DIR/main.out"  < "$CASE_DIR/input.txt" > "$CASE_DIR/actual.txt"

    if ! diff -q "$CASE_DIR/expected.txt" "$CASE_DIR/actual.txt" > /dev/null; then
        echo "WA!"
        echo "--- input ---"
        cat "$CASE_DIR/input.txt"
        echo "--- expected ---"
        cat "$CASE_DIR/expected.txt"
        echo "--- actual ---"
        cat "$CASE_DIR/actual.txt"
        break
    fi
done