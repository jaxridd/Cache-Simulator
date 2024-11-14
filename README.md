# C++ Cache Simulator
This project implements a simulation of caches in C++ with four different cache configurations.
1. Direct-Mapped
2. 2-way Set Associative
3. 4-way Set Associative
4. Fully Associtaive

The simulation utilizes this LRU replacement policy to optimize block placement and calculates the miss rate for each configuration from the user input.

## Features
- Cache associativity selection
- Miss rate calculation
- Cache content display

## Requirement

The only requirement for this program, is a c++ compiler.
The one I used is g++.

## Instructions
I'll be using g++ for this tutorial.
### 1. Compile
Open a terminal and find the directory that cotains the file: caches.cpp

Once you cd into the correct directory run the command below to compile the program.

`g++ -o runProgram caches.cpp`
Select any name you want for the exe file, I named it runProgram for simplicity.

### 2. Running the Program

To run the program after it's been compiled use the below command.

`runProgram` or `./runProgram`

After running the program you will be asked to enter a few things:

1. Number of Cache Blocks
2. Associativity:
    - `1` for direct-mapped cache
    - `2` for 2-way set-associative cache
    - `4` for 4-way set-associative cache
    - `-1` for fully associtive cache
3. Block Addresses: Type the address and hit enter, when you want to stop the sequence enter `-1`

After each address is entered, the program will output the contents of the cache and wether it's a cache hit or miss. Once `-1` is entered the miss rate will display and the program will exit.

The following image is an example of what an output might look like.

![DM-Cache-Results](DM-Cache-Results.png)

## Notes

This `README.md` should provide all you need to know about how to compile and run the cache simulator


