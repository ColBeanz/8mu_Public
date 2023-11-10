#ifndef GRIDS_H_
#define GRIDS_H_

#include "pattern_generator.h"
#include "uMidi.h"

#define FADER_1 0
#define FADER_2 1
#define FADER_3 2
#define FADER_4 3
#define FADER_5 4
#define FADER_6 5
#define FADER_7 6
#define FADER_8 7
#define MS_PER_MIN 60000
#define CLOCK_RATE 24

const uint8_t leds[8] = {0, 44, 5, 7, 10, 11, 12, 13};// left to right

class Grids {
    public:
        static void Init();
        static void NextStep();
        static void RespondToFader(uint8_t fader, uint8_t value);
        static uint8_t MsPerClock(uint8_t bpm);

    private:
        static void trigger_midi();
        static void trigger_note(uint8_t channel, uint8_t note, uint8_t vel);
        static void led_on(uint8_t ledNumber);
        static void led_off(uint8_t ledNumber);
};

extern Grids grids_;

#endif // GRIDS_H_