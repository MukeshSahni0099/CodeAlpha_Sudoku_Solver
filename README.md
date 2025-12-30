# 🧩 Sudoku Solver (C++)

A powerful Sudoku-solving application developed as part of my **CodeAlpha** internship. This project demonstrates the implementation of a **Backtracking Algorithm** to solve complex puzzles efficiently.

## 🛠️ Core Features & Logic
* **Grid Representation**: Represents the 9x9 Sudoku grid as a 2D array.
* **Backtracking Algorithm**: Uses a recursive backtracking approach to fill empty cells (marked as 0) with valid numbers.
* **Constraint Checking**: Before placing a number, the system verifies three rules:
    * **Row Check**: Number must not exist in the current row.
    * **Column Check**: Number must not exist in the current column.
    * **3x3 Subgrid Check**: Number must not exist in the local 3x3 square.
* **Recursive Solving**: The algorithm tries numbers 1-9 recursively until a valid solution is found or it backtracks to try a different path.

## 💻 Technical Implementation
* **Language**: C++
* **Data Structures**: 2D Arrays
* **Algorithm Design**: Recursion and Backtracking
