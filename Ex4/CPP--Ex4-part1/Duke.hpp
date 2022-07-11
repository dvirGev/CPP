#include "Player.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
        /* data */
    public:
        Duke(Game &game, string name);
        void block(Player &p);
        void tax();
        ~Duke();
    };
}