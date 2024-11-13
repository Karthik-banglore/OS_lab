echo "Enter two numbers: "; read a b
echo "Enter operator (+ - * /): "; read op
case $op in
  +) echo "Result: $((a + b))";;
  -) echo "Result: $((a - b))";;
  \*) echo "Result: $((a * b))";;
  /) echo "Result: $((a / b))";;
  *) echo "Invalid operator";;
esac