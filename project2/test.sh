#!/bin/bash

#Skrypt do przeprowadzenia testów
#Przyjmuje wielkość elementów do sprawdzenia 1 - 10, 2 - 10^2, 3 - 10^3 etc
#Przeprowadza 20 dla każdej wielkości i typu algorytmu, następnie
#   wylicza średnią dla każdej Grupy 20 testów i wyświetla wyniki

# Funkcja do przeprowadzenia Grupy 20 testów
# $MEAN - średnia czasu
function test {
    echo  ' ' $4 'Tests, type' $1 'size' $2 'sorted' $3
    touch ${OUTDIR}/$1_sort_$3_sorted_$2_size_$4.txt
    for (( i=0; i<$4; i++ ))
    do
        #echo ./sort.out $1 $2 $3
        echo $(./sort.out $1 $2 $3) >> ${OUTDIR}/$1_sort_$3_sorted_$2_size_$4.txt
    done
}

#Grupa testów algorytmu podwajania
echo Tests for "double":

OUTDIR=analysis/tests.tmp
mkdir -p ${OUTDIR}

SIZE[0]=10000
SIZE[1]=50000
SIZE[2]=100000
SIZE[3]=500000
SIZE[4]=1000000

SORTED[0]=0
SORTED[1]=25
SORTED[2]=50
SORTED[3]=75
SORTED[4]=95
SORTED[5]=99
SORTED[6]=99.7
SORTED[7]=-100

TYPE[0]=m
TYPE[1]=q
TYPE[2]=h
TYPE[3]=i

for (( t=0; t<4; t++ ))
do
  for (( srt=0; srt<8; srt++ ))
  do
    for (( s=0; s<5; s++ ))
    do
      test ${TYPE[t]} ${SIZE[s]} ${SORTED[srt]} $1
    done
  done
done
