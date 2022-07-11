#include "Game.hpp"
namespace coup{
    vector<string> Game::players()
    {
        return this->playersList;
    }
    string Game::turn()
    {
        if (this->playersList.size() == 0)
        {
            throw runtime_error("their is no players in this game");
        }
        return playersList[i];
    }
    string Game::winner()
    {
        if (this->playersList.size() != 1)
        {
            throw runtime_error("their is no players in this game");
        }
        return playersList[i];
    }
    void Game::addPlayer(string name)
    {
        playersList.push_back(name);
    }
    Game::Game(/* args */)
    {
        i = 0;
    }

    Game::~Game()
    {
    }
}