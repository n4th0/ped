OPTS=-g -Wall -std=c++11
CC=g++

tvectorporo.o: ./lib/tvectorporo.cpp tporo.o ./include/tvectorporo.h ./include/tporo.h
	$(CC) ./lib/tvectorporo.cpp -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	$(CC) ./lib/tporo.cpp -c

test:
	make -f ./tporo/makefile
	make -f ./tvectorporo/makefile



