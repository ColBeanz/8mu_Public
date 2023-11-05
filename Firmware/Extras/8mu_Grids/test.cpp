#include "grids.h"
#include <iostream>
#include <string>
#include <bitset>

using namespace grids;

int main() {
    Grids grids = Grids();
    grids.Init();
    
    for (uint8_t i = 0; i < 192; i++) {
        grids.NextStep();
    }

    return 0;
}