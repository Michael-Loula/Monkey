CC = clang++
CXXFLAGS = -Wall -Wno-c++11-extensions
DEPS = token.hpp lexer.hpp

OBJ = lexer.o repl.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)
	rm -f *.o

repl: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)
	rm -f *.o

clean:
	rm -f *.o
	rm -f *.gch
	rm repl