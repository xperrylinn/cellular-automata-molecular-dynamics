# Cellular Automata

This repository provides general library of tools to build, run, and analyze cellular automata simulations. 

## What is Cellular Automata (CA)?

__Cellular automata__ refers to a class of simulations based on a system of cells that maintain state and change state over time based on environment variables, influences from neighbhoring cells and a cells previous state. The system of cells forms an N-dimensional grid where for each time step a simultaneous update is applied to each cell of the grid using what is called a __state transition function__. A state transition function takes into consideration a cells __neighborhood__ and a __rule__ for how update a cells state. A neighborhood simply refers to the adjcent cells which should be considered when applying a rule to update a cells state. Two common neighborhood definitions are the __VonNeumann__ and __Moore neighborhood__ pictured below, left and right respectively.
![Neighborhood types](./images/neighborhood_types.png)
CA simulations have finitie size which means there needs to be __boundary conditions__. Boundary conditins simply define what is the iteractive behavior of cells at the permiter grid. One common boundary condition type is __periodic boundary conditions__ where cells interact with cells on the opposing side essentailly formnig a torus shape pictured below. 
![Neighborhood types](./images/periodic_boundary_conditions_torus.png)

The rule applied to each cell in a state transition function contains the domain specific knowledge of how a cells state should be updated given the states of the cells in its neighborhood. For example, one common rule is the __majority rule__ which is a rule where a cell will change its state to the mode of its neighboring cell states.

CA provide a powerful tool for modeling complex systems because it allows the modeling of nonlinear spatio-temporal dynamics as well as the ability to solve problemns in a wide range of domains as you can codify specific behaviors into rule functions for a particular application, like molecular dynamics.

### What does this repository offer?

This repository offers a C++ class, `CellularAutomaton` (located in `lib/cellular_automaton.h`) for constructing cellular automata simulations provided input data structures and simulation parameters. There are methods for writing simulation data and metadata to file and a python module for visualzing the simulation. The source code definitions of the functionilty is broken up into three services: __input services__, __computational services__, and __output services__. Below is a brief serice:
- input services (located in `src/cellular_automaton_input.cxx`): contains constructors for initializing `CellularAutomaton` objects as well as setter methods for key class attributes and a helper method to validate user inputs.
- computationl services (located in `src/cellular_automaton_input.cxx`): contains the core methods for running a simulation. The two main methods in this file are the `state_transition_function` and `get_neighbors` a method for comptuing the valid neighboring cells depending on the neighborhood type and boundary conditions.
- output services (located in `src/cellular_automaton_input.cxx`): contains methods for printing the grid to standard output as two methods for writing data to fil. The two methods for writing to file are a method for writing each snap shot of the simulation to a CSV capturing the state information of grid in one dimensional form and a complementary method for writing simulation metadata to a JSON file. Users can put CSV files into our visualization program (located in 'examples/Output_CA.py'), then the user can see the detailed simulation processing results interactive. 
The class offers the following list of base functionality:
- Rules:
	- Majority rule
	- Parity rule
- Boundary conditions:
	- Periodic
	- Fixed
	- Cutoff
	- None
To add more general functionlaity to this class feel free to open a pull request to introduce new features with relevant unit tests placed test in the `tests` directory. Another option for increasing functionality of the `CellularAutomaton` class, is to use class ihertiance as demonstrated in the examples section below. This is particularly useful if you want to build a class of CA simulations unique to a domain like __molecular dyanmics__ (classical mechanics applied to molecular systems).

### Examples

For an example of how to extend the base functionality of the `CellularAutomaton` class, please see `examples/solute_dispersion.cxx`. In this example we create a `SoluteDipsersion` class to model the brownian motion of solutes in a grid. This custom class introduces new a rule for update a cells state based on brownian motion for each of the solutes in that cell (the number of the solutes is equal to the integer state value of a cell).

### Depdencies

- C++11
- Makefile


## Repository Struture

This repository is structure using a standard Makefile structure.

- Root directory: cellular-automata-molecular-dynamics
	- Subdirectories:
		- README.md: this file, documentation on library functionality and a conceptual introduction to cellular automata
		- Makefile: makefile to generate all executables and libraries also commands clean all the subdirectories. See Makefile for possible 'make commands'.
		- src: this directory contains the source code with the functionality.
		- include: this directory contains the APIs in the form of .h include files
		- lib: object file produced from making the src direcotry
		- tests: this directory contains test programs used to test the functionalities of the Cellular Atomaton.
		- bin: this directory contains all the executable program


### Collaborators
- Kevin Fong
- Xavier Linn
- Xiange Wang
