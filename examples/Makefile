# TODO: DOCUMENTATION HERE

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    =  -std=c++11 -O3 -o

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib
BIN_DIR     = ../bin

# The next line contains the list of utility objects created by this Makefile.
EXECUTABLES = solute_dispersion

solute_dispersion: $(INC_DIR)/cellular_automaton.h 
	$(CXX) $(CXXFLAGS) solute_dispersion solute_dispersion.cxx -I$(INC_DIR) $(LIB_DIR)/cellular_automaton.a
	mv solute_dispersion $(BIN_DIR)

all: $(EXECUTABLES)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
