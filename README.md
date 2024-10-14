# Sudoku Solver

A simple C program that solves Sudoku puzzles using a backtracking algorithm. The program takes a 9x9 Sudoku grid as input, where `0` represents an empty cell, and attempts to fill the grid with numbers from 1 to 9 following Sudoku rules.

## Table of Contents

- [About the Project](#about-the-project)
- [Rules of Sudoku](#rules-of-sudoku)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## About the Project

This project is a command-line Sudoku solver implemented in C. It uses a backtracking algorithm to fill in the empty cells (`0`s) in the grid while ensuring all Sudoku rules are followed.

### Rules of Sudoku

1. Each row must contain the numbers 1 to 9 without repetition.
2. Each column must contain the numbers 1 to 9 without repetition.
3. Each of the nine 3x3 sub-grids (boxes) must contain the numbers 1 to 9 without repetition.

The program will try different numbers in the empty cells until it finds a solution that satisfies these constraints.

## Getting Started

### Prerequisites

Ensure you have a C compiler like `gcc` installed. You can check if it's installed by running:
```bash
gcc --version

## Usage
1. Open the terminal and navigate to the directory known as Sudoku Solver
2. Compile and run the program using gcc:
  gcc -o sudoku_solver sudoku_solver.c
  ./sudoku_solver
3. The program will output the solved Sudoku grid if a solution exists, or it will state that no solution is possible.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to create a pull request or open an issue.

## Contact
Takunda Christian Takaindisa - christiantakaindisa@outlook.com
