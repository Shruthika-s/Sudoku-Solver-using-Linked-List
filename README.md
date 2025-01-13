# Sudoku Solver Using Linked List

## Overview
This project implements a Sudoku solver using linked lists. The solver takes an unsolved Sudoku grid as input and fills it according to Sudoku rules: 
- Each row, column, and 3x3 subgrid must contain the digits 1 through 9 exactly once.

The program employs a recursive backtracking algorithm to find a solution while leveraging linked lists for dynamic memory allocation and efficient constraint checking.

---

## Features
- **Linked List Representation**: Each cell in the Sudoku grid is represented as a node in a linked list.
- **Recursive Backtracking**: Attempts to solve the puzzle by exploring all possibilities.
- **Dynamic Memory Allocation**: Uses a flexible memory model for handling grids.
- **Input and Output**:
  - Accepts a 9x9 Sudoku grid as input.
  - Displays the grid before and after solving.

---

## Usage

### Input
The program accepts a 9x9 Sudoku grid where:
- Numbers `1-9` represent filled cells.
- `0` represents empty cells.

### Output
- Displays the input grid.
- Prints the solved Sudoku grid if a solution exists, or reports if the puzzle is unsolvable.
