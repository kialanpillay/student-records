CC=g++         
CCFLAGS=-std=c++11
LIBS=-lm      

driver: driver.o database.o
	$(CC) $(CCFLAGS) driver.o database.o -o driver $(LIBS)

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) -c database.cpp $(LIBS)

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp $(LIBS)
   
clean:
	@rm -f *.o
	@rm driver
   
# copies/moves the relevant binaries and/or libraries to the correct folders   
install:
	@mv driver ~/bin
