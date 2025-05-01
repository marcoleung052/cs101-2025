#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];  // 3x3 棋盤
    char current_player; // 當前玩家 ('X' 或 'O')

public:
    // 建構子：初始化棋盤與起始玩家
    TicTacToe() {
        reset_board();
        current_player = 'X';
    }

    // 重設棋盤
    void reset_board() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    // 顯示棋盤
    void display_board() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    // 嘗試下棋，傳入 row 與 col（0-based index）
    bool make_move(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid move. Out of range.\n";
            return false;
        }
        if (board[row][col] != ' ') {
            cout << "Cell already taken. Try again.\n";
            return false;
        }
        board[row][col] = current_player;
        return true;
    }

    // 交換玩家
    void switch_player() {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    // 檢查是否有玩家獲勝
    bool check_win() {
        // 檢查橫排與直排
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player)
                return true;
            if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
                return true;
        }
        // 檢查對角線
        if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
            return true;
        if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
            return true;

        return false;
    }

    // 檢查棋盤是否已滿
    bool is_draw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    // 取得當前玩家
    char get_current_player() const {
        return current_player;
    }
};

// 主程式：執行遊戲迴圈
int main() {
    TicTacToe game;
    int row, col;

    while (true) {
        game.display_board();
        cout << "Player " << game.get_current_player() << ", enter your move (row and column 0-2): ";
        cin >> row >> col;

        if (!game.make_move(row, col)) {
            continue;
        }

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
