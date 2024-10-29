#include <iostream>
#include <iomanip>  // for formatting output

char board[3][3];       // 3x3 Tic-Tac-Toe board
char currentPlayer = 'X';  // Start with player X

// Function to initialize the board with numbers 1-9
void initializeBoard() {
    int num = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '0' + num;
            ++num;
        }
    }
}

// Function to display the board
void displayBoard() {
    std::cout << "\n\n    Tic-Tac-Toe Game Board\n";
    std::cout << "-----------------------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "   ";
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) std::cout << "|";
        }
        if (i < 2) std::cout << "\n---------------------\n";
    }
    std::cout << "\n\n";
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to handle player input and update the board
void playerMove() {
    int move;
    bool validMove = false;
    
    while (!validMove) {
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;
        
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                validMove = true;
            } else {
                std::cout << "  This spot is already taken. Try again.\n";
            }
        } else {
            std::cout << " Invalid input. Please choose a number between 1 and 9.\n";
        }
    }
}

// Main game loop
void playGame() {
    bool gameWon = false;
    bool gameDraw = false;

    initializeBoard();
    displayBoard();

    while (!gameWon && !gameDraw) {
        playerMove();
        displayBoard();
        gameWon = checkWin();
        if (gameWon) {
            std::cout << " Congratulations! Player " << currentPlayer << " wins! \n";
        } else {
            gameDraw = checkDraw();
            if (gameDraw) {
                std::cout << " It's a draw! \n";
            } else {
                switchPlayer();
            }
        }
    }
}

// Main function
int main() {
    char playAgain;

    std::cout << "Welcome to the Tic-Tac-Toe Game!\n";
    std::cout << "Players take turns to place their marks (X or O) on the board.\n";
    std::cout << "To make a move, enter a number between 1 and 9 corresponding to the grid.\n";
    std::cout << "Get three in a row to win!\n\n";

    do {
        playGame();
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
        currentPlayer = 'X';  // Reset to player X for a new game
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "\nThanks for playing Tic-Tac-Toe! Goodbye!\n";

    return 0;
}
