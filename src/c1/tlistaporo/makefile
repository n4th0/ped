CC=g++
OPTS=-g -Wall -std=c++11
tests= 01 02 03 04 05 06 07 08 09 10 11 12
LIB=./lib/tporo.cpp ./lib/tlistaporo.cpp
INCLUDE=./include/tporo.h ./include/tlistaporo.h

testTlistaporo.o: $(LIB)  $(INCLUDE) # $(OBJ)
	$(foreach var,$(tests), $(CC) $(OPTS) -c tlistaporo/tad$(var).cpp -o tlistaporo/tad$(var).o;)
	touch testTlistaporo.o



