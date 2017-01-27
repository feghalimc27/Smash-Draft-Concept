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

void::Player::initializeSchedule() {
    schedule.initialize(this->name);
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

std::ostream& Player::displaySchedule(std::ostream &os) {
    os << name << "'s Schedule: " << std::endl;
    os << "     " << schedule;
    return os;
}

std::ostream& Player::displayRecord(std::ostream &os) {
    schedule.getRecord(os);
    return os;
}

void Player::Schedule::initialize(std::string name) {
    wins = 0;
    losses = 0;
    points = 0;

    playerName = name;
}

void Player::Schedule::addOpponent(std::string name) {
    if(playerName != name) {
        opponents.push_back(name);
        results.push_back(' ');
    }
    else {
        return;
    }
}

void Player::Schedule::setResult(int week, int stocks, char result) {
    if(results[week - 1]) {
        results[week - 1] = result;
        points += stocks;
    }
}

std::ostream& Player::Schedule::getRecord(std::ostream& os) {
    os << "W: " << wins << " L: " << losses << " Points: " << points << "\n";
    return os;
}

std::ostream& Player::Schedule::getResult(std::ostream& os, int week) {
    if(results[week - 1]) {
        os << "Week: " << week << " vs. " << opponents[week - 1] << " " << results[week - 1] << "\n";
        return os;
    }
    else {
        os << " " << std::endl;
        return os;
    }
}

std::ostream& operator<<(std::ostream& os, const Player &player) {
    os << player.name << "'s team: \n";
    for(int i = 0; i < player.characters.size(); i++) {
        os << i + 1 << ". " << player.characters[i] << "\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Player::Schedule& right) {
    for(int i = 0; i < right.opponents.size(); i++) {
        os << " Week: " << i + 1 << " vs. " << right.opponents[i] << " " << right.results[i] << std::endl;
    }

    return os;
}
