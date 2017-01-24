#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player {
private:
    int draftPosition;
    int seed;
    std::string name;
    std::vector<std::string> characters;
public:
    Player();
    Player(int xSeed, int xPos);

    int getPosition();
    int getSeed();
    std::string getChar(int i);
    std::string getName();

    void setPosition(int i);
    void setSeed(int i);
    void setChar(int i, std::string newChar);
    void setName(std::string name);

    void draftFighter(std::string fighter);
};
#endif // PLAYER_H
