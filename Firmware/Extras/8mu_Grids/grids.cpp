#include "grids.h"
#include "iostream"

using namespace grids;

/* extern */
Grids grids_;

void Grids::Init() {
    pattern_generator.Init();
    pattern_generator.set_clock_resolution(2);

    PatternGeneratorSettings* settings = pattern_generator.mutable_settings();
    settings->options.drums.x = 64;
    settings->options.drums.y = 32;
    settings->options.drums.randomness = 64;
    settings->density[0] = 127;
    settings->density[1] = 255;
    settings->density[2] = 127;
    //settings->options.euclidean_length[0] = 65; // seems to be equivelent to x, y and randomness 
    //settings->options.euclidean_length[1] = 255;
    //settings->options.euclidean_length[2] = 16;
}

void Grids::NextStep() {
    pattern_generator.TickClock(1);

    //DEBUG:
    // static uint8_t step = 0;
    // if (step % kPulsesPerStep == 0) {
    //     std::bitset<8> bits(pattern_generator.state());
    //     std::cout << "state=" + bits.to_string() + " ";
    //     std::bitset<8> part1(pattern_generator.part_level(0));
    //     std::bitset<8> part2(pattern_generator.part_level(1));
    //     std::bitset<8> part3(pattern_generator.part_level(2));
    //     std::cout << "part1=" + part1.to_string() + " part2=" + part2.to_string() + " part3=" + part3.to_string() + "\n";
    // }

    // if (++step >= kPulsesPerStep) {
    //     step -= kPulsesPerStep;
    // }
}

void Grids::trigger_midi() {
    uint8_t part1Level = pattern_generator.part_level(0) >> 1; // scale it to midi velocity
    uint8_t part2Level = pattern_generator.part_level(1) >> 1;
    uint8_t part3Level = pattern_generator.part_level(2) >> 1;

    std::cout << "part1Level=" << (int)part1Level;
}