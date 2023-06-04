# Object-Oriented Simulation in C Language
This project is a Colony War game written in the C language. Sample outputs are provided below. For details, you can refer to the "odev-2" file in the main directory.


The code represents different populations of colonies in separate columns, with each number representing a different column.
Each column is represented by a random character symbol.
Each colony can use a different warfare tactic, which is a different type inheriting from the tactic structure.
When two colonies fight, the Warfare function of the tactic structure is called, and the colony with the higher value wins based on a value between 0 and 1000 returned by the function.
The population of the losing colony decreases by a difference /1000 ratio compared to the winning colony, and the difference / 1000 ratio of the food stock goes to the winning colony.
If there is a tie, the colony with the larger population wins. If the populations are equal, a winner is chosen randomly.
Each colony adds a random integer value between 1 and 10, returned by the Production function of the production structure, to its food stock in each round.
The initial food stock of each colony is equal to the square of its initial population.
In each round, the population of each colony increases by 20% and the food stock decreases by double the current population.
If a colony's population or food stock becomes zero or negative, the colony is eliminated.
The program continues until only one colony is left, which is then displayed on the screen before the program ends.


![cikti1](https://github.com/osmntahir/ColonyWar-C/blob/master/images/Screen%20Shot%205-22-2023%20at%2012.22%20AM.png?raw=true)



![cikti2](https://github.com/osmntahir/ColonyWar-C/blob/master/images/Screen%20Shot%205-22-2023%20at%2012.23%20AM.png?raw=true)



![cikti3](https://github.com/osmntahir/ColonyWar-C/blob/master/images/Screen%20Shot%205-22-2023%20at%2012.23%20AM%20-%202.png?raw=true)


## Project Description
I designed a simulation in C language using object-oriented programming to achieve high readability, modularity, and realism.

## Usage
You can compile the program using the Mingw compiler with the help of the makefile. Alternatively, you can directly run the "Program.exe" file inside the "bin" folder to test the program.
