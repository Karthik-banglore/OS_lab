#!/bin/bash

if [ $# -ne 5 ]; then
  echo "Usage: $0 num1 num2 num3 num4 num5"
  exit 1
fi

sum=0

for num in "$@"; do
  sum=$((sum + num))
done

echo "Sum of numbers: $sum"