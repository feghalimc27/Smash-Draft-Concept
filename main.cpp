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

    while(choice !=3) {
        cout << "Please select an option from below:\n 1) New Draft \n 2) Load Draft and Schedule \n 3) Exit \n";
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
                cout << "Please select an option from below:\n 1) New Draft \n 2) Load Draft and Schedule \n 3) Exit \n";
            break;
        }
    }
    return 0;
}
