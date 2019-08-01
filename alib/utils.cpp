#include <iostream>
#include <cstdlib>
#include <ctime>

int get_random_number() {
    
}


int get_door_number() {
    std::string sInput;
    while(true) {
        getline(std::cin, sInput);
        int n = stoi(sInput);
        if (n>=1 && n<=3) {
            return n;
        }
        std::cout << "You must enter 1, 2, or 3. Re-Enter: ";
    }
}

bool yesNo(){
    std::string sInput;
    char ch;

    while(true) {
        getline(std::cin, sInput);
        ch = sInput[0];

        if (ch=='y' | ch=='Y') {
            return true;
        }
        else if (ch=='n' | ch=='N') {
            return false;
        }
        else {
            std::cout << "Enter 'y' for YES or 'n' for NO. Re-Enter: ";
        }
    }
}

bool alter_choice() {
    return yesNo();
}

bool play_again() {
    return yesNo();
}