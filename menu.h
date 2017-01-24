#ifndef MENU_H
#define MENU_H

void newDraft(int numPlayers, vector<Player> &players) {
    Player *player;
    std::string playerName;

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
}

void mainMenu() {
    cout << "Welcome to Smash Draft!" << endl << endl;
    cout << "Please select an option from below:\n 1) New Draft \n 2) Load Draft and Schedule \n 3) Exit \n";

    int choice = 0;
    vector<Player> players;

    while(choice !=3) {
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "How many players are in the draft?"<< endl;
                cin >> choice;
                cin.ignore();
                newDraft(choice, players);
                choice = 1;
            break;
            case 2:
                cout << "Kendall Jenner\n";
            break;
            case 3:
                choice = 3;
            break;
            default:
            break;
        }
    }
}

#endif // MENU_H
