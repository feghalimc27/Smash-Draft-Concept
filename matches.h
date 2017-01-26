#ifndef MATCHES_H
#define MATCHES_H

#include <vector>
#include <string>
#include <iostream>

class Matches {
private:
    int wins, losses, points;
    std::vector<std::string> opponents;
    std::vector<char> results;
    std::string playerName;
public:
    Matches();
    Matches(std::string name);

    void addOpponent(std::string name);
    void setResult(int week, int stocks, char result);

    std::ostream getRecord();
    std::ostream getResult(int week);
};

#endif // MATCHES_H
