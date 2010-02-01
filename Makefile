
CXX=g++
LD=g++
CXXFLAGS=-O2
LDFLAGS=-lglut -lGL -lGLU

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: tpsdemo

tpsdemo: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

