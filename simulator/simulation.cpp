#include <iostream>
#include <math.h>

#include "../alib/doormgr.h"
#include "../alib/utils.h"
#include "../alib/rseed.h"

using namespace std;

bool trial();
double trialSeries(int n);
void displayTrialStatistics(double p, int n);

int main() {
    int n = 10000;

    double p = trialSeries(n);
    
    displayTrialStatistics(p, n);

    return 0;
}

bool trial() {
    // probability to win after switching to another door
    bool sw = false;
    int selectedDoor;
    DoorManager dm;

    // trial game
    dm.start_new_game();

    dm.set_doors();

    // switch is a winning strategy
    if ( dm.get_alt_door() == dm.get_win_door() )
        sw = true;

    return sw;
}

double trialSeries(int n) {
    double p;
    double sum = 0;
    for (int i=0; i<n; ++i) {    
        sum += 1.0 * double( trial() );
    }
    p = sum / n;
    return p;
}

void displayTrialStatistics(double p, int n) {
    double std;
    double me;

    cout << "\nMonty Hall Paradox: Showing Simulation Results\n" << endl;

    // Number of trials
    cout << "Number of trials (or number of games played): ";
    cout << n << endl;

    // Estimated probability of winning the game after switching
    cout << "Estimated probability to win after switching: ";
    cout << p << endl;

    // Estimated standard error:
    std = sqrt(p * (1-p) / n );
    cout << "Estimated standard error: ";
    cout << std << endl;

    // 95% Confidence Interval
    me = 1.96 * std;

    cout << "Confidence interval: ";
    cout << "(" << p - me << ", ";
    cout << p + me << ")\n" << endl;
}