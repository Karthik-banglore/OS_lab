echo "Enter hours and minutes: "; read h m
case $h in
  [0-9]|1[0-1]) echo "AM";;
  12) [ "$m" -eq 0 ] && echo "PM" || echo "AM";;
  *) echo "PM";;
esac