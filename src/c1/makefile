OPTS=-g -Wall -std=c++11
CC=g++

	#valgrind -q --tool=memcheck --leak-check=full ./tad

tlistaporo.o: ./lib/tlistaporo.cpp tporo.o ./include/tlistaporo.h ./include/tporo.h
	$(CC)  ./lib/tlistaporo.cpp -c

tvectorporo.o: ./lib/tvectorporo.cpp tporo.o ./include/tvectorporo.h ./include/tporo.h
	$(CC)  ./lib/tvectorporo.cpp -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	$(CC)  ./lib/tporo.cpp -c

test:
	make -f ./tporo/makefile
	make -f ./tvectorporo/makefile
	make -f ./tlistaporo/makefile

tad:  tporo.o tlistaporo.o ./src/tad.cpp
	$(CC) $(OPTS) tporo.o tlistaporo.o ./src/tad.cpp -o tad

run:  ./src/tad.cpp tad
	valgrind -q --tool=memcheck --leak-check=full ./tad


clean:
	rm -rf tad 
	rm -rf *.o 
	rm -rf tporo/*.o 
	rm -rf tvectorporo/*.o 
	rm -rf tlistaporo/*.o 
	rm -rf ./include/*.gch


