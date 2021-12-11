# Makefile for Cellular Automata

UTILS_DIR = utils/
TESTS_DIR = tests/
SRC_DIR = src/
EXMPLES_DIR = examples/

all:
	cd $(SRC_DIR); make all
	cd $(TESTS_DIR); make all
	cd $(EXMPLES_DIR); make all

cleanall:
	cd $(SRC_DIR); make cleanall
	cd $(TESTS_DIR); make cleanall
	cd $(EXMPLES_DIR); make cleanall
