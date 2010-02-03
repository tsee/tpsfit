

BINDIR=bin
SRCDIR=src

CXX=g++
LD=g++
CXXFLAGS=-O2 -I. -I$(SRCDIR) -Wall
LDFLAGS=-lglut -lGL -lGLU

SOURCES=$(SRCDIR)/linalg3d.cc $(SRCDIR)/ThinPlateSpline.cc
EXESOURCES=$(SRCDIR)/tpsdemo.cc $(SRCDIR)/tpsfit.cc $(SRCDIR)/tpsview.cc
OBJECTS=$(SOURCES:.cc=.o)
EXEOBJECTS=$(EXESOURCES:.cc=.o)

all: bin $(BINDIR)/tpsdemo $(BINDIR)/tpsfit $(BINDIR)/tpsview

bin:
	@mkdir -p bin

$(BINDIR)/tpsview: $(OBJECTS) $(EXEOBJECTS)
	$(CC) $(LDFLAGS) $(SRCDIR)/tpsview.o $(OBJECTS) -o $@

$(BINDIR)/tpsdemo: $(OBJECTS) $(EXEOBJECTS)
	$(CC) $(LDFLAGS) $(SRCDIR)/tpsdemo.o $(OBJECTS) -o $@

$(BINDIR)/tpsfit: $(OBJECTS) $(EXEOBJECTS)
	$(CC) $(LDFLAGS) $(SRCDIR)/tpsfit.o $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXEOBJECTS) $(BINDIR)/tpsdemo $(BINDIR)/tpsfit $(BINDIR)/tpsview

