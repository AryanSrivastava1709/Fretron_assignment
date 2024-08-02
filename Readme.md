# README

## Table of Contents

1. [Question 1](#question-1)
   - [References](#question-1-references)
   - [Algorithm Explanation](#question-1-algorithm-explanation)
2. [Question 2](#question-2)
   - [References](#question-2-references)
   - [Algorithm Explanation](#question-2-algorithm-explanation)
3. [Question 3](#question-3)
   - [References](#question-3-references)
   - [Algorithm Explanation](#question-3-algorithm-explanation)

---

## Question 1

The Python code for Question 1 involves plotting flight paths while adjusting for intersections between different paths.

### References

- **Matplotlib Documentation**: [Matplotlib](https://matplotlib.org/stable/contents.html)
- **Computational Geometry**:
  - GeeksforGeeks: [Check if Two Given Line Segments Intersect](https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/)
  - Stack Overflow: [How to Check if Line Segments Intersect](https://stackoverflow.com/questions/16372803/how-to-check-if-line-segments-intersect)

### Algorithm Explanation

1. **Function Definitions**:

   - `ccw(A, B, C)`: Determines if the sequence of points (A, B, C) makes a counter-clockwise turn.
   - `intersect(A, B, C, D)`: Checks if the line segments AB and CD intersect using the `ccw` function.
   - `adjust_path(path, other_paths)`: Adjusts the given path to avoid intersections with other paths.
   - `plot_flight_paths(flights)`: Plots the given flight paths using Matplotlib.

2. **User Input**:

   - `get_user_input()`: Function to get user input for the flight paths. Prompts the user to enter coordinates for each flight path.

3. **Path Adjustment**:

   - The algorithm checks for intersections between each segment of the current flight path and all segments of the other flight paths. If an intersection is detected, the current point is slightly adjusted.

4. **Plotting**:
   - Each adjusted flight path is plotted using Matplotlib, with different colors for each path.

---

## Question 2

The C++ code for Question 2 involves distributing apples among three individuals based on given share percentages.

### References

- **C++ Standard Library Documentation**: [C++ Standard Library](https://en.cppreference.com/w/)
- **`std::accumulate` Function**: [C++ Reference](https://en.cppreference.com/w/cpp/algorithm/accumulate)
- **Sorting in C++**: [Sorting in C++](https://en.cppreference.com/w/cpp/algorithm/sort)
- **Greedy Algorithms**:
  - GeeksforGeeks: [Greedy Algorithm to Distribute Items](https://www.geeksforgeeks.org/greedy-algorithm-to-distribute-items/)

### Algorithm Explanation

1. **Function Definition**:

   - `distributeApples(appleWeight, shares, shareWeight)`: Distributes the apple weights among individuals based on their share percentages.

2. **Weight Calculation**:

   - Calculate the total weight of the apples.
   - Compute the target weight for each share using the given percentages.

3. **Apple Distribution**:

   - Sort the apple weights in descending order.
   - Distribute each apple to the individual whose current total weight is the least in relation to their target weight.

4. **Main Function**:
   - Reads apple weights from the user.
   - Initializes the shares and individuals.
   - Calls the `distributeApples` function to distribute the apples.
   - Outputs the distribution result.

---

## Question 3

The C++ code for Question 3 involves finding unique paths for a castle to eliminate all soldiers on a grid and return to its starting position.

### References

- **C++ STL Documentation**: [C++ STL](https://en.cppreference.com/w/)
- **Vector and Tuple Operations in C++**: [Vectors](https://en.cppreference.com/w/cpp/container/vector), [Tuples](https://en.cppreference.com/w/cpp/utility/tuple)
- **Backtracking Algorithms**:
  - GeeksforGeeks: [Backtracking Algorithms](https://www.geeksforgeeks.org/backtracking-algorithms/)
  - HackerRank: [Backtracking Examples](https://www.hackerrank.com/domains/tutorials/10-days-of-javascript)

### Algorithm Explanation

1. **Struct Definitions**:

   - `Position`: Represents a coordinate (x, y) on the grid.
   - `Castle`: Represents the castle's current position and includes a method to check if it is at its home position.

2. **Function Definitions**:

   - `displayPath(path)`: Displays the steps of a path.
   - `findPaths(castle, home, soldiers, path, paths, directions)`: Recursive function to find all unique paths for the castle to eliminate all soldiers and return to its home position.

3. **Pathfinding**:

   - The castle tries to move in all four possible directions (up, down, left, right).
   - If a soldier is encountered, the castle "kills" the soldier and turns left.
   - The function recursively continues this process, backtracking if necessary, to find all possible paths.

4. **Main Function**:
   - Reads the number of soldiers and their positions from the user.
   - Reads the castle's starting position.
   - Calls the `findPaths` function to find and display all unique paths.

---

This README provides an overview of the algorithms and references used in the three questions. Each section outlines the key components and steps involved in the implementation, along with relevant references and articles for further reading.
