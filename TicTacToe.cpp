// ===============================
// Tic Tac Toe Game in C++
// Created by: Syed Arsham Asim
// ===============================

#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';
string player1, player2;

// Initialize Board
void resetBoard()
{
    char num = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }

    currentPlayer = 'X';
}

// Display Board
void drawBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

// Check Winner
bool checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

int main()
{
    char playAgain;

    cout << "=============================\n";
    cout << "      TIC TAC TOE GAME\n";
    cout << "=============================\n\n";

    cout << "Enter Player 1 Name (X): ";
    getline(cin, player1);

    cout << "Enter Player 2 Name (O): ";
    getline(cin, player2);

    do
    {
        resetBoard();
        drawBoard();

        bool winner = false;

        for (int turn = 0; turn < 9; turn++)
        {
            int move;

            string playerName;

            if (currentPlayer == 'X')
                playerName = player1;
            else
                playerName = player2;

            cout << "\n"
                 << playerName
                 << " (" << currentPlayer << ")"
                 << ", Enter a Number (1-9): ";

            cin >> move;

            // Invalid Input
            if (move < 1 || move > 9)
            {
                cout << "\nInvalid Input! Enter a number between 1 and 9.\n";
                turn--;
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            // Check if cell already occupied
            if (board[row][col] == 'X' ||
                board[row][col] == 'O')
            {
                cout << "\nThis position is already occupied!\n";
                turn--;
                continue;
            }

            board[row][col] = currentPlayer;

            drawBoard();

            if (checkWin())
            {
                cout << "\nCongratulations "
                     << playerName
                     << "! You Win.\n";

                winner = true;
                break;
            }

            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        if (!winner)
        {
            cout << "\nGame Draw!\n";
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for Playing!\n";

    return 0;
}
