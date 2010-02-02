
CXX=g++
LD=g++
CXXFLAGS=-O2 -I. -Wall
LDFLAGS=-lglut -lGL -lGLU

SOURCES=linalg3d.cc ThinPlateSpline.cc
EXESOURCES=tpsdemo.cc tpsfit.cc
OBJECTS=$(SOURCES:.cc=.o)
EXEOBJECTS=$(EXESOURCES:.cc=.o)

all: tpsdemo tpsfit

tpsdemo: $(OBJECTS) $(EXEOBJECTS)
	$(CC) $(LDFLAGS) tpsdemo.o $(OBJECTS) -o $@

tpsfit: $(OBJECTS) $(EXEOBJECTS)
	$(CC) $(LDFLAGS) tpsfit.o $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXEOBJECTS) tpsdemo tpsfit

