#include "grids.h"
#include <iostream>
#include <string>
#include <bitset>

using namespace grids;

int main() {
    grids_.Init();
    
    for (uint8_t i = 0; i < 192; i++) {
        grids_.NextStep();
    }

    return 0;
}