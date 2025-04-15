OPTS=-g -Wall -std=c++11
CC=g++

all:  tvectorporo.o tporo.o tabbporo.o

tabbporo.o: ./lib/tabbporo.cpp ./lib/tporo.cpp ./lib/tvectorporo.cpp tporo.o tvectorporo.o ./include/tvectorporo.h ./include/tporo.h
	@$(CC)  ./lib/tabbporo.cpp -g -c 

tvectorporo.o: ./lib/tvectorporo.cpp  tporo.o ./include/tvectorporo.h ./include/tporo.h
	@$(CC)  ./lib/tvectorporo.cpp -g -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	@$(CC)  ./lib/tporo.cpp -g -c

test: 
	@make -f ./tabbporo/makefile
tad:  tporo.o tvectorporo.o tabbporo.o ./src/tad.cpp
	@$(CC) $(OPTS) tporo.o tvectorporo.o tabbporo.o ./src/tad.cpp -g -o tad

run:  ./src/tad.cpp tad tvectorporo.o tporo.o
	@#valgrind -q --leak-check=full --tool=memcheck ./tad
	@#valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./tad
	@#valgrind -q --tool=memcheck ./tad
	@ ./tad

tar: ./include ./lib ./src nombres.txt
	tar cvzf cuad1.tgz include lib src nombres.txt

 #--track-origins=yes --leak-check=full

clean:
	rm -rf tad 
	rm -rf *.o 
	rm -rf tabbporo/*.o
	rm -rf ./include/*.gch


