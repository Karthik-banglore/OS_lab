echo "Enter 3 numbers:"; read a b c
if ((a > b && a > c)); then echo $a
elif ((b > c)); then echo $b
else echo $c; fi