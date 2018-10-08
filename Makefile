# the compiler to use:
CC = clang++

# compiler flags:
CFLAGS = -g -Wall -std=c++1z 
  
EXECUTABLE = ConconPiler
# files: 
FILES = *.cpp Lexical/*.cpp Syntaxic/*.cpp 

compile:
	$(CC) $(FILES) $(CFLAGS) -o $(EXECUTABLE) 

clean:
	rm $(EXECUTABLE)

# for tests:
BADFILE = ../testInput
GOODFILE = ../test2

good: 
	$(CC) $(FILES) $(CFLAGS) -o $(EXECUTABLE) && ./$(EXECUTABLE) $(GOODFILE) && rm $(EXECUTABLE) 

bad: 
	$(CC) $(FILES) $(CFLAGS) -o $(EXECUTABLE) && ./$(EXECUTABLE) $(BADFILE) && rm $(EXECUTABLE)

vgood: 
	$(CC) $(FILES) $(CFLAGS) -o $(EXECUTABLE) && ./$(EXECUTABLE) -v $(GOODFILE) && rm $(EXECUTABLE) 

vbad: 
	$(CC) $(FILES) $(CFLAGS) -o $(EXECUTABLE) && ./$(EXECUTABLE) -v $(BADFILE) && rm $(EXECUTABLE) 