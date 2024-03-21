// 1. Write a method void printArray(int[][]arr)
// Prints array elements clockwise and anti-clockwise alternatively.
// Input :
//  1 2 3
//  4 5 6
//  7 8 9
// Output :
// 1 2 3 6 9 8 7 4 5
// 3 2 1 4 7 8 9 6 5

/*
 * MARK -  Program aim to traverse matrix in clock wise and anticlockwise
 * DESC -  printClockwiseSpiral(const vector<vector<int>> &matrix) this function is printing the element in clock wise
 *         printAntiClockwiseSpiral(const vector<vector<int>> &matrix) this function is printing the element in Anti Clock Wise
 * PARAM - printClockwiseSpiral(consvect tor<vector<int>> &matrix) take a matrix as an input
 *         printAntiClockwiseSpiral(const vector<vector<int>> &matrix) takes a matrix as an input
 * RETURN -Returing the sprial order of the matrix in ClockWise and AntiClockWise
 */
#include <bits/stdc++.h>
using namespace std;
void printClockwiseSpiral(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();

    int cols = matrix[0].size();

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Print top row
        for (int i = left; i <= right; ++i)
            cout << matrix[top][i] << " ";
        top++;

        // Print right column
        for (int i = top; i <= bottom; ++i)
            cout << matrix[i][right] << " ";
        right--;

        // Print bottom row (if exists)
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }

        // Print left column (if exits)
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
}

void printAntiClockwiseSpiral(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();

    int cols = matrix[0].size();

    int startRow = 0, endRow = rows - 1, startCol = 0, endCol = cols - 1;

    while (startRow <= endCol && startCol <= endCol)
    {
        // printing top row
        for (int col = endCol; col >= startCol; col--)
        {
            cout << matrix[startRow][col] << " ";
        }
        startRow++;
        // printing rightmost col
        for (int row = startRow; row <= endRow; row++)
        {
            cout << matrix[row][startCol] << " ";
        }
        startCol++;
        // print bottom row
        if (startRow <= endRow)
        {
            for (int col = startCol; col <= endCol; col++)
            {
                cout << matrix[endRow][col] << " ";
            }
            endRow--;
        }
        if (startCol <= endCol)
        {
            for (int row = endRow; row >= startRow; row--)
            {
                cout << matrix[row][endCol] << " ";
            }
            endCol--;
        }
    }
}
int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "Clockwise Spiral: ";
    printClockwiseSpiral(matrix);
    cout << endl;
    cout << "Anti-clockwise Spiral: ";
    printAntiClockwiseSpiral(matrix);
    cout << endl;

    return 0;
}