echo "Enter a character: "; read char
case $char in
  [aAeEiIoOuU]) echo "Vowel";;
  *) echo "Not a vowel";;
esac