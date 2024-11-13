#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Usage: $0 <string1> <string2>"
  exit 1
fi

concatenated="$1$2"
echo "Concatenated String: $concatenated"