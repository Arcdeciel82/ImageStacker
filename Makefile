CC = g++ # using g++ for compilation
CFLAGS = -g -Wall -Wextra # flags for all warnings, extra warning, and debugging
TARGET = stacker # Target binary


all: $(TARGET)

$(TARGET): main.o stacker.o ppm.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o stacker.o ppm.o

stacker.o: ppm.h stacker.h stacker.cpp
	$(CC) $(CFLAGS) -c stacker.cpp

ppm.o: ppm.h ppm.cpp
	$(CC) $(CFLAGS) -c ppm.cpp

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~ 
