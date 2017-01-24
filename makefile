CC = g++
CF = 
a.out: main.o tools.o validationtree.o node.o interface.o
	$(CC) $(CF) main.o tools.o validationtree.o node.o interface.o -o a.out
main.o: main.cpp tools.h validationtree.h node.h interface.h
	$(CC) $(CF) -c main.cpp
tools.o: tools.cpp tools.h
	$(CC) $(CF) -c tools.cpp
validationtree.o: validationtree.cpp validationtree.h node.h interface.h tools.h
	$(CC) $(CF) -c validationtree.cpp
node.o: node.cpp node.h interface.h tools.h
	$(CC) $(CF) -c node.cpp
interface.o: interface.cpp interface.h tools.h node.h
	$(CC) $(CF) -c interface.cpp
stdout: a.out
	./a.out < in.txt && echo "\n"
diff: a.out
	./a.out < in.txt > out.txt && diff cout.txt out.txt
clean:
	rm -rf *.o ~* .DS_Store