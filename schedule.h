#ifndef SCHEDULE_H
#define SCHEDULE_H


class Schedule {
private:
    vector<string> opponents;
    int wins, losses, points;
    vector<char> results;
    string playerName;

public:
    Schedule();
    Schedule(string name);

    void setName(string name) { this->name = name; }

    void setOpponent(string name) { opponents.push_back(name); results.push_back(' '); }
    void setResult(int week, char result, int stocks);

    ostream getResult(int week);
    ostream getRecord();
};

#endif // SCHEDULE_H
