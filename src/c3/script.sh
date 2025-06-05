#!/bin/env bash

# echo $1

if [[ $1 == "" ]]; then
  echo "opciones:"
  echo " - tabbporo"
  exit 1
fi

if [[ $1 != "tabbporo" ]]; then
  echo "opciones: "
  echo "tabbporo"

  exit 1
fi

make all

if [[ $1 == "tabbporo" ]]; then
  num=18
  name="tabbporo"
  src="./tabbporo.o ./tporo.o ./tvectorporo.o"
  make test >/dev/null
fi

for ((i = 1; i < $num; i++)); do
  if [[ $i == 2 || $i == 4 || $i == 12 || $i == 13 || $i == 14 || $i == 15 ]]; then
    continue
  fi

  test="./"$name"/TABBPoro-"
  solu="./"$name"/TABBPoro-"

  if [[ i -lt 10 ]]; then
    test=$test"0$i.o"
    solu=$solu"0$i.cpp.sal"
  else
    test=$test"$i.o"
    solu=$solu"$i.cpp.sal"
  fi

  echo $test

  g++ -w $test $src -o tad
  # valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./tad >/tmp/salida 2>/tmp/salida-valgrind
  ./tad >/tmp/salida 2>/tmp/salida-valgrind
  # --leak-check=full

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
