CXX = g++
CXXFLAGS = -std=gnu++17 -Wall -g ${SANITIZERS}
LDFLAGS = ${SANITIZERS}

all: main

main: main.o classes.o coordinateSystems.o
	$(CXX) $(CXXFLAGS) -o main main.o classes.o coordinateSystems.o $(LDFLAGS)

main.o: main.cpp classes.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

classes.o: classes.cpp classes.hpp
	$(CXX) $(CXXFLAGS) -c classes.cpp

coordinateSystems.o: coordinateSystems.cpp coordinateSystems.h
	$(CXX) $(CXXFLAGS) -c coordinateSystems.cpp

valgrind: main
	valgrind --leak-check=full ./main

picoweb:
	java -jar /usr/share/plantuml/plantuml.jar -picoweb

clean:
	rm -f main main.o classes.o coordinateSystems.o
