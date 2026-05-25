#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int board[20]; // board[row] = column
int count = 0;

// Function to check if it's safe to place a queen at (row, col)
bool isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        // Check same column or same diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to print the board configuration
void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Recursive backtracking function to solve the problem
void solveNQueens(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col; // Place queen
            if (row == n) {
                printSolution(n); // Found a solution
            } else {
                solveNQueens(row + 1, n); // Try next row
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of Queens: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        printf("Invalid input. Please enter a number between 1 and 20.\n");
        return 1;
    }

    solveNQueens(1, n);

    if (count == 0) {
        printf("\nNo solution exists for %d queens.\n", n);
    } else {
        printf("\nTotal solutions found: %d\n", count);
    }

    return 0;
}
