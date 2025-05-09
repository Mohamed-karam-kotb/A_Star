# A* Algorithm Implementation

This project is an implementation of the A* (A-Star) pathfinding algorithm using C++.  
The A* algorithm is widely used in AI, robotics, and games to find the shortest path between two points on a graph or grid, considering both cost and heuristic estimation.

# Features

- Efficient pathfinding using A* algorithm
- Modular code with separate files for the algorithm and main driver
- Easy to compile and run with standard C++ compiler

# Algorithm Overview

The A* algorithm finds the shortest path between a start node and a target node by combining:

- g(n): The cost from the start node to node n
- h(n): A heuristic estimate of the cost from node n to the goal

It uses a priority queue to always explore the node with the lowest f(n) = g(n) + h(n).

A* guarantees finding the shortest path if the heuristic is admissible (never overestimates the true cost).

# Compilation

You need a C++ compiler like g++ to compile the project.

To compile the project, run this command in the terminal:

```bash
g++ A_Star.cpp main.cpp -o a_star
#Running
./a.out
Example :
![A Star Example](A_Star/Selection_006.png)
