#!/bin/bash

rm -f a.out
rm -rf coverage
coding-style.sh . .
cat coding-style-reports.log
