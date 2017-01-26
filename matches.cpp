#include "matches.h"

Matches::Matches() {
    wins = 0;
    losses = 0;
    points = 0;

    playerName = " ";
}

Matches::Matches(std::string name) {
    wins = 0;
    losses = 0;
    points = 0;
    playerName = name;
}

void Matches::addOpponent(std::string name) {
    opponents.push_back(name);
    results.push_back(' ');
}

void Matches::setResult(int week, int stocks, char result) {
    week--;

    results[week] = result;
    points += stocks;
}

std::ostream Matches::getRecord() {
    std::ostream os;
    os << "Wins: " << wins << " Losses: " << losses << " Points: " << points << endl;
    return os;
}

std::ostream Matches::getResult(int week) {
    std::ostream os;
    os << "Week: " << week << " vs. " << opponents[week - 1] << " " << results[week - 1];
    return os;
}
