

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

# default target
all: bin $(EXECUTABLES)

# create bin/ dir
bin:
	@mkdir -p bin

# generic .o rule
.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# executables
$(BINDIR)/tpsview: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsview.o $(OBJECTS) -o $@

$(BINDIR)/tpsdemo: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsdemo.o $(OBJECTS) -o $@

$(BINDIR)/tpsfit: $(OBJECTS) $(EXEOBJECTS)
	$(CXX) $(LDFLAGS) $(SRCDIR)/tpsfit.o $(OBJECTS) -o $@

# testing targets
test: all $(TESTOBJECTS) $(TESTEXECUTABLES)
	perl -MTest::Harness -e 'runtests(qw($(TESTDIR)/Vec $(TESTDIR)/streaming))'

test_verbose: all $(TESTOBJECTS) $(TESTEXECUTABLES)
	perl -MTest::Harness -e '$$Test::Harness::verbose=1;runtests(qw($(TESTDIR)/Vec $(TESTDIR)/streaming))'

# test executables
$(TESTDIR)/streaming: $(OBJECTS) $(TESTOBJECTS)
	$(CXX) $(LDFLAGS) $(TESTDIR)/streaming.o $(OBJECTS) -o $@

$(TESTDIR)/Vec: $(OBJECTS) $(TESTOBJECTS)
	$(CXX) $(LDFLAGS) $(TESTDIR)/Vec.o $(OBJECTS) -o $@


# cleanup
clean:
	rm -f core *~ *.bak $(OBJECTS) $(EXEOBJECTS) $(TESTOBJECTS) $(EXECUTABLES) $(TESTEXECUTABLES)

