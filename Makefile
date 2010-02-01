
CXX=g++
LD=g++
CXXFLAGS=-O2 -I. -Wall
LDFLAGS=-lglut -lGL -lGLU

SOURCES=linalg3d.cc main.cc ThinPlateSpline.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=tpsdemo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXECUTABLE)

