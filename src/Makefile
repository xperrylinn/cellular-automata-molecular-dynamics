# Makefile for ROOT/src
# >make all
#		makes all object data from cxx files in this directory, then creates a library
# >make cleanall
#		deletes all object and library data from ../lib

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -O3 -c  -std=c++11

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib

# The next line contains the list of math object files created by this Makefile.
# they are the targets this makefile builds
CELLULAR_AUTOMATON_OBJS = cellular_automaton_comp.o cellular_automaton_input.o cellular_automaton_output.o cellular_automaton.a

cellular_automaton_comp.o: $(INC_DIR)/cellular_automaton.h
	$(CXX) $(CXXFLAGS) cellular_automaton_comp.cxx -I$(INC_DIR)
	mv cellular_automaton_comp.o $(LIB_DIR)

cellular_automaton_input.o: $(INC_DIR)/cellular_automaton.h
	$(CXX) $(CXXFLAGS) cellular_automaton_input.cxx -I$(INC_DIR)
	mv cellular_automaton_input.o $(LIB_DIR)

cellular_automaton_output.o: $(INC_DIR)/cellular_automaton.h
	$(CXX) $(CXXFLAGS) cellular_automaton_output.cxx -I$(INC_DIR)
	mv cellular_automaton_output.o $(LIB_DIR)

cellular_automaton.a:
	ar cr cellular_automaton.a $(LIB_DIR)/cellular_automaton_input.o $(LIB_DIR)/cellular_automaton_comp.o $(LIB_DIR)/cellular_automaton_output.o
	mv cellular_automaton.a $(LIB_DIR)

all: $(CELLULAR_AUTOMATON_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(CELLULAR_AUTOMATON_OBJS)

