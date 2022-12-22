#include "Rocket_game.h"

int computer_player::minimax(Board &b1, int depth, bool maximizing, bool first) {
    int result = b1.is_winner();
    if(result != 0 ||depth == 0)
        return result;

    if(maximizing)
    {
        int final_score = -100;
        int finalI, finalJ;
        for (int i = 0; i < b1.get_n()-1; ++i) {
            for (int j = 0; j < b1.get_n()-1; ++j) {
                if(b1.update_board(i, j, 'v'))
                {
                    int score = minimax(b1, depth-1, false, false);
                    b1.remove(i, j, 'v');
                    if(score > final_score) {
                        final_score = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }
        }
        if(first)
        {
            b1.update_board(finalI, finalJ, 'v');
        }
        return final_score;
    }
    else
    {
        int final_score = 100;
        for (int i = 0; i < b1.get_n()-1; ++i) {
            for (int j = 0; j < b1.get_n()-1; ++j) {
                if(b1.update_board(i, j, '>'))
                {
                    int score = minimax(b1, depth-1, true, false);
                    b1.remove(i, j, '>');
                    if(score < final_score) {
                        final_score = score;
                    }
                }
            }
        }

        return final_score;


    }
}
