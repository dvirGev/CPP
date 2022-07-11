#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
        vector<Player*> playersList;
        unsigned int i;
    public: 
        bool isGameStart;
        
        Game(/* args */);
        vector<string> players();
        string turn();
        string winner();
        void addPlayer(Player *p);
        void moveTrun();
        ~Game();
    };
    
}
