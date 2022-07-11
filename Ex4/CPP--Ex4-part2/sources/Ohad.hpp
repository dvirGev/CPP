#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    class Ohad : public Player
    {
    private:
        /* data */
    public:
        Ohad(Game &game, string name);
        virtual void foreign_aid();
    };
}
