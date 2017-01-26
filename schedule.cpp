#include "schedule.h"

Schedule::Schedule() {
    wins = 0;
    losses = 0;
    points = 0;

    name = " ";
}

Schedule::Schedule(string name) {
    wins = 0;
    losses = 0;
    points = 0;

    this->name = name;
}

void Schedule::setResult(int week, char result, int stocks) {
    week--;
    points += stocks;
    results[i] = result;
}

ostream Schedule::getRecord() {
    ostream os;
    os << "W: " << wins << " L: " << losses << " Points: " << points << endl;
    return os;
}

ostream Schedule::getResult(int week) {
    week--;
    ostream os;

    os << "Week " << week + 1 << " result: " << endl;
    os << "vs. " << opponents[week] << " "
}
