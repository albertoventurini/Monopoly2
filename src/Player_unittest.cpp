#include "Player_unittest.h"

#include "FixedDie.h"
#include "Player.h"
#include "GameBoard.h"
#include "Game.h"


bool Player_unittest::player_rolls_seven()
{
    vector<string> playerNames;

    playerNames.push_back("player0");
    playerNames.push_back("player1");
    Game game(playerNames);

    Die* die = new FixedDie(7);
    game.die = die;

    Player* player0 = game.players[0];

    player0->rollDieAndAdvance();
    if(game.getPlayerPosition(player0) != 7) return false;

    return true;
}


bool Player_unittest::player_on_thirtynine_rolls_six_and_should_end_up_in_five()
{
    vector<string> playerNames;

    playerNames.push_back("player0");
    playerNames.push_back("player1");
    Game game(playerNames);

    Die* die = new FixedDie(6);
    game.die = die;

    Player* player0 = game.players[0];

    game.setPlayerPosition(player0, 39);
    player0->rollDieAndAdvance();
    if(game.getPlayerPosition(player0) != 5) return false;

    return true;
}


bool Player_unittest::run()
{
    return
        player_rolls_seven() &&
        player_on_thirtynine_rolls_six_and_should_end_up_in_five();
}
