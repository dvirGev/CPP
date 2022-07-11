#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

TEST_CASE("RUN GAME")
{
	vector<string> playersNames = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
	Game game_1{};
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	//check all names in game is correct
	CHECK_EQ(game_1.players(), playersNames);

	// check if each players start with 0 coins;
	CHECK_EQ(duke.coins(), 0);
	CHECK_EQ(assassin.coins(), 0);
	CHECK_EQ(ambassador.coins(), 0);
	CHECK_EQ(captain.coins(), 0);
	CHECK_EQ(contessa.coins(), 0);

	//check if it onley the duke trun
	CHECK_EQ(game_1.turn(), "Moshe");
	
	CHECK_THROWS(assassin.income());
	CHECK_THROWS(ambassador.income());
	CHECK_THROWS(captain.income());
	CHECK_THROWS(contessa.income());

	// throws no exceptions all players play
	CHECK_NOTHROW(duke.income());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.income());
	CHECK_NOTHROW(captain.income());
	CHECK_NOTHROW(contessa.income());
	
	// throws exception, it is player's turn now
	CHECK_THROWS(assassin.income());

	//now is good
	CHECK_NOTHROW(duke.income());
	CHECK_NOTHROW(assassin.foreign_aid());

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	CHECK_THROWS(captain.block(duke));

	CHECK_EQ(duke.coins(), 2); // prints 2
	CHECK_EQ(assassin.coins(), 3); // prints 3

	// throws exception, the last operation duke performed
	// is foreign aid, which cannot be blocked by contessa
	CHECK_THROWS(contessa.block(assassin));

	CHECK_NOTHROW(duke.block(assassin));
	CHECK_EQ(assassin.coins(), 1); // prints 1

	CHECK_NOTHROW(ambassador.transfer(duke, assassin)); //transfers 1 coin from duke to assassin
	CHECK_NOTHROW(captain.foreign_aid());
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.foreign_aid());
	CHECK_NOTHROW(captain.steal(contessa));
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	// no exception, assassin can coup with only 3 coins
	CHECK_NOTHROW(assassin.coup(duke));
	playersNames = {"Yossi", "Meirav", "Reut", "Gilad"};
	CHECK_EQ(game_1.players(), playersNames);
	CHECK_NOTHROW(contessa.block(assassin));
	playersNames = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
	CHECK_EQ(game_1.players(), playersNames);
}