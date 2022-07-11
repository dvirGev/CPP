#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &game, string name) : Player(game, name)
    {
    }
    string Ambassador::role()
    {
        return "Ambassador";
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        startTurn();
        if (p1.money < 1)
        {
            throw runtime_error(p1.name + " dosn't have any money");
        }
        p1.money--;
        p2.money++;
        endTurn(Actions::transfer);
    }
    void Ambassador::block(Player &p){
        money = money;
        if (p.lastAction != Actions::steal)
        {
            throw invalid_argument("you can't block " + p.name + " now");
        }
        p.blockMe();
    }
    Ambassador::~Ambassador()
    {
    }
    
}