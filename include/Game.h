#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>

#include "GameBoard.h"
#include "Die.h"
#include "Player.h"
#include "Cell.h"

class Player;

// Interface of Game class
//
// A game supports the following operations:
//  - given a list of player names, create a new game
//  - get the list of player names
//  - play
//

using namespace std;


class Game
{
    public:
        Game(const vector<string>& playerNames);
        ~Game();

        vector<string> getPlayerNames() const;

        Die* getDie() { return die; }
        void play(); // Play a full game (20 rounds)

        int getPlayerPosition(Player* p);
        void setPlayerPosition(Player* p, int pos);
        void advancePlayerPosition(Player* p, int advance);

    protected:

    private:
        vector<Player*> players;
        map<Player*, Cell*> playerPositions;

        Board gameBoard;

        int n_rounds;
        Die* die;

        // Play one round
        void playRound();

        // Some constants
        static const int roundsPerGame = 20;
        static const int standardGameBoardSize = 40;
        static const int standardDieFaces = 6;

        friend class Player_unittest;
        friend class Game_unittest;
};

#endif // GAME_H
