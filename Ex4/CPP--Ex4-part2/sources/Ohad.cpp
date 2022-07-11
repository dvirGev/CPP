#include "Ohad.hpp"

namespace coup
{
    Ohad::Ohad(Game &game, string name) : Player(game, name)
    {
    }
    void Ohad::foreign_aid()
    {
        startTurn();
        money += 2;
        endTurn(Actions::foreign_aid);
    }
}
