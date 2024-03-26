// TIC TAC TOW GAME

// Code by Gaurav Negi

/*

MARK:

- The code implements a Tic Tac Toe game where the player can play against the computer or against another player.



DESC:

- The code consists of functions to initialize the game board, display the board, show instructions, check for a winner, and determine the best move for the computer using the minimax algorithm.

- It allows the player to choose to play against the computer or against another player.

- The game continues until a player wins, it's a draw, or the player decides to quit.

- The user can input their move by selecting a cell numbered from 1 to 9.



PARAM:

- `board`: A 2D array representing the Tic Tac Toe board.

- `whoseTurn`: An integer indicating whose turn it is (COMPUTER or HUMAN).



RETURN:

- The functions Return the Winner



*/

#include <bits/stdc++.h>

using namespace std;

#define COMPUTER 1

#define HUMAN 2

#define SIDE 3 // Length of the board

char COMPUTERMOVE;

char HUMANMOVE;

#define COMPUTERMOVEE 'O'

#define HUMANMOVEE 'X'

// Showing board

void showBoard(char board[][SIDE])

{

    cout << "\t\t\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;

    cout << "\t\t\t-----------" << endl;

    cout << "\t\t\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;

    cout << "\t\t\t-----------" << endl;

    cout << "\t\t\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl

         << endl;
}

// Showing Instruction of the board

void showInstructions()

{

    cout << "\nChoose a cell numbered from 1 to 9 as below and play\n\n";

    cout << "\t\t\t 1 | 2 | 3 \n";

    cout << "\t\t\t-----------\n";

    cout << "\t\t\t 4 | 5 | 6 \n";

    cout << "\t\t\t-----------\n";

    cout << "\t\t\t 7 | 8 | 9 \n\n";
}

// Initilization of the board

void initialise(char board[][SIDE])

{

    for (int row = 0; row < SIDE; row++)

    {

        for (int col = 0; col < SIDE; col++)

            board[row][col] = ' ';
    }
}

// Declarartion of the winner

void declareWinner(int whoseTurn)

{

    if (whoseTurn == COMPUTER)

        cout << "COMPUTER has won\n";

    else

        cout << "HUMAN has won\n";
}

// This function Check wheather any row is fully filled with that symbol

bool rowCrossed(char board[][SIDE])

{

    for (int row = 0; row < SIDE; row++)

    {

        if (board[row][0] == board[row][1] &&

            board[row][1] == board[row][2] &&

            board[row][0] != ' ')

            return (true);
    }

    return (false);
}

// This function Check wheather any Column is fully filled with that symbol

bool columnCrossed(char board[][SIDE])

{

    for (int row = 0; row < SIDE; row++)

    {

        if (board[0][row] == board[1][row] &&

            board[1][row] == board[2][row] &&

            board[0][row] != ' ')

            return (true);
    }

    return (false);
}

// This function Check wheather any Diagonal is fully filled with that symbol

bool diagonalCrossed(char board[][SIDE])

{

    if (board[0][0] == board[1][1] &&

        board[1][1] == board[2][2] &&

        board[0][0] != ' ')

        return (true);

    if (board[0][2] == board[1][1] &&

        board[1][1] == board[2][0] &&

        board[0][2] != ' ')

        return (true);

    return (false);
}

/*

Checks if any row has been completely filled with the same symbol (either 'X' or 'O').

OR column is completely filled with the same symbol.

Only the main diagonal (from top-left to bottom-right) is completely filled with 'X's.

*/

bool gameOver(char board[][SIDE])

{

    return (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}

// Check the best possible move by reccurisively chek on the empty cells

int minimax(char board[][SIDE], int depth, bool isAI)

{

    int score = 0;

    int bestScore = 0;

    if (gameOver(board) == true)

    {

        if (isAI == true)

            return -1;

        if (isAI == false)

            return +1;
    }

    else

    {

        if (depth < 9)

        {

            if (isAI == true)

            {

                // ensures that it starts as a very low value. This sets a benchmark for finding the highest possible score during the Minimax algorithm.

                bestScore = -999;

                for (int row = 0; row < SIDE; row++)

                {

                    for (int col = 0; col < SIDE; col++)

                    {

                        if (board[row][col] == ' ')

                        {

                            board[row][col] = COMPUTERMOVE;

                            score = minimax(board, depth + 1, false);

                            board[row][col] = ' ';

                            if (score > bestScore)

                            {

                                bestScore = score;
                            }
                        }
                    }
                }

                return bestScore;
            }

            else

            {

                bestScore = 999;

                for (int row = 0; row < SIDE; row++)

                {

                    for (int col = 0; col < SIDE; col++)

                    {

                        if (board[row][col] == ' ')

                        {

                            board[row][col] = HUMANMOVE;

                            score = minimax(board, depth + 1, true);

                            board[row][col] = ' ';

                            if (score < bestScore)

                            {

                                bestScore = score;
                            }
                        }
                    }
                }

                return bestScore;
            }
        }

        else

        {

            return 0;
        }
    }
}

int bestMove(char board[][SIDE], int moveIndex)

{

    int x = -1, y = -1;

    int score = 0, bestScore = -999;

    for (int row = 0; row < SIDE; row++)

    {

        for (int col = 0; col < SIDE; col++)

        {

            if (board[row][col] == ' ')

            {

                board[row][col] = COMPUTERMOVE;

                score = minimax(board, moveIndex + 1, false);

                board[row][col] = ' ';

                if (score > bestScore)

                {

                    bestScore = score;

                    x = row;

                    y = col;
                }
            }
        }
    }

    return x * 3 + y; // returning the beat move
}

void playTicTacToe1(char playerSymbol, char computerSymbol)

{

    char board[SIDE][SIDE];

    int moveIndex = 0, x = 0, y = 0;

    initialise(board);

    showInstructions();

    while (gameOver(board) == false && moveIndex != SIDE * SIDE)

    {

        int n;

        if (playerSymbol == HUMANMOVE)

        {

            bool validInput = false;

            while (!validInput)

            {

                cout << "Enter the position (1-9) where you want to place your move: ";

                cin >> n;

                // Check if input failed or if the position is out of range or if the position is already occupied

                if (cin.fail() || n < 1 || n > 9 || board[(n - 1) / SIDE][(n - 1) % SIDE] != ' ')

                {

                    cout << "Invalid move! Please enter a valid number between 1 and 9 corresponding to an empty cell." << endl

                         << endl;

                    cin.clear(); // Clear the error flag

                    while (cin.get() != '\n') // Read and discard characters until newline

                        continue;
                }

                else

                {

                    validInput = true; // Break out of the loop if input is valid
                }
            }

            x = (n - 1) / SIDE;

            y = (n - 1) % SIDE;

            board[x][y] = playerSymbol;

            cout << "\nYou have put a " << playerSymbol << " in cell " << n << endl

                 << endl;

            showBoard(board);

            moveIndex++;
        }

        else // Computer's turn

        {

            n = bestMove(board, moveIndex);

            x = n / SIDE;

            y = n % SIDE;

            board[x][y] = computerSymbol;

            cout << "Computer has put a " << computerSymbol << " in cell " << n + 1 << endl

                 << endl;

            showBoard(board);

            moveIndex++;
        }

        // Switch turns

        playerSymbol = (playerSymbol == HUMANMOVE) ? COMPUTERMOVE : HUMANMOVE;
    }

    if (gameOver(board) == false && moveIndex == SIDE * SIDE)

        cout << "It's a draw\n";

    else

    {

        if (playerSymbol == COMPUTERMOVE)

            declareWinner(COMPUTER);

        else

            declareWinner(HUMAN);
    }
}

void playTicTacToe(int whoseTurn)

{

    char board[SIDE][SIDE];

    int moveIndex = 0, x = 0, y = 0;

    initialise(board);

    showInstructions();

    // Keep playing till the game is over or it is a draw

    while (gameOver(board) == false && moveIndex != SIDE * SIDE)

    {

        int n;

        if (whoseTurn == COMPUTER)

        {

            n = bestMove(board, moveIndex);

            x = n / SIDE;

            y = n % SIDE;

            board[x][y] = COMPUTERMOVEE;

            printf("COMPUTER has put a %c in cell %d\n\n", COMPUTERMOVEE, n + 1);

            showBoard(board);

            moveIndex++;

            whoseTurn = HUMAN;
        }

        else if (whoseTurn == HUMAN)

        {

            printf("You can insert in the following positions : ");

            for (int row = 0; row < SIDE; row++)

                for (int col = 0; col < SIDE; col++)

                    if (board[row][col] == ' ')

                        printf("%d ", (row * 3 + col) + 1);

            printf("\n\nEnter the position = ");

            // Error handling for non-integer input

            if (!(cin >> n))

            {

                cout << "Invalid input! Please enter a number.\n";

                cin.clear(); // Clear the error flag

                while (cin.get() != '\n') // Discard invalid input

                    continue;

                continue; // Restart the loop
            }

            n--; // Adjust index to match array indexing

            x = n / SIDE;

            y = n % SIDE;

            if (n >= 0 && n < 9 && board[x][y] == ' ')

            {

                board[x][y] = HUMANMOVEE;

                printf("\nHUMAN has put a %c in cell %d\n\n", HUMANMOVEE, n + 1);

                showBoard(board);

                moveIndex++;

                whoseTurn = COMPUTER;
            }

            else

            {

                printf("Invalid move! Please select a valid position.\n\n");
            }
        }
    }

    // If the game has drawn

    if (gameOver(board) == false && moveIndex == SIDE * SIDE)

        printf("It's a draw\n");

    else

    {

        // Toggling the user to declare the actual winner

        if (whoseTurn == COMPUTER)

            whoseTurn = HUMAN;

        else if (whoseTurn == HUMAN)

            whoseTurn = COMPUTER;

        declareWinner(whoseTurn);
    }
}

int main()

{

    cout << "\n-------------------------------------------------------------------\n\n";

    cout << "\t\t\t TIC-TAC-TOE\n";

    cout << "\t\t Welcome to Tic-Tac-Toe Game\n";

    cout << "\n-------------------------------------------------------------------\n\n";

    char cont = 'y';

    do

    {

        char choice;

        cout << "Do you want to start first? (y/n): ";

        cin >> choice;

        if (cin.fail() || (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'))

        {

            cout << "Invalid choice\n";

            cin.clear(); // Clear the error flag

            while (cin.get() != '\n') // Read and discard characters until newline

                continue;

            continue; // Restart loop
        }

        char playerSymbol, computerSymbol;

        if (choice == 'n' || choice == 'N')

        {

            playTicTacToe(COMPUTER);

            // break;
        }

        else

        {

            char userChoice;

            do

            {

                cout << "Enter your choice ('X' or 'O'): ";

                cin >> userChoice;

                // Validate the user's choice

                if ((userChoice == 'X' || userChoice == 'O' || userChoice == 'x' || userChoice == 'o') && cin.peek() == '\n')

                {

                    if (userChoice == 'X' || userChoice == 'x')

                    {

                        playerSymbol = 'X';

                        COMPUTERMOVE = 'O';

                        HUMANMOVE = 'X';

                        computerSymbol = 'O';
                    }

                    else if (userChoice == 'O' || userChoice == 'o')

                    {

                        playerSymbol = 'O';

                        computerSymbol = 'X';

                        COMPUTERMOVE = 'X';

                        HUMANMOVE = 'O';
                    }

                    else

                    {

                        cout << "Wrong choice! Please enter 'X' or 'O'." << endl;
                    }
                }

                else

                {

                    cout << "Invalid choice! Please enter 'X' or 'O'." << endl;

                    cin.clear(); // Clear the error flag

                    while (cin.get() != '\n') // Read and discard characters until newline

                        continue;

                    continue; // Restart loop
                }

            } while (userChoice != 'X' && userChoice != 'x' && userChoice != 'O' && userChoice != 'o');

            cout << "You have chosen '" << playerSymbol << "' as your symbol." << endl;

            cout << "Computer will play with symbol '" << computerSymbol << "'." << endl;

            playTicTacToe1(playerSymbol, computerSymbol);

            cout << "\nDo you want to play again? (y/n): ";

            cin >> cont;

            cont = tolower(cont);

            if (cin.fail() || (cont != 'y' && cont != 'n'))

            {

                cout << "Invalid input! Please enter 'y' to play again or 'n' to quit." << endl;

                cin.clear(); // Clear the error flag

                while (cin.get() != '\n') // Read and discard characters until newline

                    continue;

                cont = 'n'; // Force exit loop on invalid input
            }
        }

    } while (cont == 'y');

    return 0;
}
