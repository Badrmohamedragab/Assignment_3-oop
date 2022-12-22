#ifndef GAME_ROCKET_ROCKET_GAME_H
#define GAME_ROCKET_ROCKET_GAME_H
#include<iostream>
#include<iomanip>
#include<windows.h>
#include <cstdlib>
using namespace std;

class Board {
private:
     int n{};
   char **board;
public:
    explicit Board(int a);
    void Display_board();
    int get_n() const;
    bool update_board(int x, int y, char symbol);
    int is_winner();
    void remove(int x, int y, char symbol);

    int if_can_play(char symbol);

};

class Player
{
protected:
    string name{};
    char symbol{};
public:
    Player(string n, char s);
    [[nodiscard]] char get_symbol() const;
    string get_name();
    void get_move(int &x, int &y);

};
class game_manager
{
public:
    static void run();
};
class computer_player : public Player
{
private:
    string name ;
    char Symbol ;
public:
    computer_player(string n, char s) :Player(n, s) {};

    int minimax(Board& b1, int depth, bool maximizing, bool first = true);
};


#endif //GAME_ROCKET_ROCKET_GAME_H
