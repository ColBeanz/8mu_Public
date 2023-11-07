#ifndef GRIDS_H_
#define GRIDS_H_

#include "pattern_generator.h"
//#include "uMidi.h"

//uMidi myMidi;

class Grids {
    public:
        static void Init();
        static void NextStep();

    //private:
        static void trigger_midi();
};

extern Grids grids_;

#endif // GRIDS_H_