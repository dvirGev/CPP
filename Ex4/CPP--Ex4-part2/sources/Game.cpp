#include "Game.hpp"
namespace coup{
    vector<string> Game::players()
    {
        vector<string> res;
        for(Player *p : playersList)
        {   if (p->isAlive)
            {
                res.push_back(p->name);
            }
        }
        return res;
    }
    string Game::turn()
    {
        if (this->playersList.empty())
        {
            throw runtime_error("their is no players in this game");
        }
        return playersList[i]->name;
    }
    string Game::winner()
    {
        if (players().size() != 1 || !isGameStart)
        {
            throw runtime_error("their is no winner in this game");
        }
        return playersList[i]->name;
    }
    void Game::addPlayer(Player *p)
    {
        if (players().size() >= MAXPLAYERS)
        {
            throw runtime_error("Need up to six players to play");
        }
        if (isGameStart)
        {
            throw runtime_error("Add Player In Middle Of Game");
        }
        
        playersList.push_back(p);
    }
    void Game::moveTrun()
    {
        do
        {
            i = (i+1) % playersList.size();
        } while (!playersList[i]->isAlive);
    }
    Game::Game(/* args */)
    {
        i = 0;
        isGameStart = false;
    }

    Game::~Game()
    {
    }
}