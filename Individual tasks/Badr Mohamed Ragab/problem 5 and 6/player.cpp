#include "Rocket_game.h"

using namespace std;
Player::Player(const string n, char s) {
    this-> name = n;
    this->symbol = s;
}

char Player::get_symbol() const {
    return this->symbol;
}
string Player::get_name()
{
    return this->name;
}

void Player::get_move(int &x, int &y) {
    cout<<"\n"<<this->get_name()<<"'s turn Please enter your move separated by spaces:";
    cin>>x>>y;

}





