
int main()
{
    cout << "\n-------------------------------------------------------------------\n\n";
    cout << "\t\t\t Tic-Tac-Toe\n";
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
            cin.clear();              // Clear the error flag
            while (cin.get() != '\n') // Read and discard characters until newline
                continue;
            continue; // Restart loop
        }

        char playerSymbol, computerSymbol;
        if (choice == 'n' || choice == 'N')
        {
            char userChoice;
            cout << "Enter your choice ('X' or 'O'): ";
            cin >> userChoice;
            if (userChoice == 'X' || userChoice == 'x')
            {
                playerSymbol = HUMANMOVE;
                computerSymbol = COMPUTERMOVE;
            }
            else if (userChoice == 'O' || userChoice == 'o')
            {
                playerSymbol = COMPUTERMOVE;
                computerSymbol = HUMANMOVE;
            }
            else
            {
                cout << "Wrong choice! Please enter 'X' or 'O'." << endl;
                continue; // Restart loop
            }
        }
        else
        {
            char userChoice;
            cout << "Enter your choice ('X' or 'O'): ";
            cin >> userChoice;

            // Validate the user's choice
            if ((userChoice == 'X' || userChoice == 'O' || userChoice == 'x' || userChoice == 'o') && cin.peek() == '\n')
            {
                // cout << "Choose X or Y to play game : ";
                // char s;
                // cin >> s;
                if (userChoice == 'X' || userChoice == 'x')
                {
                    playerSymbol = HUMANMOVE;
                    computerSymbol = COMPUTERMOVE;
                }
                else if (userChoice == 'O' || userChoice == 'o')
                {
                    playerSymbol = COMPUTERMOVE;
                    computerSymbol = HUMANMOVE;
                }
                else
                {
                    cout << "Wrong choice! Please enter 'X' or 'O'." << endl;
                    continue; // Restart loop
                }
            }
            else
            {
                cout << "Invalid choice! Please enter 'X' or 'O'." << endl;
                cin.clear();              // Clear the error flag
                while (cin.get() != '\n') // Read and discard characters until newline
                    continue;
                continue; // Restart loop
            }
        }

        cout << "You have chosen '" << playerSymbol << "' as your symbol." << endl;
        cout << "Computer will play with symbol '" << computerSymbol << "'." << endl;

        playTicTacToe(playerSymbol, computerSymbol);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> cont;

        if (cin.fail() || (cont != 'y' && cont != 'n'))
        {
            cout << "Invalid input! Please enter 'y' to play again or 'n' to quit." << endl;
            cin.clear();              // Clear the error flag
            while (cin.get() != '\n') // Read and discard characters until newline
                continue;
            cont = 'n'; // Force exit loop on invalid input
        }

    } while (cont == 'y');

    return 0;
}