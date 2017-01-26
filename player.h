#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "matches.h"

class Player {
private:
    int draftPosition;
    int seed;
    std::string name;
    std::vector<std::string> characters;
    Matches schedule;
public:
    Player();
    Player(int xSeed, int xPos);

    int getPosition();
    int getSeed();
    std::string getChar(int i);
    std::string getName();
    int getSize();

    void setPosition(int i);
    void setSeed(int i);
    void setChar(int i, std::string newChar);
    void setName(std::string name);

    void draftFighter(std::string fighter);
    void addToSchedule(std::string name);

    bool operator <(const Player &right) { return draftPosition < right.draftPosition; }
    bool operator >(const Player &right) { return draftPosition > right.draftPosition; }

    friend std::ostream& operator << (std::ostream &os, const Player &player);
};
#endif // PLAYER_H
