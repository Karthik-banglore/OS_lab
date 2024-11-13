#!/bin/bash

if [ $# -lt 3 ]; then
  echo "Usage: $0 <Name> <Age> <Candidate>"
  exit 1
fi

name=$1
age=$2
candidate=$3

echo "Voter Information:"
echo "Name: $name"
echo "Age: $age"
echo "Voting for: $candidate"

if [ "$age" -ge 18 ]; then
  echo "Vote recorded successfully for $candidate."
else
  echo "Sorry, $name. You must be at least 18 to vote."
fi