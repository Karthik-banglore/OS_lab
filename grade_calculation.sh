echo "Enter marks of 5 subjects: "; read p c b m comp
total=$((p + c + b + m + comp))
perc=$((total / 5))
case $perc in
  9[0-9]|100) grade="A";;
  8[0-9]) grade="B";;
  7[0-9]) grade="C";;
  6[0-9]) grade="D";;
  4[0-9]) grade="E";;
  *) grade="F";;
esac
echo "Percentage: $perc%, Grade: $grade"