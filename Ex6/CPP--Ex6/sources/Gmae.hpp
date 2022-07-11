#pragma once
#include <iostream>
using namespace std;

class Team;
class Gmae
{
private:
    Team *homeTeam, *outTeam;
public:
    Gmae(Team *homeTeam, Team *outTeam);
    
    ~Gmae();
};

Gmae::Gmae(Team *homeTeam, Team *outTeam)
{
    this->homeTeam = homeTeam;
    this->outTeam = outTeam;
}

Gmae::~Gmae()
{
}
