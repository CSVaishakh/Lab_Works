echo "Enter the number"
read n
x=0
y=1
echo "The Fibonacci series of $n is"
for((i=1;i<=n;i++))
do
    echo "$x"
    f=$(($x + $y))
    x=$y
    y=$f
done