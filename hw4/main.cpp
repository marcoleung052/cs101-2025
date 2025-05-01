#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char current_player;

public:
    TicTacToe() {
        reset_board();
        current_player = 'X';
    }

    void reset_board() {
        char pos = '1';
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = pos++;
    }

    void display_board() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool make_move(int position) {
        if (position < 1 || position > 9) {
            cout << "Invalid position. Choose 1-9.\n";
            return false;
        }
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Try again.\n";
            return false;
        }
        board[row][col] = current_player;
        return true;
    }

    void switch_player() {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    bool check_win() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player)
                return true;
            if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
                return true;
        }
        if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
            return true;
        if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
            return true;

        return false;
    }

    bool is_draw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    char get_current_player() const {
        return current_player;
    }
};

int main() {
    TicTacToe game;
    int pos;

    while (true) {
        game.display_board();
        cout << "Player " << game.get_current_player() << ", enter your move (1-9): ";
        cin >> pos;

        if (!game.make_move(pos))
            continue;

        if (game.check_win()) {
            game.display_board();
            cout << "Player " << game.get_current_player() << " wins!\n";
            break;
        }

        if (game.is_draw()) {
            game.display_board();
            cout << "It's a draw!\n";
            break;
        }

        game.switch_player();
    }

    return 0;
}
