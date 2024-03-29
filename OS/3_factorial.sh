echo "ENTER THE NUMBER:"
read n
fact=1
while [ $n -gt 1 ]; do
    fact=`expr $fact \* $n | bc`
    n=`expr $n - 1`
done
echo "FACTORIAL OF THE GIVEN NUMBER IS $fact"