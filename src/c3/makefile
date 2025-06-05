OPTS=-g -Wall -std=c++11
CC=g++

all:  tvectorporo.o tporo.o tqueueporo.o

tqueueporo.o: ./lib/tqueueporo.cpp ./lib/tporo.cpp ./lib/tvectorporo.cpp tporo.o tvectorporo.o ./include/tvectorporo.h ./include/tporo.h
	@$(CC)  ./lib/tqueueporo.cpp -g -c 

tvectorporo.o: ./lib/tvectorporo.cpp  tporo.o ./include/tvectorporo.h ./include/tporo.h
	@$(CC)  ./lib/tvectorporo.cpp -g -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	@$(CC)  ./lib/tporo.cpp -g -c

# test: 
	# @make -f ./tqueueporo/makefile

tad:  tporo.o tvectorporo.o ./src/tad.cpp tqueueporo.o
	@$(CC) $(OPTS) tporo.o tvectorporo.o  ./src/tad.cpp -g -o tad tqueueporo.o

run:  ./src/tad.cpp tad tvectorporo.o tporo.o
	@#valgrind -q --leak-check=full --tool=memcheck ./tad
	@#valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./tad
	@#valgrind -q --tool=memcheck ./tad
	@ ./tad

tar: ./include ./lib ./src nombres.txt
	tar cvzf cuad2.tgz include lib src nombres.txt

 #--track-origins=yes --leak-check=full

clean:
	rm -rf tad 
	rm -rf *.o 
	rm -rf tqueueporo/*.o
	rm -rf ./include/*.gch


