#!/bin/bash

is_palindrome() {
  num=$1
  rev=$(echo "$num" | rev)
  if [ "$num" == "$rev" ]; then
    echo "$num is a palindrome"
  else
    echo "$num is not a palindrome"
  fi
}

for arg in "$@"; do
  is_palindrome "$arg"
done