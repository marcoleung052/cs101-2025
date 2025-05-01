#include <iostream>
using namespace std;

class TicTacToe {
private:
    int board[3][3];
    int current_player;

public:
    TicTacToe() {
        reset_board();
        current_player = 1;
    }

    void reset_board() {
        int pos = 1;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = 0;
    }

    void display_board() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            if (i < 3) cout << "   ■   ■   \n";
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 1)
                    cout << " X ";
                else if (board[i][j] == 2)
                    cout << " O ";
                else
                    cout << " " << (i * 3 + j + 1) << " ";
                if (j < 2) cout << "■";
            }
            cout << "\n";
            if (i < 3) cout << "   ■   ■   \n";
            if (i < 2) cout << "■■■■■■■■■■■\n";
        }
        cout << "\n";
    }

    bool make_move(int pos) {
        if (pos < 1 || pos > 9) {
            cout << "Invalid input. Choose a number between 1 and 9.\n";
            return false;
        }
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] != 0) {
            cout << "Cell already taken. Try again.\n";
            return false;
        }
        board[row][col] = current_player;
        return true;
    }

    void switch_player() {
        current_player = 3 - current_player; 
    }

    bool check_win() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == current_player &&
                board[i][1] == current_player &&
                board[i][2] == current_player)
                return true;
            if (board[0][i] == current_player &&
                board[1][i] == current_player &&
                board[2][i] == current_player)
                return true;
        }
        if (board[0][0] == current_player &&
            board[1][1] == current_player &&
            board[2][2] == current_player)
            return true;
        if (board[0][2] == current_player &&
            board[1][1] == current_player &&
            board[2][0] == current_player)
            return true;
        return false;
    }

    bool is_draw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == 0)
                    return false;
        return true;
    }

    int get_current_player() const {
        return current_player;
    }
};

int main() {
    TicTacToe game;
    int pos;

    while (true) {
        cout << "-- Tic Tac Toe --CSIE@CGU\nPlayer 1 (X)  -  Player 2 (O)";
        game.display_board();
        cout << "Player " << game.get_current_player() << ", enter your move (1-9): ";
        cin >> pos;

        if (!game.make_move(pos))
            continue;

        if (game.check_win()) {
            game.display_board();
            cout << "==>Player " << game.get_current_player() << " wins\n";
            break;
        }

        if (game.is_draw()) {
            game.display_board();
            cout << "==>Game draw\n";
            break;
        }

        game.switch_player();
    }

    return 0;
}
