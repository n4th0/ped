OPTS=-g -Wall -std=c++11
CC=g++

tvectorporo.o: ./lib/tvectorporo.cpp tporo.o ./include/tvectorporo.h ./include/tporo.h
	$(CC)  ./lib/tvectorporo.cpp -c

tporo.o: ./lib/tporo.cpp ./include/tporo.h
	$(CC)  ./lib/tporo.cpp -c

test:
	make -f ./tporo/makefile
	make -f ./tvectorporo/makefile

tad:  tporo.o tvectorporo.o
	$(CC) $(OPTS) tporo.o tvectorporo.o ./src/tad.cpp -o tad

run:  ./src/tad.cpp 
	make tad > /dev/null
	valgrind -q --tool=memcheck --leak-check=full ./tad


clean:
	rm -rf tad 
	rm -rf *.o 
	rm -rf tporo/*.o 
	rm -rf tvectorporo/*.o 
	rm -rf tlistaporo/*.o 


