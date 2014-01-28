#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Cell.h"
#include "Die.h"

class Game;

using namespace std;


// Interface of Player
//
// The class Player exposes the following operations:
//   - play one round
//   - get current position on the board
//   - set current position on the board
//   - get player's name
//   - set player's name
//

class Player
{
    public:
        // Constructor / destructor
        Player(const string& name, Game* game);
        ~Player() {}

        // Play one round
        void playRound();

        // Get / set name
        string getName() const { return name; }
        void setName(string name) { this->name = name; }

    private:
        string name;
        Game* game;

        int n_rounds; // number of played rounds

        // Roll a die and advance on the board
        void rollDieAndAdvance();

        friend class Player_unittest;
        friend class Game_unittest;
};

#endif // PLAYER_H
