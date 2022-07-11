#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:
        Player *sucker;
        int moneySteal;
    public:
        Captain(Game &game, string name);
        void block(Player &p);
        void blockMe();
        void steal(Player &p);
        string role();
        ~Captain();
    };


}