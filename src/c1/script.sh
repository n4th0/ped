#!/bin/env bash

# echo $1

if [[ $1 == "" ]]; then
  echo "opciones:"
  echo " - tporo"
  echo " - tvector"
  echo " - tlista"
  exit 1
fi

if [[ $1 != "tporo" && $1 != "tvector" && $1 != "tlista" ]]; then
  echo "opciones: "
  echo "tporo"
  echo "tvector"
  echo "tlista"
  echo "aqui"

  exit 1
fi

if [[ $1 == "tporo" ]]; then
  num=11
  name="tporo"
  # lib=""
  src="./tporo.o"
  make test >/dev/null
fi

if [[ $1 == "tvector" ]]; then
  name="tvectorporo"
  num=9
  # lib="./include/tporo.h ./include/tvectorporo.h"
  make test >/dev/null
  src="./tvectorporo.o ./tporo.o"
fi

if [[ $1 == "tlista" ]]; then
  name="tlistaporo"
  num=10
  # lib="./include/tporo.h ./include/tvectorporo.h"
  make test >/dev/null
  src="./tlistaporo.o ./tporo.o"
fi

for ((i = 1; i < $num; i++)); do

  test="./"$name"/tad"
  solu="./"$name"/tad"

  if [[ i -lt 10 ]]; then
    test=$test"0$i.o"
    solu=$solu"0$i.cpp.sal"
  else
    test=$test"$i.o"
    solu=$solu"$i.cpp.sal"
  fi

  echo $test

  g++ -w $test $src -o tad

  valgrind -q --tool=memcheck --leak-check=full ./tad >/tmp/salida 2>/tmp/salida-valgrind

  diff /tmp/salida $solu
  resultOfDiff=$?

  if [[ -s /tmp/salida-valgrind ]]; then
    cat /tmp/salida-valgrind
  else
    if [[ $? != 0 && $resultOfDiff == 0 ]]; then
      echo OK
    fi
  fi

  # diff /tmp/a /tmp/salida-valgrind >/dev/null
  # if [[ $? != 0 ]]; then
  #   cat /tmp/a /tmp/salida-valgrind
  # fi

  echo "---------------------------------------"

  rm /tmp/salida
  rm /tmp/salida-valgrind

done
