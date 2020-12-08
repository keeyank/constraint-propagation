CC = g++
CFLAGS = -std=c++17 -Wall -Werror -pedantic
TARGET = a
OBJECTS = connector.o constraint.o main.o

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

connector.o : connector.cpp connector.h constraint.h
	$(CC) $(CFLAGS) -c connector.cpp

constraint.o : constraint.cpp constraint.h connector.h
	$(CC) $(CFLAGS) -c constraint.cpp

main.o : main.cpp connector.h constraint.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm $(TARGET) $(OBJECTS)