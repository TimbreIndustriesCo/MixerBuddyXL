#include <Control_Surface.h>

USBMIDI_Interface usbmidi;  
HardwareSerialMIDI_Interface  serialmidi {Serial1, MIDI_BAUD};

BidirectionalMIDI_PipeFactory<2> pipes;

// MIDI CC switches. Works like an on-off toggle. 
// The way you should read the code below used for the switches is the following:
//
// CCbutton [name] {
// [used in on board],
// {[CC number], Channel_[MIDI channel number]}
//};
//
// For CC editing, only change the [CC number] and the [MIDI channel number]

CCButton button1 {
  6,
  {0, Channel_1},
};

CCButton button2 {
  7,
  {0, Channel_2},
};

CCButton button3 {
  8,
  {0, Channel_3},
};

CCButton button4 {
  9,
  {0, Channel_4},
};

CCButton button5 {
  10,
  {0, Channel_5},
};

CCButton button6 {
  11,
  {0, Channel_6},
};

CCButton button7 {
  12,
  {0, Channel_7},
};

CCButton button8 {
  18,
  {0, Channel_8},
};

CCButton button9 {
  19,
  {0, Channel_9},
};

CCButton button10 {
  20,
  {0, Channel_10},
};

CCButton button11 {
  21,
  {0, Channel_11},
};

CCButton button12 {
  22,
  {0, Channel_12},
};

//Everything below these lines are multiplexers: A separate small board that switches between selecions. 
//All multiplexers are connected by pots. See Mixer Buddys MIDI Chart file for the correct connection if you want to switch out the CCs. 

CD74HC4067 mux1 {
  14,       // Analog input pin
  {5, 4, 3, 2} // Address pins S0, S1, S2
};
 
//Here's how to read the multiplexer code
//
// { mux[multiplexer number].pin[pin number], { [CC number], Channel_[MIDI channel number]} },
//
// In the same regard as the switches, to edit MIDI CCs, the only thing you will have to edit is:
// [CC number] and the [MIDI channel number]

CCPotentiometer potentiometersmux1[] {
 { mux1.pin(0), { 5, Channel_1 } },
  { mux1.pin(1), { 4, Channel_1 } },
  { mux1.pin(2), { 3, Channel_1 } },
  { mux1.pin(3), { 2, Channel_1 } },
  { mux1.pin(4), { 1, Channel_1 } },
  { mux1.pin(5), { 5, Channel_2 } },
  { mux1.pin(6), { 4, Channel_2 } },
  { mux1.pin(7), { 3, Channel_2 } },
  { mux1.pin(8), { 2, Channel_2 } },
  { mux1.pin(9), { 1, Channel_2 } },
  { mux1.pin(10), { 5, Channel_3 } },
  { mux1.pin(11), { 4, Channel_3 } },
  { mux1.pin(12), { 3, Channel_3 } },
  { mux1.pin(13), { 2, Channel_3 } },
  { mux1.pin(14), { 1, Channel_3 } },
  { mux1.pin(15), { 5, Channel_4 } },
};

CD74HC4067 mux2 {
  15,       // Analog input pin
  {5, 4, 3, 2} // Address pins S0, S1, S2
};
 
CCPotentiometer potentiometersmux2[] {
  { mux2.pin(0), { 4, Channel_4 } },
  { mux2.pin(1), { 3, Channel_4 } },
  { mux2.pin(2), { 2, Channel_4 } },
  { mux2.pin(3), { 1, Channel_4 } },
  { mux2.pin(4), { 5, Channel_5 } },
  { mux2.pin(5), { 4, Channel_5 } },
  { mux2.pin(6), { 3, Channel_5 } },
  { mux2.pin(7), { 2, Channel_5 } },
  { mux2.pin(8), { 1, Channel_5 } },
  { mux2.pin(9), { 5, Channel_6 } },
  { mux2.pin(10), { 4, Channel_6 } },
  { mux2.pin(11), { 3, Channel_6 } },
  { mux2.pin(12), { 2, Channel_6 } },
  { mux2.pin(13), { 1, Channel_6 } },
  { mux2.pin(14), { 5, Channel_7 } },
  { mux2.pin(15), { 4, Channel_7 } },
};

CD74HC4067 mux3 {
  16,       // Analog input pin
  {5, 4, 3, 2} // Address pins S0, S1, S2
};
 
CCPotentiometer potentiometersmux3[] {
  { mux3.pin(0), { 3, Channel_7 } },
  { mux3.pin(1), { 2, Channel_7 } },
  { mux3.pin(2), { 1, Channel_7 } },
  { mux3.pin(3), { 5, Channel_8 } },
  { mux3.pin(4), { 4, Channel_8 } },
  { mux3.pin(5), { 3, Channel_8 } },
  { mux3.pin(6), { 2, Channel_8 } },
  { mux3.pin(7), { 1, Channel_8 } },
  { mux3.pin(8), { 5, Channel_9 } },
  { mux3.pin(9), { 4, Channel_9 } },
  { mux3.pin(10), { 3, Channel_9 } },
  { mux3.pin(11), { 2, Channel_9 } },
  { mux3.pin(12), { 1, Channel_9 } },
  { mux3.pin(13), { 5, Channel_10 } },
  { mux3.pin(14), { 4, Channel_10 } },
  { mux3.pin(15), { 3, Channel_10 } },
};

CD74HC4067 mux4 {
  17,       // Analog input pin
  {5, 4, 3, 2} // Address pins S0, S1, S2
};
 
CCPotentiometer potentiometersmux4[] {
  { mux4.pin(0), { 2, Channel_10 } },
  { mux4.pin(1), { 1, Channel_10 } },
  { mux4.pin(2), { 5, Channel_11 } },
  { mux4.pin(3), { 4, Channel_11 } },
  { mux4.pin(4), { 3, Channel_11 } },
  { mux4.pin(5), { 2, Channel_11 } },
  { mux4.pin(6), { 1, Channel_11 } },
  { mux4.pin(7), { 5, Channel_12 } },
  { mux4.pin(8), { 4, Channel_12 } },
  { mux4.pin(9), { 3, Channel_12 } },
  { mux4.pin(10), { 2, Channel_12 } },
  { mux4.pin(11), { 1, Channel_12 } },
};

void setup() {
  Control_Surface | pipes | usbmidi;
  Control_Surface | pipes | serialmidi;
  Control_Surface.begin();  // Initialize the Control Surface
}

void loop() {
  Control_Surface.loop();  // Update the Control Surface
}