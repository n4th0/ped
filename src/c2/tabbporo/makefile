CC=g++
OPTS=-g -Wall -std=c++11
tests= 01 03 05 06 07 08 09 10 11 16 17
LIB=./lib/tporo.cpp ./lib/tvectorporo.cpp ./lib/tabbporo.cpp
INCLUDE=./include/tporo.h ./include/tabbporo.h ./include/tvectorporo.h

testArbol.o: $(LIB)  $(INCLUDE)
	$(foreach var,$(tests), $(CC) $(OPTS) -c ./tabbporo/TABBPoro-$(var).cpp -o ./tabbporo/TABBPoro-$(var).o;)
	touch testArbol.o



