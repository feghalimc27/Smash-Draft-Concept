#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>

class Player {

public:

    struct Schedule {
        int wins, losses, points;
        std::string playerName;
        std::vector<std::string> opponents;
        std::vector<char> results;

        void initialize(std::string name);
        void addOpponent(std::string name);
        void setResult(int week, int stocks, char result);

        std::ostream& getRecord(std::ostream& os);
        std::ostream& getResult(std::ostream& os, int week);

        friend std::ostream& operator<<(std::ostream& os, const Schedule& right);
    };

    Player();
    Player(int xSeed, int xPos);

    int getPosition();
    int getSeed();
    std::string getChar(int i);
    std::string getName();
    int getSize();
    int getWeeks();

    std::ostream& getResult(std::ostream& os, int week);
    std::ostream& getMatchup(std::ostream& os, int week);

    void setPosition(int i);
    void setSeed(int i);
    void setChar(int i, std::string newChar);
    void setName(std::string name);

    void initializeSchedule();
    void draftFighter(std::string fighter);
    void addToSchedule(std::string name);

    std::ostream& displaySchedule(std::ostream &os);
    std::ostream& displayRecord(std::ostream& os);

    bool operator <(const Player &right) { return draftPosition < right.draftPosition; }
    bool operator >(const Player &right) { return draftPosition > right.draftPosition; }

    friend std::ostream& operator << (std::ostream &os, const Player &player);

private:
    int draftPosition;
    int seed;
    std::string name;
    std::vector<std::string> characters;
    Schedule schedule;
};
#endif // PLAYER_H
