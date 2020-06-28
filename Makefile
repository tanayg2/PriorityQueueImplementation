EXEC = run
CC = g++
CFLAGS = -c -g -std=c++11 -Wall
# $(EXEC) has the value of shell variable EXEC, which is run. # run depends on the files main.o util.o heap.o
$(EXEC)	:main.o util.o heap.o element.o
# run is created by the command g++ -o run main.o util.o
# note that the TAB before $(CC) is REQUIRED...
	$(CC) -o $(EXEC) main.o util.o heap.o element.o
# main.o depends on the files main.h main.cpp
main.o	:main.cpp heap.h heap.cpp element.h element.cpp util.h util.cpp
# main.o is created by the command g++ -c -Wall main.cpp # note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) main.cpp

util.o	:util.h util.cpp heap.h heap.cpp element.h element.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o :heap.h heap.cpp element.h element.cpp
	$(CC) $(CFLAGS) heap.cpp

element.o	:element.cpp element.h
	$(CC) $(CFLAGS) element.cpp

clean	:
	rm *.o
