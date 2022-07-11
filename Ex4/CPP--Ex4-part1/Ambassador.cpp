#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &game, string name) : Player(game,name)
    {
    }
    
    Ambassador::~Ambassador()
    {
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        cout << "transfer\n";
    }
}