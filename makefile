CXX = g++
CXXFLAGS = -std=gnu++17 -Wall -g ${SANITIZERS}
LDFLAGS = ${SANITIZERS}

all: main

main: main.o classes.o
	$(CXX) $(CXXFLAGS) -o main main.o classes.o $(LDFLAGS)

main.o: main.cpp classes.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

classes.o: classes.cpp classes.hpp
	$(CXX) $(CXXFLAGS) -c classes.cpp

valgrind: main
	valgrind --leak-check=full ./main

picoweb:
	java -jar /usr/share/plantuml/plantuml.jar -picoweb

clean:
	rm -f main main.o classes.o
