#include <iostream>
#include "Player.h"
#include "Game.h"

Player::Player(const string& name, Game* game)
{
    this->name = name;
    this->game = game;
    n_rounds = 0;
}


void Player::rollDieAndAdvance()
{
    int advance = game->getDie()->roll();
    game->advancePlayerPosition(this, advance);
}


void Player::playRound()
{
    rollDieAndAdvance();

    // TO DO: do some actions here

    n_rounds++;
}
