#!/bin/sh

TEST_LIST=(
    "test_speed512"
    "test_speed512-90s"
    "test_speed768"
    "test_speed768-90s"
    "test_speed1024"
    "test_speed1024-90s"
    )

for test in ${TEST_LIST[@]}; do
    echo "Running $test..."
    ./$test &> $test-output.txt
done
