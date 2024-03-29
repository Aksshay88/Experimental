echo "ENTER THE LIMIT:"
read n
p=-1
q=1
i=1
while [ $i -le $n ]; do
    r=`expr $p + $q`
    p=$q
    q=$r
    echo "$r"
    i=`expr $i + 1`
done