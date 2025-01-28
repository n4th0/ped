#!/bin/env bash

# echo $1

if [[ $1 == "" ]]; then
  echo "opciones:"
  echo " - tporo"
  echo " - tvector"
  exit 1
fi

if [[ $1 != "tporo" && $1 != "tvector" ]]; then
  echo "opciones: "
  echo "tporo"
  echo "tvector "
  echo "aqui"

  exit 1
fi

if [[ $1 == "tporo" ]]; then

  touch /tmp/a # fichero auxiliar

  for ((i = 1; i < 11; i++)); do

    test="./tporo/tad"
    if [[ i -lt 10 ]]; then
      test=$test"0$i.cpp"
    else
      test=$test"$i.cpp"
    fi

    solu=$test".sal"

    echo $test

    g++ -w $test ./lib/tporo.cpp -o tad
    valgrind -q --tool=memcheck --leak-check=full ./tad >/tmp/salida 2>/tmp/salida-valgrind

    diff /tmp/salida $solu

    if [[ -s /tmp/salida-valgrind ]]; then
      cat /tmp/salida-valgrind

    else
      if [[ $? != 0 ]]; then
        echo OK
      fi
    fi

    # diff /tmp/a /tmp/salida-valgrind >/dev/null
    # if [[ $? != 0 ]]; then
    #   cat /tmp/a /tmp/salida-valgrind
    # fi

    echo "---------------------------------------"

  done

fi
