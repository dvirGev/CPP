#include "Player.hpp"

using namespace std;
namespace coup{
    class Assassin : public Player
    {
    private:
        Player *target;
    public:
        Assassin(Game &game, string name);
        string role();
        void coup(Player &p);
        void blockMe();
        ~Assassin();
    };

}