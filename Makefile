CXX = clang++
CXXFLAGS = -Wall -Wno-c++11-extensions
DEPS = token.hpp lextools/lexer.hpp

OBJ = lextools/lexer.o repl.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

repl: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
	rm -f *.o
	rm -f lextools/*.o

clean:
	rm -f *.o
	rm -f *.gch
	rm -f lextools/*.o
	rm -f lextools/*.gch
	rm repl