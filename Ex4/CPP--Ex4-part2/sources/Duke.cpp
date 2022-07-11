#include "Duke.hpp"
namespace coup
{
    Duke::Duke(Game &game, string name) : Player(game, name)
    {
    }
    string Duke::role()
    {
        return "Duke";
    }
    void Duke::block(Player &p){
        money = money;
        if (p.lastAction != Actions::foreign_aid)
        {
            throw invalid_argument("you can't block " + p.name + " now");
        }
        p.blockMe();
    }
    void Duke::tax(){
        startTurn();
        money += 3;
        endTurn(Actions::tax);
    }
    Duke::~Duke()
    {
    }
}