#include <iostream>
#include <chrono>

#include "math.h"
#include "limits.h"
#include "rseed.h"

unsigned long RandomSeed::get_current_time() {
    std::chrono::microseconds mcs = std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch());

    return mcs.count();
}

unsigned int RandomSeed::get_rseed() {
    return RandomSeed::get_current_time() % UINT_MAX;
}

