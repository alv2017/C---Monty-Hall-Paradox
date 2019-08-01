#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "rseed.h"
#include "doormgr.h"

using namespace std;        

DoorManager::DoorManager() {       
    srand( RandomSeed::get_rseed() ); 
};

void DoorManager::start_new_game() {
    winDoor = rand() % 3;
    selDoor = rand() % 3;
}

void DoorManager::set_doors() {
    int rf;
    if (selDoor == winDoor) {        
        rf = rand() % 2 ;
        altDoor = (selDoor + 1 + rf) % 3;
    }
    else {
        altDoor = winDoor;
    }
    badDoor = 3 - selDoor - altDoor;
}


void DoorManager::set_doors(int n) {
    int rf;
    selDoor = n - 1;
    if (selDoor == winDoor) {        
        rf = rand() % 2 ;
        altDoor = (selDoor + 1 + rf) % 3;
    }
    else {
        altDoor = winDoor;
    }
    badDoor = 3 - selDoor - altDoor;
}

void DoorManager::set_switch(bool sw) {
    if (sw) {
        hasSwitched = true;
        selDoor = altDoor;
    }
}

void DoorManager::show_results() {
    cout << "\nGame Summary: \n" << endl;
    cout << "Win Door: " << get_win_door() << " | ";
    cout << "Bad Door: " << get_bad_door() << " | ";
    cout << "Sel. Door: " << get_sel_door() << " | ";
    cout << "Alt. Door: " << get_alt_door() << " | ";
    cout << "Switched: " << hasSwitched << endl;
}
