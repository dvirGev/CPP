#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
// #include "Player.hpp"
#pragma once
using namespace std;

namespace coup
{
    class Game
    {
    private:
        vector<string> playersList;
        unsigned int i;
    public: 
        Game(/* args */);
        vector<string> players();
        string turn();
        string winner();
        void addPlayer(string name);
        ~Game();
    };
    
}
