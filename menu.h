#ifndef MENU_H
#define MENU_H

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
    while(choice != 'n') {

        if(choice == 'Y' || choice == 'y') {
            system("cls");
            cout << "Man do I love boobs!" << endl;
            return;
        }
        else if(choice == 'N' || choice == 'n') {
            choice = 'n';
            cout << "deleting draft order..." << endl;
            system("cls");
            return;
        }
        else {
            cout << endl << "Begin draft? (Y/n)" << endl;
            cin >> choice;
        }
    }
}

#endif // MENU_H
