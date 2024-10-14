/*
Sudoku rules:
1) Each 3*3 box must have the #'s 1-9
2) Each Row must have the #'s 1-9 
3) Each column must have the #'s 1-9 
4) A number can only appear once in each row,column, 3*3 box
5) Order doesn't matter
*/

#include <stdio.h>
#include <stdlib.h>
#define N 9
int checkRow(int grid[N][N], int row, int num);
int checkColumn(int grid[N][N], int column, int num);
int checkBox(int grid[N][N], int boxRow, int boxColumn, int num);
int solveSudoku(int grid[N][N], int row, int column);
int main();
int count = 0;
//check if num is already in row, if yes, then num can't be placed there
int checkRow(int grid[N][N], int row, int num) {
    for (int column = 0; column < N; column++)
        if (grid[row][column] == num)
            return 0;
    return 1;
}
//check if num is  already in cilumn, if yes, then num can't be placed there
int checkColumn(int grid[N][N], int column, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][column] == num)
            return 0;
    return 1;
}
//check if num is present in the 3*3 box, if yes, then nu can't be placed there
int checkBox(int grid[N][N], int boxRow, int boxColumn, int num) {
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            if (grid[row + boxRow][column + boxColumn] == num)
                return 0;
    return 1;
/*
Calculation of boxRow/boxColumn:
row%3/column%3, the remainder gives the relative position of the current row/column in 3*3 box
subtracting the remainder from row/column gives the starting row/column index of the row/column in the 3*3 box
from there, itertate 3 times, mening you've gone through the 3 rows/columns of the 3*3 box
*/
}

int solveSudoku(int grid[N][N], int row, int column) {
    count++;
    //count appended after every function call
    if (row == N - 1 && column == N)
    /*
    row = N-1 means the last row 
    column = N (after the last row) means all the rows in the current column are processed/move to next row
    column needs to be compared to N because if you stopped at N-1, the progran wouldn't iterate for the bottom right cell
    */
        return 1;

    if (column == N) { //when you're at the last column, move on to the next row, start from th first column
        row++;
        column = 0;
    }

    if (grid[row][column] > 0) //if the element in the current place isn't 0/ is a number, move on and start from next column
        return solveSudoku(grid, row, column + 1);

    for (int num = 1; num <= N; num++) { 
        if (checkRow(grid, row, num) && checkColumn(grid, column, num) && checkBox(grid, row - row % 3, column - column % 3, num)) {
            //if the number isn't in the current row, column or 3*3 grif
            grid[row][column] = num; //the number can then be put in the placeholder
            if (solveSudoku(grid, row, column + 1)) //if all previous checks/iterations return True, run the function again for the next column
                return 1;
            grid[row][column] = 0; //else that number won't work, set it to 0 again
        }
    }
    return 0;
}

int main() {
    int grid[N][N] = {
    {0, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 0, 0, 0, 3},
    {0, 7, 4, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 0, 2},
    {0, 8, 0, 0, 4, 0, 0, 1, 0},
    {6, 0, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 7, 8, 0},
    {5, 0, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 0}
};


    if (solveSudoku(grid, 0, 0)) {
        printf("Solution found after %d iterations:\n", count);
        for (int i = 0; i < N; i++) {
            if (i % 3 == 0 && i != 0) {
                printf("-----------------------\n");
            }
            for (int j = 0; j < N; j++) {
                if (j % 3 == 0 && j != 0) {
                    printf("| ");
                }
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}