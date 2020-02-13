CC=g++         
CCFLAGS=-std=c++11
LIBS=-lm      

driver: driver.o database.o
	$(CC) $(CCFLAGS) driver.o database.o -o driver

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) -c database.cpp

clean:
	@rm -f *.o
	@rm driver
   
run:
	@./driver

install:
	@mv driver ~/bin
