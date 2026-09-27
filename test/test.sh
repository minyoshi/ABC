#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
TEST_DIR="$PROJECT_ROOT/test"
CASE_DIR="$TEST_DIR/testcases"
TMP_DIR="$TEST_DIR/tmp"

mkdir -p "$CASE_DIR" "$TMP_DIR"

# Colors
GREEN='\033[32m'
RED='\033[31m'
CYAN='\033[36m'
RESET='\033[0m'
BOLD='\033[1m'

# Spinner
SPINNER=('⠋' '⠙' '⠹' '⠸' '⠼' '⠴' '⠦' '⠧' '⠇' '⠏')

# Progress bar
BAR_WIDTH=20

g++ -std=c++20 "$TEST_DIR/gen.cpp" -o "$TMP_DIR/gen.out"
g++ -std=c++20 "$TEST_DIR/naive.cpp" -o "$TMP_DIR/naive.out"
g++ -std=c++20 "$PROJECT_ROOT/abc.cpp" -o "$TMP_DIR/main.out"

count=0
spinner_index=0
start_time=$(date +%s)

# Ctrl+C
handle_interrupt() {
    elapsed=$(( $(date +%s) - start_time ))

    printf "\r\033[K"
    printf "${RED}${BOLD}✗ 中断${RESET}  %'d tests  │  %ds\n" \
        "$count" "$elapsed"

    exit 130
}

trap handle_interrupt SIGINT

while true
do
    "$TMP_DIR/gen.out" > "$CASE_DIR/input.txt"

    "$TMP_DIR/naive.out" < "$CASE_DIR/input.txt" > "$CASE_DIR/expected.txt"
    "$TMP_DIR/main.out"  < "$CASE_DIR/input.txt" > "$CASE_DIR/actual.txt"

    count=$((count + 1))

    if ! diff -q "$CASE_DIR/expected.txt" "$CASE_DIR/actual.txt" > /dev/null; then
        elapsed=$(( $(date +%s) - start_time ))

        printf "\r\033[K"
        printf "${RED}${BOLD}✗ WA${RESET}  %'d tests  │  %ds\n" \
            "$count" "$elapsed"

        echo "--- input ---"
        cat "$CASE_DIR/input.txt"
        echo "--- expected ---"
        cat "$CASE_DIR/expected.txt"
        echo "--- actual ---"
        cat "$CASE_DIR/actual.txt"

        break
    fi

    if (( count % 5 == 0 )); then
        elapsed=$(( $(date +%s) - start_time ))

        spinner="${SPINNER[$spinner_index]}"
        spinner_index=$(( (spinner_index + 1) % ${#SPINNER[@]} ))

        progress=$(( (count / 50) % (BAR_WIDTH + 1) ))

        bar=""
        for ((i = 0; i < BAR_WIDTH; i++)); do
            if (( i < progress )); then
                bar+="█"
            else
                bar+="░"
            fi
        done

        printf "\r\033[K"
        printf "${CYAN}${BOLD}%s Stress Test${RESET}  ${GREEN}%s${RESET}  %'d tests  │  %ds" \
            "$spinner" "$bar" "$count" "$elapsed"
    fi
done

echo