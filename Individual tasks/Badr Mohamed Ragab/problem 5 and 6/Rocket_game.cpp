#include "Rocket_game.h"
using namespace std;

Board::Board(int a) {
    this->n  = a;
    this->board = new char*[n];
    for (int i = 0; i < n; ++i) {
        this->board[i] = new char[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            this->board[i][j] = '-';
        }
    }
    for (int i = 1; i < n-1; ++i) {
        board[0][i] = 'v';
    }
    for (int i = 1; i < n-1; ++i) {

        board[i][0] = '>';
    }

}

void Board::Display_board() {

    for (int i = 0; i < n; ++i) {
        if(i == 0)
            cout<<"    "<<i;
        else
            cout<<"   "<<i;
    }
    cout<<"\n";
    for (int i = 0; i < n; ++i) {
        cout<<i<<" | ";
        for (int j = 0; j < n; ++j) {
            cout<<this->board[i][j]<<" | ";
        }
        cout<<"\n";

    }

}

bool Board::update_board(int x, int y, char symbol) {
    if(x>n-2||y>n-2)
        return false;
    if(board[x][y] == 'v' && symbol == 'v')
    {
        if(board[x + 1][y] == '-') {
            board[x + 1][y] = 'v';
            board[x][y] = '-';
        }
        else if(board[x + 2][y] == '-')
        {
            board[x + 2][y] = 'v';
            board[x][y] = '-';
        }
        else
           return false;
    }

    else if(board[x][y] == '>' && symbol == '>')
    {
        if(board[x][y + 1] == '-') {
            board[x ][y+1] = '>';
            board[x][y] = '-';
        }
        else if(board[x][y + 2] == '-')
        {
            board[x][y+2] = '>';
            board[x][y] = '-';
        }
        else
            return false;
    }
    else
    {
       return false;
    }
    return true;
}

int Board::is_winner() {
    int counter_1 = 0, counter_2 = 0;
    for (int i = 1; i < n-1; ++i) {
        if(this->board[n-1][i] == 'v')
        {
            counter_1++;

        }
        if(this->board[i][n-1] == '>')
        {
            counter_2++;
        }
    }
    if(counter_1 == n-2)
        return 1;
    else if(counter_2 == n-2)
        return -1;
    else
        return 0;

}

int Board::if_can_play(char symbol) {
    int counter_1 = 0;
    int counter_2 = 0;
    for (int i = 0; i < n-1; ++i) {
        if(board[n - 1][i] == 'v')
            counter_1++;
        if(board[i][n-1] == '>')
            counter_2++;
    }

    for (int i = 0; i < this->n-1; ++i) {
        for (int j = 0; j < this->n-1; ++j) {
            if ((board[i][j] == 'v' && board[i + 1][j] == '>' && board[i + 2][j] == '>')) {
                    counter_1++;

            }
            else if ((board[i][j] == '>' && board[i][j + 1] == 'v' && board[i][j + 2] == 'v')) {
                    counter_2++;
            }
        }
    }

    if(counter_1 == n-2 && symbol == 'v')
        return -1;
    else if(counter_2 == n-2 && symbol == '>')
        return -2;
    else
        return 2;
}
void Board::remove(int x, int y, char symbol) {
    if (symbol == 'v'){
        if (board[x + 1][y] == 'v') {
            board[x + 1][y] = '-';
        }
        else{
            board[x + 2][y] = '-';
        }

        if (board[x][y] == '-') {
            board[x][y] = 'v';
        }
        else{
            board[x - 1][y] = 'v';
        }
    }
    else {
        if (board[x][y + 1] == '>') {
            board[x][y + 1] = '-';
        }
        else{
            board[x][y + 2] = '-';
        }

        if (board[x][y] == '-') {
            board[x][y] = '>';
        }
        else{
            board[x][y - 1] = '>';
        }
    }
}
int Board::get_n() const {
    return n;
}


