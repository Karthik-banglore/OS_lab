echo "Enter year:"; read y
if ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0)); then echo "Leap Year"; else echo "Not a Leap Year"; fi