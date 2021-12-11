# TODO: DOCUMENTATION HERE

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -O3 -o -std=c++11

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib
BIN_DIR     = ../bin

# The next line contains the list of utility objects created by this Makefile.
EXECUTABLES = test_xavi tests

tests: $(INC_DIR)/cellular_automaton.h 
	$(CXX) $(CXXFLAGS) tests tests.cxx -I$(INC_DIR) $(LIB_DIR)/cellular_automaton.a
	mv tests $(BIN_DIR)

test_xavi: $(INC_DIR)/cellular_automaton.h 
	$(CXX) $(CXXFLAGS) test_xavi test_xavi.cxx -I$(INC_DIR) $(LIB_DIR)/cellular_automaton.a
	mv test_xavi $(BIN_DIR)

all: $(EXECUTABLES)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
