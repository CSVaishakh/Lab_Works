echo "Enter the first number"
read n1
echo "Enter the second number"
read n2
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "Choose the operation(1-4)"
read op
case $op in
1)
rs=$(($n1 + $n2))
echo "The sum is $rs";;
2)
rs=$(($n1 - $n2))
echo "The difference is $rs";;
3)
rs=$(($n1 * $n2))
echo "The product is $rs";;
4)
rs=$(($n1 / $n2))
echo "The quotient is $rs";;
*)
echo "Wrong choice entered";;   
esac