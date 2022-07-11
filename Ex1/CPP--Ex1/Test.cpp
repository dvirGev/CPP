/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dvir gev
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}

TEST_CASE("Small input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n$+$\n$+$\n$+$\n$$$"));
	CHECK(nospaces(mat(5, 1, '#', '$')) == nospaces("#####"));
	CHECK(nospaces(mat(1, 5, '#', '$')) == nospaces("#####"));
	CHECK(nospaces(mat(1, 1, '#', '$')) == nospaces("#"));
	
	CHECK(nospaces(mat(5, 5, '#', '#')) == nospaces("#########################"));
	/* Add more test here */
}

TEST_CASE("Big input")
{
	CHECK(nospaces(mat(3,479, '$', '%')) == nospaces("$$$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$%$$$$"));
	CHECK(nospaces(mat(49,251, '$', '%')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$$%$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$%$$%$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$%$$%$%$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$$$$$$$$$$$$$$$$$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%%%%%%%%%%%%%%%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$$$$$$$$$$$$$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%%%%%%%%%%%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$$$$$$$$$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%%%%%%%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$$$$$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%%%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$%%%$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%$$$$$%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$%%%%%%%$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%$$$$$$$$$%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$%%%%%%%%%%%$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%$$$$$$$$$$$$$%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$%%%%%%%%%%%%%%%$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%$$$$$$$$$$$$$$$$$%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$%$%$$%$%$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$%$%$$%$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$%$$%$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$%$$%$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$%$$%$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$%$$%$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$%$$%$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$%$$%$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$%$$%$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$%$$%$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$%$$%$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$%$$%$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$%$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%$$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));
}


TEST_CASE("Even input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(5, 10, '$', '%'));
}
TEST_CASE("Not Positive input") {
    CHECK_THROWS(mat(-5, 5, '$', '%'));
	CHECK_THROWS(mat(5, -5, '$', '%'));
	CHECK_THROWS(mat(5, 0, '$', '%'));
	CHECK_THROWS(mat(0, 5, '$', '%'));
	CHECK_THROWS(mat(0, 0, '$', '%'));
	CHECK_THROWS(mat(-5, -5, '$', '%'));
}
TEST_CASE("Invalid char")
{
	for (int i = 0; i < 33; i++)
	{
		CHECK_THROWS(mat(5, 5, i, '$'));
		CHECK_THROWS(mat(5, 5, '$', i));
	}
	CHECK_THROWS(mat(5, 5, 127, '$'));
	CHECK_THROWS(mat(5, 5, '$', 127));
}
TEST_CASE("Too much col")
{
	CHECK_THROWS(mat(51,3, '$', '%'));
}