#!/bin/bash
echo "START"

echo "Start H file"
find -maxdepth 1 -name "*.h" > H_lista_plikow.txt
Hcount=`cat H_lista_plikow.txt | wc -l`
echo "$Hcount"

START=1
END=3
echo "Countdown"
for (( c=$START; c<=$END; c++ ))
do
    echo -n "$c "
    #sleep 0.5
done
echo "Boom!"

CPY_DIR="include/"
for ((count=0; count<=$Hcount; count++))
do
plik=`cat H_lista_plikow.txt | sed ${count}'q;d'`
cp -f $plik $CPY_DIR
done


if echo $? == 0
then 
    echo "copy Hfile done"
fi


echo "Start C file"
find -maxdepth 1 -name "*.c" > C_lista_plikow.txt
Ccount=`cat C_lista_plikow.txt | wc -l`
echo $Ccount

echo "Countdown"
for (( c=$START; c<=$END; c++ ))
do
	echo -n "$c "
	#sleep 0.5
done
echo "Boom!"

CCPY_DIR="Cfile/"
for ((count=0; count<=$Ccount; count++))
do
plik=`cat C_lista_plikow.txt | sed ${count}'q;d'`
cp -f $plik $CCPY_DIR
done


if echo $? == 0
then 
    echo "copy Cfile done"
fi


echo "END"
