// ii) Write a method Boolean isKingSafe(int[][]chessBoard)
// Returns true if king in the given chess board is safe from the given enemies otherwise false;
// NOTE: Enemies are- Horse, Camel, Queen, Elephant only
// Do not consider the colour case of the chess board for traversal of camel and all
/**
 * MARK - Program is Used to Find That the King is Safe or Not By Putting Chess Element like CAMEL , QUEEN , HORSE , ELEPHANT
 * DESC -  isValidPosition(int row, int col) - Checking for codinates which are in valid position or not  ,
 *         isKingSafe(vector<vector<int>> &chessBoard) function returing if king is in safe position or not
 * PARAM - isValidPosition(int row, int col) - Take row coodinate and column coodinates  ,
 *         isKingSafe(vector<vector<int>> &chessBoard) Take ChessBoard as a Argument
 * RETURN - Returing Weather the King is at Safe Position or Not.
 */
#include <bits/stdc++.h>
using namespace std;
// Movement Detail
/*
(-) values in horseRow represent movements upwards.
(+) values in horseRow represent movements downwards.
(-) values in horseCol represent movements to the left.
(+) values in horseCol represent movements to the right.
*/
bool isValidPosition(int row, int col)
{
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool isKingSafe(vector<vector<int>> &chessBoard)
{
    int kingRow = -1;
    int kingCol = -1;
    bool kingFound = false;

    // Find the position of the king
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (chessBoard[row][col] == 6)
            { // Assuming king is represented by '6'
                kingRow = row;
                kingCol = col;
                kingFound = true;
                break;
            }
        }
        if (kingFound)
            break;
    }

    if (!kingFound)
    {
        // If king not found, return false (assuming king must be present on the board)
        return false;
    }

    // Check for threats from horse
    int horseDenomination = 1;
    int horseRow[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int horseCol[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int row = 0; row < 8; row++)
    {
        int newRow = kingRow + horseRow[row];
        int newCol = kingCol + horseCol[row];
        if (isValidPosition(newRow, newCol) && chessBoard[newRow][newCol] == horseDenomination)
        {
            return false;
        }
    }
    // Check for threats from queen
    int queenDenomination = 3;
    int queenRowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int queenColOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int row = 0; row < 8; row++)
    {
        int newRow = kingRow + queenRowOffsets[row];
        int newCol = kingCol + queenColOffsets[row];
        while (isValidPosition(newRow, newCol))
        {
            if (chessBoard[newRow][newCol] == queenDenomination)
            {
                return false;
            }
            if (chessBoard[newRow][newCol] != 0)
            {
                break;
            }
            newRow += queenRowOffsets[row];
            newCol += queenColOffsets[row];
        }
    }

    // Check for threats from elephant
    int elephantDenomination = 4;
    int elephantRowOffsets[] = {-1, -1, 1, 1};
    int elephantColOffsets[] = {-1, 1, -1, 1};

    for (int row = 0; row < 4; row++)
    {
        int newRow = kingRow + elephantRowOffsets[row];
        int newCol = kingCol + elephantColOffsets[row];
        if (isValidPosition(newRow, newCol) && chessBoard[newRow][newCol] == elephantDenomination)
        {
            return false;
        }
    }

    // If no threats found, king is safe
    return true;
}

int main()
{
    // Example usage:
    vector<vector<int>> chessBoard = {
        {6, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {4, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0} // Assuming king is at position (7,7)
    };
    bool kingSafe = isKingSafe(chessBoard);
    cout << "king safe? " << (kingSafe ? "Yes" : "No") << endl;
    return 0;
}
