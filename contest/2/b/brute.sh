for((i = 1; ; ++i)); do
    echo $i
    ./random $i > int
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
#    diff -w <(./b < int) <(./solved < int) || break
    diff -w <(./b < int) <(./solved < int)
done