#include "Player.hpp"
#include "Game.hpp"

namespace coup{

    void Player::income(){
        this->money++;
    }
    void Player::foreign_aid(){
        this->money += 2;
    }
    void Player::coup(Player &p){
        cout << "coup\n";
    }
    void Player::role(){
        cout << "you are a regular player";
    }
    int Player::coins(){
        return this->money;
    }
    Player::Player(Game &game, string name)
    {
        this->name = name;
        this->game = &game;
        this->money = 0;
        
        game.addPlayer(name);
    }
    Player::~Player()
    {
    }
}