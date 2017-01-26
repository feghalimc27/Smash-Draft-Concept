#include "player.h"

Player::Player() {
    draftPosition = 1;
    seed = 8;
}

Player::Player(int xSeed, int xPos) {
    draftPosition = xPos;
    seed = xSeed;
}

int Player::getPosition() {
    return draftPosition;
}

int Player::getSeed() {
    return seed;
}
int Player::getSize() {
    return characters.size();
}

std::string Player::getName() {
    return name;
}

std::string Player::getChar(int i) {
    i--;
    if(i <= characters.size()) {
        return characters[i];
    }
    else {
        return "ERROR";
    }
}

void Player::setSeed(int i) {
    seed = i;
}

void Player::setPosition(int i) {
    draftPosition = i;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setChar(int i, std::string newChar) {
    characters[i] = newChar;
}

void Player::draftFighter(std::string fighter) {
    characters.push_back(fighter);
}

void Player::addToSchedule(std::string name) {
    if(name != this->name) {
        schedule.addOpponent(name);
    }
    else {
        return;
    }
}

std::ostream& operator<<(std::ostream& os, const Player &player) {
    os << player.name << "'s team: \n";
    for(int i = 0; i < player.characters.size(); i++) {
        os << "     "<< i + 1 << ". " << player.characters[i] << "\n";
    }
    return os;
}
