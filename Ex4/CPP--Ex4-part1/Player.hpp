
#include "Game.hpp"
#include <string>
#pragma once
using namespace std;
namespace coup{
    class Player
    {
    private:
        string name;
        int money;
        Game *game;
    public:
        Player(Game& game, string name);
        void income();
        void foreign_aid();
        void coup(Player &p);
        void role();
        int coins();
        ~Player();
    };
    
}