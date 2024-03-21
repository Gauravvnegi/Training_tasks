// Day-3
// i) Write a method Boolean isValidSudoku(int{{]{{]Sudoku)
// Returns true if the given Sudoku is correctly arranged otherwise false
// Write a method Boolean isValidSudoku(int[][]Sudoku)Returns true if the given Sudoku is correctly arranged otherwise false
// Determine if a 9 x 9 The Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each COLumn must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Example :
// Input: board =
// [['5','3','.','.','7','.",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false

/**
 * MARK  - Program is Used to Find That the Given Suduko is valid or not.
 * DESC  - isValidisValid function is used to check either the current element is there or not on the position the element to be filled,
 *         solveSudoku(vector<vector<char>> &Sudoko_Board) function put all the element from 0 to 9 to validate the suduko 
 * PARAM - isValidisValid(vector<vector<char>> &Sudoko_Board, int row, int col, char c) - takes 2D suduko board , position of row , 
 *         position of col and a character , solveSudoku(vector<vector<char>> &Sudoko_Board) take suduko board as input. 
 * RETURN - Returing Weather the King is at Safe Position or Not.
 */
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>> &Sudoko_Board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++) // Checking for valid number
    {
        if (Sudoko_Board[i][col] == c) // checking if the character  in that Row
            return false;

        if (Sudoko_Board[row][i] == c) // Checking if the character  in that Col
            return false;

        if (Sudoko_Board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // Checking the character is present in 3*3 Board
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &Sudoko_Board)
{
    int ROW = Sudoko_Board.size();
    int COL = Sudoko_Board[0].size();
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            if (Sudoko_Board[row][col] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(Sudoko_Board, row, col, c)) // Checking if the Character is present or not
                    {
                        Sudoko_Board[row][col] = c;

                        if (solveSudoku(Sudoko_Board))
                            return true;
                        else
                            Sudoko_Board[row][col] = '.'; // Backtracking and replacing the character with DOT(.)
                    }
                }

                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> Sudoko_Board{{'5', '.', '.', '.', '7', '.', '.', '.', '.'},
                                      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool answer = solveSudoku(Sudoko_Board);

    if (answer == true)
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << Sudoko_Board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
// test case -2
//  {
//          {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};