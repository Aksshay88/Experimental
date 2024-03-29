echo "enter the range"
read n
x=1
sum=0
while [ $x -le $n ]; do
    sum=`expr $sum + $x`
    x=`expr $x + 2`
done
echo "sum=$sum"