#pragma once
#include <iostream>
using namespace std;
class Game
class Team
{
private:
    string name;
    double skill;

public:
    Team(string &name, double skill);
    ~Team();
};

Team::Team(string &name, double skill)
{
    this->name = name;
    this->skill = skill;
}

Team::~Team()
{
}
