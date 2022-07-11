#include "Captain.hpp"
namespace coup
{
    Captain::Captain(Game &game, string name) : Player(game, name)
    {
        sucker = NULL;
        moneySteal = 0;
    }
    string Captain::role()
    {
        return "Captain";
    }
    void Captain::block(Player &p)
    {
        money = money;
        if (p.lastAction != Actions::steal)
        {
            throw invalid_argument("you can't block " + p.name + " now");
        }
        p.blockMe();
    }
    void Captain::steal(Player &p)
    {
        startTurn();
        if (p.money <= 0)
        {
            throw runtime_error(p.name + " dosn't have any money");
        }
        if (p.money < 2)
        {
            money += p.money;
            moneySteal = p.money;
            p.money = 0;
            sucker = &p;
        }
        else
        {
            p.money -= 2;
            moneySteal = 2;
            sucker = &p;
            money += 2;
        }
        endTurn(Actions::steal);
    }
    void Captain::blockMe()
    {
        switch (lastAction)
        {
        case Actions::foreign_aid:
            money -= 2;
            break;
        case Actions::steal:
            sucker->money += moneySteal;
            money -= moneySteal;
            break;
        default:
            throw invalid_argument("you can't block my last action");
            break;
        }
        lastAction = Actions::nothing;
    }
    Captain::~Captain()
    {
    }

}