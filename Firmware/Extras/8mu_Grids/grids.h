#include "pattern_generator.h"
//#include "uMidi.h"

class Grids {
    public:
        void Init();
        void NextStep();

    private:
        uint8_t mode_;
        //uMidi myMidi;
        
        void trigger_midi();
};