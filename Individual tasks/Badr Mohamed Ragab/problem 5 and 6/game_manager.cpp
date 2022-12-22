#include "Rocket_game.h"

void game_manager::run() {
    int check;
    up:
    cout << "1-Player-1 VS Player-2\n2-Player Vs Computer\n";
    cin >> check;

    if (check == 1) {
        cout << "Enter the size of board must be greater than 2 --> ";
        int n;
        int x, y;
        here:
        cin >> n;
        if (n <= 2) {
            cout << "Invalid coordinate ! "<< endl;
            goto here;
        }
        string n1, n2;
        cout << "Enter the name of the first player--> ";
        cin >> n1;
        cout << "Enter the name of the second player--> ";
        cin >> n2;
        Board B1(n);
        Player p[2] = {Player(n1, 'v'), Player(n2, '>')};
        B1.Display_board();

        while (true) {

            for (int i: {1, 2}) {
                if (!((B1.if_can_play(p[i].get_symbol()) == -1 && p[i - 1].get_symbol() == 'v') ||
                      (B1.if_can_play(p[i].get_symbol())
                       == -2 && p[i - 1].get_symbol() == '>'))) {
                    p[i - 1].get_move(x, y);
                    while (!B1.update_board(x, y, p[i - 1].get_symbol())) {
                        cout << "Invalid coordinate!" << endl;
                        p[i - 1].get_move(x, y);
                    }
                } else {
                    cout << "This turn pass!" << endl;
                    continue;
                }
                B1.Display_board();
                if (B1.is_winner() == 1 || B1.is_winner() == -1) {
                    cout << p[i - 1].get_name() << " win the game" << char(1) << ".";
                    return;
                }
            }

        }
    }
    else if (check == 2) {
        cout << "Enter the size of board must be greater than 2 --> ";
        int n, x, y;
        there:
        cin >> n;
        if (n <= 2) {
            cout << "Invalid coordinate ! " << endl;
            goto there;
        }
        Board b(n);
        string name_player;
        cout << "Enter the name of the player-->";
        cin >> name_player;
        Player p1(name_player, '>');
        computer_player p2("computer", 'v');

        b.Display_board();
        while (true) {
            for (int i: {1, 2}) {
                if(i == 1) {
                    if (!((b.if_can_play(p1.get_symbol()) == -2 && p1.get_symbol() == '>'))) {
                        p1.get_move(x, y);

                        while (!b.update_board(x, y, p1.get_symbol())) {
                            cout << "Invalid coordinate!" << endl;
                            p1.get_move(x, y);
                        }
                    }
                    else {
                        cout << "This turn pass!" << endl;
                        continue;
                    }
                    b.Display_board();
                    if (b.is_winner() == -1) {
                        cout << p1.get_name() << " win the game" << char(1) << ".";
                        return;
                    }
                }
                else if(i == 2){
                    p2.minimax(b, 100, true) ;
                    b.Display_board() ;
                    if (b.is_winner() == 1) {
                        cout << p2.get_name() << " win the game" << char(1) << ".";
                        return;
                    }
                }
            }
        }

    }
    else{
        cout<<"Invalid Number!!"<<endl;
        goto up;
    }
}


