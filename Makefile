
CXX=g++
LD=g++
CXXFLAGS=-O2
LDFLAGS=-lglut -lGL -lGLU

SOURCES=main.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tpsdemo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXECUTABLE)

