/*
   Ultralight Midi driver
   (c) 2023 by Tom Whitwell
   MIT License
*/

#ifndef U_MIDI_H_
#define U_MIDI_H_

#pragma once

// activates printing of debug messages
#define DEBUG 0

#define Proto_3_2

// wrap code to be executed only under DEBUG conditions in D()
#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

#define MAKEHEADER(cn, cin) (((cn & 0x0f) << 4) | cin)


// Class member variables, initialised at startup
const uint8_t NOTE_OFF = 0x80;
const uint8_t NOTE_ON = 0x90;
const uint8_t CONT_CONT = 0xB0;
const uint8_t SYSEX = 0xF0;
const uint8_t SYSEX_END = 0xF7;

class uMidi
{
  public:

    // Constructor
    uMidi();

    // Initialises Midi
    void begin();
    bool _midiThru = true;

    // Various controls
    void noteOn(uint8_t channel, uint8_t note, uint8_t velocity);
    void hardNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
    void noteOff(uint8_t channel, uint8_t note);
    void hardNoteOff(uint8_t channel, uint8_t note);
    void CC(uint8_t channel, uint8_t controller, uint8_t level);
    void hardCC(uint8_t channel, uint8_t controller, uint8_t level);
    void changeHardMidiMode(bool _midiMode);


    // Check for messages
    void newMessage();
    bool sysexAvailable();
    uint8_t *returnSysex();


    // Send sysex
    void sendSysEx(int length, uint8_t *data);

  private:
    static const int bufferSize = 124;
    uint8_t midiBuffer[bufferSize];
    uint8_t oldPacket[4];
    int bufferLength = -1;
    uint8_t recievingSysex = false;
    uint8_t recievedSysex = false;


    // void printHex(uint8_t num) {
    //   char hexCar[2];

    //   //sprintf(hexCar, "%02X", num);
    //   D(Serial.print(hexCar));
    // }

    // void printHexArray(uint8_t* array, int size) {
    //   for (int i = 0; i < size; i++) {
    //     printHex(array[i]);
    //     D(Serial.print(" "));
    //   }
    //   D(Serial.println());
    // }
    // void printBytesAsIntsArray(uint8_t* array, int size) {
    //   for (int i = 0; i < size; i++) {
    //     Serial.print(array[i]);
    //     D(Serial.print(" "));
    //   }
    //   D(Serial.println());
    // };

};

#endif // U_MIDI_H_