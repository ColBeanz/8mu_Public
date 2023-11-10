#include "grids.h"
#include "iostream"
#include <Arduino.h>

using namespace grids;

/* extern */
Grids grids_;

uMidi myMidi;

void Grids::Init() {
    myMidi.begin();
    pattern_generator.Init();
    pattern_generator.set_clock_resolution(2);
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
    trigger_midi();
}

void Grids::RespondToFader(uint8_t fader, uint8_t value) {
    PatternGeneratorSettings* settings = pattern_generator.mutable_settings();

    switch (fader) {
        case FADER_1:
            settings->density[0] = value;
            break;
        case FADER_2:
            settings->density[1] = value;
            break;
        case FADER_3:
            settings->density[2] = value;
            break;
        case FADER_4:
            settings->options.drums.x = value;
            break;
        case FADER_5:
            settings->options.drums.y = value;
            break;
        case FADER_6:
            settings->options.drums.randomness = value;
            break;
        case FADER_7:
            // do nothing
            break;
        case FADER_8:
            // do nothing
            break;
        default:
            // do nothing
            break;
    }
}

uint8_t Grids::MsPerClock(uint8_t bpm) {
    return MS_PER_MIN / (CLOCK_RATE * bpm);
}

void Grids::trigger_midi() {
    uint8_t part1Level = pattern_generator.part_level(0) >> 1; // scale it to midi velocity
    uint8_t part2Level = pattern_generator.part_level(1) >> 1;
    uint8_t part3Level = pattern_generator.part_level(2) >> 1;

    trigger_note(1, 60, part1Level);
    trigger_note(2, 60, part2Level);
    trigger_note(3, 60, part3Level);
}

void Grids::trigger_note(uint8_t channel, uint8_t note, uint8_t vel) {
    if (vel == 0) {
        myMidi.hardNoteOff(channel, note);
        myMidi.noteOff(channel, note);
        led_off(channel - 1);
    } else {
        myMidi.hardNoteOn(channel, note, vel);
        myMidi.noteOn(channel, note, vel);
        led_on(channel - 1);
    }
}

void Grids::led_on(uint8_t ledNumber) {
    digitalWrite(leds[ledNumber], 1);
}

void Grids::led_off(uint8_t ledNumber) {
    digitalWrite(leds[ledNumber], 0);
}