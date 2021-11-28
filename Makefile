# Makefile for Cellular Automata

UTILS_DIR = utils/
TESTS_DIR = tests/
SRC_DIR = src/

all:
	cd $(UTILS_DIR); make all
	cd $(TESTS_DIR); make all
	cd $(SRC_DIR); make all

cleanall:	
	cd $(UTILS_DIR); make cleanall
	cd $(TESTS_DIR); make cleanall
	cd $(SRC_DIR); make cleanall

