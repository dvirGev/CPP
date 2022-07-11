#include "Assassin.hpp"
namespace coup
{
    Assassin::Assassin(Game &game, string name) : Player(game, name)
    {
        this->target = NULL;
    }
    string Assassin::role()
    {
        return "Assassin";
    }
    void Assassin::coup(Player &p)
    {
        startTurn();
        if (!p.isAlive)
        {
            throw runtime_error(name + " ALREADY DEAD");
        }
        if (money < 3)
        {
            throw runtime_error(name + "you don't have enough money to kill " + p.name);
        }
        if (money >= COUPPRICE)
        {
            p.isAlive = false;
            target = &p;
            money -= COUPPRICE;
            endTurn(Actions::coup);
        }
        else
        {
            p.isAlive = false;
            target = &p;
            money -= 3;
            endTurn(Actions::Acoup);
        }
    }
    void Assassin::blockMe()
    {
        switch (lastAction)
        {
        case Actions::foreign_aid:
            money -= 2;
            break;
        case Actions::Acoup:
            target->isAlive = true;
            break;
        default:
            throw invalid_argument("you can't block my last action");
            break;
        }
        lastAction = Actions::nothing;
    }
    Assassin::~Assassin()
    {
    }
}