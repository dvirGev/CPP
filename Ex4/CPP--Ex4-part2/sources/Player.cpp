#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    class Game;
    Player::Player(Game &game, string &name)
    {
        this->name = name;
        this->game = &game;
        this->money = 0;
        this->lastAction = Actions::nothing;
        this->isAlive = true;
        game.addPlayer(this);
    }
    void Player::income()
    {
        startTurn();
        this->money++;
        endTurn(Actions::income);
    }
    void Player::foreign_aid()
    {
        if (money > MAXMONEY)
        {
            throw runtime_error(name + " has more than 10 coins");
        }
        startTurn();
        this->money += 2;
        endTurn(Actions::foreign_aid);
    }
    void Player::coup(Player &p)
    {
        startTurn();
        if (!p.isAlive)
        {
            throw runtime_error(name + " ALREADY DEAD");
        }
        if (money < COUPPRICE)
        {
            throw runtime_error(name + ", you don't have enough money to kill " + p.name);
        }
        p.isAlive = false;
        money -= COUPPRICE;
        endTurn(Actions::coup);
    }
    string Player::role()
    {
        return "Player";
    }
    int Player::coins() const
    {
        return this->money;
    }
    void Player::blockMe()
    {
        switch (lastAction)
        {
        case Actions::foreign_aid:
            money -= 2;
            break;
        default:
            throw invalid_argument("you can't block my last action");
            break;
        }
        lastAction = Actions::nothing;
    }
    void Player::startTurn()
    {
        if (game->players().size() < 2)
        {
            throw runtime_error("Need two players to play");
        }
        if (!isAlive)
        {
            throw runtime_error(name + " is Dead");
        }
        if (name != game->turn())
        {
            throw runtime_error(name + " This is " + game->turn() + " Trun");
        }
        game->isGameStart = true;
    }
    void Player::endTurn(Actions a)
    {
        lastAction = a;
        game->moveTrun();
    }
    Player::~Player()
    {
    }
}