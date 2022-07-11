#pragma once
#include "Game.hpp"
#include <string>
using namespace std;
namespace coup
{
    constexpr int COUPPRICE = 7;
    constexpr int MAXPLAYERS = 6;
    constexpr int MAXMONEY = 10;
    enum Actions
    {
        nothing,
		income,
		foreign_aid,
        coup,
        Acoup,
        transfer,
        block,
        steal,
        tax
    };
    class Game;
    class Player
    {
    private:
        
    protected:
        Game *game;

    public:
        string name;
        Actions lastAction;
        bool isAlive;
        int money;

        Player(Game &game, string &name);
        void income();
        virtual void foreign_aid();
        void coup(Player &p);
        virtual void blockMe();
        virtual string role();
        void startTurn();
        void endTurn(Actions a);
        int coins() const;
        ~Player();
    };

}