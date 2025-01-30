CC=g++
OPTS=-g -Wall -std=c++11
tests= 01 02 03 04 05 06 07 08
LIB=./lib/tporo.cpp ./lib/tvectorporo.cpp
INCLUDE= ./include/tporo.h ./include/tvectorporo.h


testTvectorporo.o:  $(LIB) $(INCLUDE)
	$(foreach var,$(tests), $(CC) $(OPTS) -c tporo/tad$(var).cpp -o tporo/tad$(var).o;)
	touch testTvectorporo.o
