#!/bin/bash

rm a.out
rm -r coverage
coding-style.sh . .
cat coding-style-reports.log