#include "Duke.hpp"
namespace coup
{
    Duke::Duke(Game &game, string name) : Player(game, name)
    {
    }

    Duke::~Duke()
    {
    }
    void Duke::block(Player &p){
        cout<<"block\n";
    }
    void Duke::tax(){
        cout<< "tax\n";
    }

}