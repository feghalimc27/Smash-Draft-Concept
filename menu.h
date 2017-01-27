#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>>
#include <player.h>

void displayTeams(std::vector<Player> &players) {
    cout << "Draft Results:" << endl << endl;
    for(int i = 0; i < players.size(); i++) {
        cout << players[i] << endl;
    }
}

void actDraft(std::vector<Player> &players) {
    std::ifstream roster;
    std::vector<std::string> vRoster;
    std::string entry;
    bool invalidPick;
    int c, numPlayers, totalChars, perTeam, choice;

    totalChars = 0;

    numPlayers = players.size();
    do {

    cout << "Please select a game: \n1) Smash 4\n2) Melee\n3) Project M\n4) Smash 64\n5) Brawl" << endl;
    cin >> c;
    cin.ignore();

    if(c == 1) {
        roster.open("smash4roster.txt");
    }
    else if(c == 2) {
         roster.open("meleeroster.txt");
    }
    else if(c == 3) {
        roster.open("projectmroster.txt");
    }
    else if(c == 4) {
        roster.open("smash64roster.txt");
    }
    else if(c == 5) {
        roster.open("brawlroster.txt");
    }
    else {
        cout << "Invalid game chosen. Please choose a valid game" << endl;
    }
    } while(c > 5 || c <= 0);

        while(!roster.eof()) {
            getline(roster, entry);
            vRoster.push_back(entry);
            totalChars++;
        }
        c = 999;
        while(c > totalChars/numPlayers) {
            cout << "How many characters per team? " << endl;
            cin >> c;
            cin.ignore();
        }
        perTeam = c;
        invalidPick = true;
        for(int i = 0; i < numPlayers * perTeam;) {
            for(int j = 0; j < vRoster.size(); j++) {
                cout << j + 1 << ". " << vRoster[j] << endl;
            }
            for(int k = 0; k < numPlayers; k++) {
                cout << players[k].getName() << "'s turn.\n";
                cout << "Please enter a number for your selection:" << endl;
                choose4:
                cin >> choice;
                choice--;
                if(vRoster[choice] != " ") {
                    players[k].draftFighter(vRoster[choice]);
                    vRoster[choice] = " ";
                }
                else {
                    cout << "Character chosen. Please try again." << endl;
                    goto choose4;
                }
                i++;
                system("cls");
                for(int j = 0; j < vRoster.size(); j++) {
                    cout << j + 1 << ". " << vRoster[j] << endl;
                }
            }
            system("cls");
        }
        roster.close();
        return;
}

void newDraft(int numPlayers, vector<Player> &players) {
    Player *player;
    std::string playerName;
    char choice = 'k';

    // Define Draft Order
    for(int i = 0; i < numPlayers; ++i) {
        player = new Player(i+1, numPlayers - i);
        cout << "Please enter player " << i + 1 << "'s name: ";
        getline(cin, playerName);
        player->setName(playerName);
        player->initializeSchedule();
        players.push_back(*player);
    }
    for(int i = 0; i < numPlayers; ++i) {
        cout << "Player: " << players[i].getName();
        cout << " Seed: " << players[i].getSeed();
        cout << " Draft Position: " << players[i].getPosition() << endl;
    }
    cout << endl << "Begin draft? (Y/n)" << endl;
    while(choice != 'n') {
        cin >> choice;
        if(choice == 'Y' || choice == 'y') {
            system("cls");
            std::sort(players.begin(), players.end());
            actDraft(players);
            displayTeams(players);
            return;
        }
        else if(choice == 'N' || choice == 'n') {
            cout << "Clearing draft order..." << endl;
            for(int i = 0; i < numPlayers; ++i) {
                players.pop_back();
            }
            system("cls");
            return;
        }
        else {
            cout << endl << "Begin draft? (Y/n)" << endl;
        }
    }
}

void createSchedule(std::vector<Player> &players) {
    for(int i = 0; i < players.size(); i++) {
        for(int k = 0; k < players.size(); k++) {
            if(players[k].getName() != players[i].getName()) {
                players[i].addToSchedule(players[k].getName());
            }
        }
    }
}

void printSchedule(std::ostream& os, std::vector<Player> &players) {
    for(int i = 0; i < players.size(); i++) {
        players[i].displaySchedule(os);
    }
}

#endif // MENU_H
