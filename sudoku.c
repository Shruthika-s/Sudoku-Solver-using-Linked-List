#include<stdio.h>
#include<stdlib.h>
#define N 9

// Structure for a Sudoku cell
typedef struct Cell {
    int row;
    int col;
    int num;
    struct Cell* next;
} Cell;

// Function to check if it's safe to assign a number to a particular cell
int isSafe(Cell* head, int row, int col, int num) {
    Cell* curr = head;
    while (curr != NULL) {
        if (curr->row == row || curr->col == col || 
           (curr->row / 3 == row / 3 && curr->col / 3 == col / 3)) {
            if (curr->num == num) {
                return 0;
            }
        }
        curr = curr->next;
    }
    return 1;
}

// Function to solve the Sudoku grid
int solveSudoku(Cell* head) {
    Cell* curr = head;
    int isComplete = 1;
    while (curr != NULL) {
        if (curr->num == 0) {
            isComplete = 0;
            break;
        }
        curr = curr->next;
    }
    if (isComplete) {
        return 1;
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(head, curr->row, curr->col, num)) {
            curr->num = num;
            if (solveSudoku(head)) {
                return 1;
            }
            curr->num = 0;
        }
    }
    return 0;
}

// Function to print the Sudoku grid
void printGrid(Cell* head) {
    int a[N][N];
    int i, j, k = 0;
    Cell* curr = head;
    while (curr != NULL) {
        while (k < N) {
            i = curr->row;
            j = curr->col;
            a[i][j] = curr->num;
            printf("\t%d", a[i][j]);
            curr = curr->next;
            k++;
        }
        k = 0;
        printf("\n");
    }
}

// Function to create a new Sudoku cell
Cell* createCell(int row, int col, int num) {
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->row = row;
    newCell->col = col;
    newCell->num = num;
    newCell->next = NULL;
    return newCell;
}

// Function to construct the Sudoku grid from a 2D array
Cell* constructGrid(int grid[N][N]) {
    Cell* head = NULL;
    Cell* prev = NULL;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int num = grid[row][col];
            Cell* newCell = createCell(row, col, num);
            if (head == NULL) {
                head = newCell;
            } else {
                prev->next = newCell;
            }
            prev = newCell;
        }
    }
    return head;
}

int main() {
    Cell* head = NULL;
    int grid[N][N];
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("Enter %dth row %dth element: ", row + 1, col + 1);
            scanf("%d", &grid[row][col]);
        }
    }
    printf("\nSudoku before solving:\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                printf("\t_");
            } else {
                printf("\t%d", grid[row][col]);
            }
        }
        printf("\n");
    }
    head = constructGrid(grid);
    if (solveSudoku(head)) {
        printf("Sudoku solved:\n");
        printGrid(head);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}
