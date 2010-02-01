
CXX=g++
LD=g++
CXXFLAGS=-O2
LDFLAGS=-lglut -lGL -lGLU

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tpsdemo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXECUTABLE)

