OPTS=-g -Wall -std=c++11
CC=g++

all: tlistaporo.o tvectorporo.o tporo.o

tlistaporo.o: ./lib/tlistaporo.cpp tporo.o ./include/tlistaporo.h ./include/tporo.h
	@$(CC)  ./lib/tlistaporo.cpp -g -c

tvectorporo.o: ./lib/tvectorporo.cpp tporo.o ./include/tvectorporo.h ./include/tporo.h
	@$(CC)  ./lib/tvectorporo.cpp -g -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	@$(CC)  ./lib/tporo.cpp -g -c

test:
	@make -f ./tporo/makefile
	@make -f ./tvectorporo/makefile
	@make -f ./tlistaporo/makefile

tad:  tporo.o tvectorporo.o tlistaporo.o ./src/tad.cpp
	@$(CC) $(OPTS) tporo.o tvectorporo.o tlistaporo.o ./src/tad.cpp -g -o tad

run:  ./src/tad.cpp tad tlistaporo.o tvectorporo.o tporo.o
	@#valgrind -q --leak-check=full --tool=memcheck ./tad
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./tad
	@#valgrind -q --tool=memcheck ./tad
	@ ./tad

 #--track-origins=yes --leak-check=full

clean:
	rm -rf tad 
	rm -rf *.o 
	rm -rf tporo/*.o 
	rm -rf tvectorporo/*.o 
	rm -rf tlistaporo/*.o 
	rm -rf ./include/*.gch


