#include <iostream>

#include "../alib/doormgr.h"
#include "../alib/utils.h"
#include "../alib/rseed.h"

using namespace std;
void play_game();

int main() {
    while(true) {
        play_game();
        cout << endl << "Do you want to play again?" << endl;
        if (!play_again()) {
            break;
        }
    }
    return 0;
}

void play_game() {
    int selectedDoor;
    bool hasSwitched;
    DoorManager dm = DoorManager();

    dm.start_new_game();

    //ask player to choose one of the doors
    cout << "Select door number: 1, 2, or 3: ";
    selectedDoor = get_door_number();

    //set up the doors
    dm.set_doors(selectedDoor);

    //open the 'bad door'
    cout << "Monty opens door number " << dm.get_bad_door() << endl;
    cout << "There is nothing behind it...";

    //ask if the user wants to switch
    cout << "Do you want to change your initial choice, input 'y/n'?" << endl;
    hasSwitched = alter_choice();

    //set switch
    dm.set_switch(hasSwitched);

    //reveal game outcome
    if ( dm.query_door() ) {
        cout << "You Won!" << endl;
    }
    else {
        cout << "You Lost!" << endl;
    }

    //display game summary
    dm.show_results();
}