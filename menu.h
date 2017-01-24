#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include <string>

void displayRoster(int c) {
    std::ifstream roster;
    std::vector<std::string> vRoster;
    std::string entry;

    if(c == 1) {
        roster.open("smash4roster.txt");
        while(!roster.eof()) {
            getline(roster, entry);
            cout << entry;
            vRoster.push_back(entry);
        }
        for(int i = 0; i < vRoster.size(); ++i) {
            cout << vRoster[i] << endl;;
        }
        for(int i = 0; i < vRoster.size(); ++i) {
        }
        roster.close();
        return;
    }
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
            displayRoster(1);
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

#endif // MENU_H
