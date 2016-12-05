GXX=g++
FLAGS=-g -std=c++11

all: build

run: 
	./final input.txt abcaby

build: kmp.o driver.o
	$(GXX) $(FLAGS) kmp.o driver.o -o final

kmp.o: kmp.h kmp.cpp
	$(GXX) $(FLAGS) -c kmp.cpp -o kmp.o

driver.o: kmp.h driver.cpp
	$(GXX) $(FLAGS) -c driver.cpp -o driver.o

clean:
	rm *.o final *~
