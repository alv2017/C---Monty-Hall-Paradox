#ifndef RSEED_H_
#define RSEED_H_

#include <iostream>
#include <chrono>

class RandomSeed {
    private:
        static unsigned long get_current_time();

    public:
        static unsigned int get_rseed();
};

#endif /* RSEED_H_ */