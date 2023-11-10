***8mu Grids***

This is a midi version of Mutable Instruments Grids.

Issues I had to overcome:

When setting up dependencies and getting issues like missing dependencies, check the forum post [here](https://lowpowerlab.com/forum/moteino/not-able-to-compile-with-samd-version-1-6-1-with-arduino-samd-1-8-11/)

The text inside quotes:
```
- go to platform.txt and find these lines:

Code: [Select]

compiler.arm.cmsis.c.flags="-I{runtime.tools.CMSIS-5.4.0.path}/CMSIS/Core/Include/" "-I{runtime.tools.CMSIS-5.4.0.path}/CMSIS/DSP/Include/" "-I{runtime.tools.CMSIS-Atmel-1.2.0.path}/CMSIS/Device/ATMEL/"
compiler.arm.cmsis.ldflags="-L{runtime.tools.CMSIS-5.4.0.path}/CMSIS/Lib/GCC/" -larm_cortexM0l_math


Replace those lines with the following, save & you may need to close and restart the IDE.
Let me know if this fixes the compile error you were having before.

Code: [Select]

compiler.arm.cmsis.c.flags="-I{runtime.tools.CMSIS-4.5.0.path}/CMSIS/Include/" "-I{runtime.tools.CMSIS-Atmel-1.2.0.path}/CMSIS/Device/ATMEL/"
compiler.arm.cmsis.ldflags="-L{runtime.tools.CMSIS-4.5.0.path}/CMSIS/Lib/GCC/" -larm_cortexM0l_math
```

To update the device, I found a github repo with a python program to generate the uf2 file [here](https://github.com/microsoft/uf2)
Running the command -> `python3 uf2conv.py -f 0x68ed2b88 -b 0x2000 '/Users/colin/git/8mu_Public/Firmware/Extras/8mu_Grids/build/music thing.samd.musicthing_musicthing_m0_plus/8MU_Grids.ino.bin' -o 8mu_Grids.uf2` to send the built file to the device.
