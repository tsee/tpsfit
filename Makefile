

BINDIR=bin
SRCDIR=src
TESTDIR=test

#CXX=g++
#LD=g++
CXXFLAGS+=-O2 -I. -I$(SRCDIR) -Wall
LDFLAGS+=-lglut -lGL -lGLU

SOURCES=$(SRCDIR)/linalg3d.cc $(SRCDIR)/ThinPlateSpline.cc
EXESOURCES=$(SRCDIR)/tpsdemo.cc $(SRCDIR)/tpsfit.cc $(SRCDIR)/tpsview.cc
TESTSOURCES=$(TESTDIR)/Vec.cc $(TESTDIR)/streaming.cc

OBJECTS=$(SOURCES:.cc=.o)
EXEOBJECTS=$(EXESOURCES:.cc=.o)
TESTOBJECTS=$(TESTSOURCES:.cc=.o)

EXECUTABLES=$(BINDIR)/tpsdemo $(BINDIR)/tpsfit $(BINDIR)/tpsview
TESTEXECUTABLES=$(TESTDIR)/Vec $(TESTDIR)/streaming

all: bin $(EXECUTABLES)

bin:
	@mkdir -p bin

$(BINDIR)/tpsview: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsview.o $(OBJECTS) -o $@

$(BINDIR)/tpsdemo: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsdemo.o $(OBJECTS) -o $@

$(BINDIR)/tpsfit: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsfit.o $(OBJECTS) -o $@

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(OBJECTS) $(TESTOBJECTS) $(TESTEXECUTABLES)
	perl -MTest::Harness -e 'runtests(qw($(TESTDIR)/Vec $(TESTDIR)/streaming))'

$(TESTDIR)/steaming:
	$(CXX) $(LDFLAGS) $(TESTDIR)/streaming.o $(OBJECTS) -o $@

clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXEOBJECTS) $(TESTOBJECTS) $(EXECUTABLES) $(TESTEXECUTABLES)

