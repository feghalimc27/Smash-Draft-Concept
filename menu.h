#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <vector>
#include <string>

void actDraft(std::vector<Player> &players) {
    std::ifstream roster;
    std::vector<std::string> vRoster;
    std::string entry;
    bool invalidPick;
    int c, numPlayers, totalChars, perTeam, choice;

    totalChars = 0;

    numPlayers = players.size() + 1;

    cout << "Please select a game: \n1)Smash 4" << endl;
    cin >> c;
    cin.ignore();

    if(c == 1) {
        roster.open("smash4roster.txt");
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
                cout << vRoster[j] << endl;
            }
            for(int k = 0; k < players.size(); k++) {
                cout << players[k].getName() << "'s turn.\n";
                cout << "Please make a selection:" << endl;
                choose4:
                cin >> choice;
                choice--;
                if(vRoster[choice] != " ") {
                    players[k].draftFighter(vRoster[choice]);
                    vRoster[choice] = " ";
                }
                else {
                    cout << "Character drafted. Please try again." << endl;
                    goto choose4;
                }
                i++;
            }
        }
        cout << totalChars;
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
    cin.ignore();
    cout << endl << "Begin draft? (Y/n)" << endl;
    while(choice != 'n') {
        cin >> choice;
        if(choice == 'Y' || choice == 'y') {
            system("cls");
            actDraft(players);
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
