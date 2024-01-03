#!/bin/bash

mkdir -p coverage
cd coverage

gcc -o unit_tests ../*.c ../tests/*.c --coverage -lcriterion

./unit_tests
echo ""
echo ""

cd ..

gcovr --exclude tests
echo ""
echo ""

gcovr --exclude tests --branches
