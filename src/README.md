# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  Kevin Fong
#
This is directory where all source C++ and C Files are being compiled.  
Tests of these functionalities are in the ../tests subdirectory.  

PATH ROOT_DIR/src
    Files:
    - README: this file with a general description of the src subdirectory
    - cellular_automaton_input.cxx: contains source code of the input services of the Cellular Automaton
    - cellular_automaton_comp.cxx: contains source code of the computational services of the Cellular Automaton
    - cellular_automaton_output.cxx: contains source code of the output services of the Cellular Automaton
    - Output_CA.py: contains the source code for the tinker animation as part of output services
    - Makefile: creates objects from each of the CA services and places them in the subdirectory ../lib, then creates a library object from the created objects