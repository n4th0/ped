CC=g++
OPTS=-g -Wall -std=c++11
tests= 01 02 03 04 05 06 07 08 09 10
# OBJ=tad01.o tad02.o tad03.o tad04.o tad05.o tad06.o tad07.o tad08.o tad09.o tad10.o
LIB=./lib/tporo.cpp 
INCLUDE=./include/tporo.h

testTporo.o: $(LIB)  $(INCLUDE) # $(OBJ)
	$(foreach var,$(tests), $(CC) $(OPTS) -c tporo/tad$(var).cpp -o tporo/tad$(var).o;)
	touch testTporo.o



