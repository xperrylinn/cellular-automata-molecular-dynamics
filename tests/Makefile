# TODO: DOCUMENTATION HERE

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -O3 -o

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib
BIN_DIR     = ../bin

# The next line contains the list of utility objects created by this Makefile.
EXECUTABLES = test_xavi

test_xavi: $(INC_DIR)/cellularautomaton.h 
	$(CXX) $(CXXFLAGS) test_xavi test_xavi.cxx -I$(INC_DIR) $(LIB_DIR)/cellularautomaton.o
	mv test_xavi $(BIN_DIR)

all: $(EXECUTABLES)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
