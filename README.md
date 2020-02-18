# Assignment One: PLLKIA010

## Makefile
The purpose of the Makefile is to automatically compile and link the C++ source files into a binary executable that can be run locally. Run these commands in sequence to interact with the program.
```make``` will compile the files into an executable called ```driver```

```make install``` moves the executable into a seperate *bin* directory 

```make run``` will run this executable file (```./bin/driver```) in your shell.

```make clean``` will delete all object files and the *bin* folder

## database.h

This is a header file that contains the variable and method declarations for the main logic of the program. It declares a ```StudentRecord``` struct to bundle relevant data fields, and a ```vector<StudentRecord>``` to store multiple instances. 
It also declares various methods that correspond to the program functionality, e.g reading and saving to the textfile.

## database.cpp

This file is the actual implementation of the method definitions declared in the ```database.h``` file. It contains the logic for the program, and implements various methods that read and write to a textfile, push records onto the Vector data structure, calculate the average grade of a student, and displays the recorded details of a student.

## driver.cpp

This file contains the main method, and provides an entry point into the program. It consists of a simple menu of options which are continually displayed to the user, until they decide to quit the program. It imports the database.h file in order to provide program functionality. Users can select options 0 - 4, which correspond to a different action e.g. Adding a student, reading the database (textfile). All interaction with the program is done via a Command Line Interface. All input required is clearly prompted.

## General

You can only read in the database once, there is logic to prevent multiple reads of the database. This is to prevent duplicate data being stored into the Vector. If you simply save the database, without reading, you are also prevented from reading in the database. This is because the data is already present in the Vector, and there is no need to access it from persistent storage. Saving the database without reading in first will result in the records being overwritten with the current contents of the vector.
