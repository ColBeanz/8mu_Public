#include "grids.h"
#include "iostream"

using namespace grids;

void Grids::Init() {
    pattern_generator.Init();
    pattern_generator.set_clock_resolution(2);

    PatternGeneratorSettings* settings = pattern_generator.mutable_settings();
    settings->options.drums.x = 0;
    settings->options.drums.y = 0;
    settings->options.drums.randomness = 0;
    settings->density[0] = 255;
    settings->density[1] = 255;
    settings->density[2] = 255;
    settings->options.euclidean_length[0] = 8;
    settings->options.euclidean_length[1] = 8;
    settings->options.euclidean_length[2] = 4;
}

void Grids::NextStep() {
    pattern_generator.TickClock(1);

    //DEBUG:
    static uint8_t step = 0;
    if (step % kPulsesPerStep == 0) {
        std::bitset<8> bits(pattern_generator.state());
        std::cout << "state=" + bits.to_string() + " ";
        std::bitset<8> part1(pattern_generator.part_level(0));
        std::bitset<8> part2(pattern_generator.part_level(1));
        std::bitset<8> part3(pattern_generator.part_level(2));
        std::cout << "part1=" + part1.to_string() + " part2=" + part2.to_string() + " part3=" + part3.to_string() + "\n";
    }

    if (++step >= kPulsesPerStep) {
        step -= kPulsesPerStep;
    }
}

void Grids::trigger_midi() {

}