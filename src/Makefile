# TODO: add documentation here

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib

# The next line contains the list of math object files created by this Makefile.
# they are the targets this makefile builds
CELLULAR_AUTOMATON_OBJS = cellular_automaton.o

cellular_automaton.o: $(INC_DIR)/cellular_automaton.h
	$(CXX) $(CXXFLAGS) cellular_automaton.cxx -I$(INC_DIR)
	mv cellular_automaton.o $(LIB_DIR)

all: $(CELLULAR_AUTOMATON_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(CELLULAR_AUTOMATON_OBJS)

