#ifndef GRIDS_H_
#define GRIDS_H_

#include "pattern_generator.h"
//#include "uMidi.h"

class Grids {
    public:
        static void Init();
        static void NextStep();
        static inline uint8_t* mutable_int() {
            return &x;
        }

    private:
        //uMidi myMidi;
        static void trigger_midi();
        static uint8_t x;
};

extern Grids grids_;

#endif // GRIDS_H_