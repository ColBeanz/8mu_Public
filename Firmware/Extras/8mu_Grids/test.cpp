#include "pattern_generator.h"
#include <iostream>
#include <string>
#include <bitset>

using namespace grids;

int main() {
    pattern_generator.Init();
    pattern_generator.set_clock_resolution(2);

    uint8_t state;
    std::string mystring;

    for (uint8_t i = 0; i < 128; i++) {
        pattern_generator.TickClock(i);

        state = pattern_generator.state();

        std::bitset<8> part1(pattern_generator.part_level(0));
        std::bitset<8> part2(pattern_generator.part_level(1));
        std::bitset<8> part3(pattern_generator.part_level(2));
        std::cout << "part1=" + part1.to_string() + " part2=" + part2.to_string() + " part3=" + part3.to_string() + "\n";
        //pattern_generator.IncrementPulseCounter();
    }

    return 0;
}