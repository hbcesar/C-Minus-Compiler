#!/bin/sh

make

# executavel em trab2

# c01 até c13

for i in c01 c02 c03 c04 c05 c06 c07 c08 c09 c10 c11 c12 c13
do
    echo "\nTeste $i"
    ./trab2 < in/$i.cm > saida
    diff saida out2/$i.out
done

# err1_01 até err1_03

for i in err1_01 err1_02 err1_03
do
    echo "\nTeste $i"
    ./trab2 < in/$i.cm > saida
    diff saida out2/$i.out
done

# err2_01 até err2_03

for i in err2_01 err2_02 err2_03
do
    echo "\nTeste $i"
    ./trab2 < in/$i.cm > saida
    diff saida out2/$i.out
done


# err3_01 até err3_15

for i in err3_01 err3_02 err3_03 err3_04 err3_05 err3_06 err3_07 err3_08 
do
    echo "\nTeste $i"
    ./trab2 < in/$i.cm > saida
    diff saida out2/$i.out
done

for i in err3_09 err3_10 err3_11 err3_12 err3_13 err3_14 err3_15
do
    echo "\nTeste $i"
    ./trab2 < in/$i.cm > saida
    diff saida out2/$i.out
done