/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Dvir GEV>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("good input")
{
	ariel::Notebook notebook;
	notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");
	CHECK(notebook.read(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/4) == "abcd");
	CHECK(notebook.read(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3) == "_b_");
	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	notebook.erase(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3);
	// writes ~ instead of _ in line 99, b in line 100 and _ again in line 99
	CHECK(notebook.read(/*page=*/100, /*row=*/99, /*column=*/51, Direction::Vertical, /*length=*/3) == "~~~");

	notebook.write(10,10,10,Direction::Horizontal,"abcd");
	CHECK(notebook.read(/*page=*/10, /*row=*/10, /*column=*/10, Direction::Horizontal, /*length=*/4) == "abcd");
	notebook.erase(10,10,10,Direction::Horizontal,4);
	CHECK(notebook.read(/*page=*/10, /*row=*/10, /*column=*/10, Direction::Horizontal, /*length=*/4) == "~~~~");

	notebook.write(20,20,20,Direction::Vertical,"abcd");
	CHECK(notebook.read(/*page=*/20, /*row=*/20, /*column=*/20, Direction::Vertical, /*length=*/4) == "abcd");
	notebook.erase(20,20,20,Direction::Vertical,4);
	CHECK(notebook.read(/*page=*/20, /*row=*/20, /*column=*/20, Direction::Vertical, /*length=*/4) == "~~~~");

	notebook.write(30,30,30,Direction::Horizontal,"abcd");
	CHECK(notebook.read(/*page=*/30, /*row=*/30, /*column=*/30, Direction::Horizontal, /*length=*/4) == "abcd");
	notebook.erase(30,30,30,Direction::Horizontal,4);
	CHECK(notebook.read(/*page=*/30, /*row=*/30, /*column=*/30, Direction::Horizontal, /*length=*/4) == "~~~~");

	notebook.write(40,40,40,Direction::Vertical,"abcd");
	CHECK(notebook.read(/*page=*/40, /*row=*/40, /*column=*/40, Direction::Vertical, /*length=*/4) == "abcd");
	notebook.erase(40,40,40,Direction::Vertical,4);
	CHECK(notebook.read(/*page=*/40, /*row=*/40, /*column=*/40, Direction::Vertical, /*length=*/4) == "~~~~");

	notebook.write(50,50,50,Direction::Horizontal,"abcd");
	CHECK(notebook.read(/*page=*/50, /*row=*/50, /*column=*/50, Direction::Horizontal, /*length=*/4) == "abcd");
	notebook.erase(50,50,50,Direction::Horizontal,4);
	CHECK(notebook.read(/*page=*/50, /*row=*/50, /*column=*/50, Direction::Horizontal, /*length=*/4) == "~~~~");
}

TEST_CASE("Bad input")
{
	Notebook notebook;
	notebook.write(/*page=*/100, /*row=*/100, /*column=*/50, Direction::Horizontal, "abcd");
	CHECK_THROWS(notebook.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz"));
	// throws error because writing the letter y will intersect with the letter c

	CHECK_THROWS(notebook.write(0,0,100,Direction::Horizontal,"ancd"));
	//throws error because writing the letter a out of the line lengh
	CHECK_THROWS(notebook.write(0,0,97,Direction::Horizontal, "abcd"));
	//throws error because writing the letter c out of the line lengh

	CHECK_THROWS(notebook.read(0,0,100,Direction::Horizontal,1));
	//throws error because readig out of the line lengh
	CHECK_THROWS(notebook.read(0,0,97,Direction::Horizontal,4));
	//throws error because readig out of the line lengh
	CHECK_THROWS(notebook.erase(0,0,100,Direction::Horizontal,1));
	//throws error because erase out of the line lengh
	CHECK_THROWS(notebook.erase(0,0,97,Direction::Horizontal,4));
	//throws error because erase out of the line lengh
}
