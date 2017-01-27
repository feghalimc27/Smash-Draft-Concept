#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "player.h"
#include "menu.h"

int main() {
    cout << "Welcome to Smash Draft!" << endl << endl;

    int choice = 0;
    vector<Player> players;

    while(choice !=4) {
        cout << "Please select an option from below:\n 1) New Draft \n 2) View Teams and Schedule \n 3) Start Games 4) Exit \n";
        cin >> choice;
        switch(choice) {
            case 1:
                // clear players vector before each new draft
                players.clear();

                cout << "How many players are in the draft?"<< endl;
                cin >> choice;
                cin.ignore();
                newDraft(choice, players);
                createSchedule(players);
                choice = 1;
            break;
            case 2:
                displayTeams(cout, players);
                printSchedule(cout, players);
            break;
            case 3:
                choice = 3;
            break;
            case 4:
                choice = 4;
            default:
                cout << "Please select an option from below:\n 1) New Draft \n 2) Load Draft and Schedule \n 3) Exit \n";
            break;
        }
    }
    return 0;
}
