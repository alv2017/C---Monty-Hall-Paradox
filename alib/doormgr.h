#ifndef DOORMGR_H_
#define DOORMGR_H_

#include "rseed.h"

class DoorManager {
    private:
        int winDoor, selDoor, altDoor, badDoor;
        bool hasSwitched = false;
    public:
        DoorManager();
        void start_new_game();
        void set_doors();
        void set_doors(int n);
        void set_switch(bool sw);
        void show_results();
        
        int get_sel_door() {return selDoor + 1;}
        int get_win_door() {return winDoor + 1;}
        int get_alt_door() {return altDoor + 1;}
        int get_bad_door() {return badDoor + 1;}
        bool has_switched() {return hasSwitched;}

        bool query_door() {return selDoor==winDoor;}
};

#endif /* DOORMGR_H_ */