/*
  Music Thing Modular 8mu Firmware - Hello World

  This is a simple midi step sequencer
  Positions of 8 faders map to 8 steps, output on midi channel 1 via USB
  Leds show the active step
  Accelerometer measures if the front or back of 8mu is lifted, and maps that to Midi velocity
  Buttons on the back influence clock speed

  Add `https://raw.githubusercontent.com/TomWhitwell/board-defs/master/package_musicthing_samd21_index.json`
  to "Additional Boards Manager Urls" in the Arduino IDE Preferences to install 'MusicThing M0 Plus' into the Arduino IDE

  NB: Select USB Stack TinyUSB

  Use library BMI160-Arduino-master
  https://github.com/hanyazou/BMI160-Arduino

  Using library Adafruit_TinyUSB_Library at version 0.10.0


*/

#include "grids.h"

using namespace grids;

// Create Midi
// uMidi myMidi;


// Pin assignments for leds, buttons, faders 
//const byte leds[8] = {0, 44, 5, 7, 10, 11, 12, 13};// left to right
const byte buttons[6] = {29, 30, 28, 2, 31, 3}; // A, B, C, D, Left, Right
const byte faders[8] = {A0, A1, A2, A3, A4, A5, A10, A11}; // left to right

int IMU_readings[6]; // variable to store accelerometer readings

int count = 0;
int bpm = 120;
int msPerClock = 0;
unsigned long time_now = 0;

void setup() {

  // Setup Leds as output pins
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }

  grids_.Init();

  msPerClock = grids_.MsPerClock(bpm);
  // Start Midi
  //myMidi.begin();

  // Setup buttons as input pins
  for (int i = 0; i < 6; i++) {
    pinMode (buttons[i], INPUT_PULLUP  );
  }
}

void loop() {
  time_now = millis();
  // // Light LED
  // digitalWrite(leds[count], 1);

  // // Read Fader
  // int read = analogRead(faders[count]);
  for (uint8_t fader = 0; fader < 8; fader++) {
    int read = analogRead(faders[fader]);
    uint8_t x = map(read, 0, 1023, 255, 0);
    grids_.RespondToFader(fader, x);
  }
  // // Convert to note and send Midi
  // int note = map(read, 0, 1023, 81, 33);

  // // Send midi note
  // myMidi.hardNoteOn(1, 36, 127);

  // // Read buttons
  // // Low = button pressed
  // for (int i = 0; i < 6; i++) {
  //   Serial.print(digitalRead(buttons[i]));
  //   Serial.print (" ");
  // }

  // // Map buttons to BPM
  if (!digitalRead(buttons[4])) { // Left button
    bpm--;
    msPerClock = grids_.MsPerClock(bpm);
  }
  else if (!digitalRead(buttons[5])) { // Right button
    bpm++;
    msPerClock = grids_.MsPerClock(bpm);
  }
  // else if (!digitalRead(buttons[2])) bpm = 240;
  // else if (!digitalRead(buttons[3])) bpm = 480;
  // else bpm = 120;
  grids_.NextStep();

  // // Delay according to BPM
  while(millis() < time_now + msPerClock){
        //wait approx. [msPerClock] ms
  }

  // // End note
  // myMidi.hardNoteOff(1, 36);

  // // Turn off LED
  // digitalWrite(leds[count], 0);

  // // Increment and return to zero when necessary
  // count++;
  // if (count >= 8) count = 0;

}