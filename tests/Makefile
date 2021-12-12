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
EXECUTABLES = test_input_services test_computational_services

test_input_services: $(INC_DIR)/cellular_automaton.h 
	$(CXX) $(CXXFLAGS) test_input_services test_input_services.cxx -I$(INC_DIR) $(LIB_DIR)/cellular_automaton.a
	mv test_input_services $(BIN_DIR)

test_computational_services: $(INC_DIR)/cellular_automaton.h 
	$(CXX) $(CXXFLAGS) test_computational_services test_computational_services.cxx -I$(INC_DIR) $(LIB_DIR)/cellular_automaton.a
	mv test_computational_services $(BIN_DIR)

all: $(EXECUTABLES)

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
