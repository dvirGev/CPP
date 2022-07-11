#include "Contessa.hpp"
namespace coup{
    Contessa::Contessa(Game &game, string name) : Player(game, name)
    {
    }
    string Contessa::role()
    {
        return "Contessa";
    }
    void Contessa::block(Player &p)
    {
        money = money;
        if (p.lastAction != Actions::Acoup)
        {
            throw invalid_argument("you can't block " + p.name + " now");
        }
        p.blockMe();
    }
    Contessa::~Contessa()
    {
    }
    
}