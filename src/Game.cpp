#include <algorithm>
#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;


Game::Game(const vector<string>& playerNames) :
    gameBoard(standardGameBoardSize), n_rounds(0)
{
    die = new Die();

    for(auto name : playerNames)
    {
        Player* p = new Player(name, this);
        players.push_back(p);
        //playerPositions.insert(pair<Player*, Cell*>(p, gameBoard.start()));
        playerPositions[p] = gameBoard.start();
    }

    random_shuffle(players.begin(), players.end());
}

Game::~Game()
{
    vector<Player *>::iterator it;
    for(it = players.begin(); it != players.end(); it++)
        delete *it;

    delete die;
}


int Game::getPlayerPosition(Player* p)
{
    Cell* cell = playerPositions[p];
    return gameBoard.getCellPosition(cell);
}


void Game::setPlayerPosition(Player* p, int pos)
{
    Cell* c = gameBoard.advance(gameBoard.start(), pos);
    playerPositions[p] = c;
}


void Game::advancePlayerPosition(Player* p, int advance)
{
    Cell* c = gameBoard.advance(playerPositions[p], advance);
    playerPositions[p] = c;
}


vector<string> Game::getPlayerNames() const
{
    vector<string> names;

    for(auto player : players)
        names.push_back(player->getName());

    return names;
}


void Game::playRound()
{
    for(auto player : players)
        player->playRound();

    n_rounds++;
}


void Game::play()
{
    // Check that the number of players is valid
    if(players.size() < 2 || players.size() > 8)
        throw string("Invalid number of players");

    // Play 20 rounds
    for(int i = 0; i < roundsPerGame; i++)
        playRound();
}
