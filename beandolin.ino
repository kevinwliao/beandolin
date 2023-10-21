#include <Audio.h>
#include "june5filtered.h"

june5filtered faustEffect;
AudioInputI2S in;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;

AudioMixer4 stringMix;
AudioMixer4 bassMix;
AudioMixer4 finalMix;

// sending mic input to faustEffect
AudioConnection patchCord0(in,0,faustEffect,0);

AudioConnection patchCord8(faustEffect,0,out,0);
AudioConnection patchCord9(faustEffect,0,out,1);

int root = 67;
float bassGain1;
float bassGain2;

void setup() {
  pinMode(0, INPUT);
  AudioMemory(6);
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC);
  audioShield.inputLevel(0.01);
  audioShield.micGain(10); // in dB
  audioShield.volume(1);

  // digital pins
  pinMode(3, INPUT); // configuring digital pin 0 as an input
  pinMode(5, INPUT); // configuring digital pin 0 as an input
  pinMode(9, INPUT); // configuring digital pin 0 as an input

  // mute bass for now
  faustEffect.setParamValue("bassGain1", 0);
  faustEffect.setParamValue("bassGain2", 0);

  // set to root
  update(0);
}

void loop() {
  if(digitalRead(3)) {
    update(0);
    Serial.println("root!");
  }
  else if(digitalRead(5)) {
    update(5);
    Serial.println("subdom!");
  }
  else if(digitalRead(9)) {
    update(7);
    Serial.println("dominant!");
  }
  bassGain1 = mapf(analogRead(A0), 0, 1023, 0, 0.3);
  bassGain2 = mapf(analogRead(A2), 0, 1023, 0, 0.3);
  faustEffect.setParamValue("bassGain1", bassGain1);
  faustEffect.setParamValue("bassGain2", bassGain2);
  delay(10);
}

void update(int degree) {
  faustEffect.setParamValue("midi1", root + degree);
  faustEffect.setParamValue("midi2", root + degree + 4);
  faustEffect.setParamValue("midi3", root + degree + 7);
  faustEffect.setParamValue("midi4", root + degree + 12);
}


// https://forum.arduino.cc/t/map-to-floating-point/3976/2

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/* FAUST CODE */

/* import("stdfaust.lib");
import("stdfaust.lib");

detune = 0.98;

freq1 = hslider("midi1", 70, 0, 127, 1) : ba.midikey2hz : si.smoo;
freq2 = hslider("midi2", 74, 0, 127, 1) : ba.midikey2hz : si.smoo;
freq3 = hslider("midi3", 79, 0, 127, 1) : ba.midikey2hz : si.smoo;
freq4 = hslider("midi4", 82, 0, 127, 1) : ba.midikey2hz : si.smoo;

length1 = freq1 : pm.f2l;
length2 = freq2 : pm.f2l;
length3 = freq3 : pm.f2l;
length4 = freq4 : pm.f2l;

model1 = _ : pm.guitarModel(length1, 0.5);
model2 = _ : pm.guitarModel(length2, 0.5);
model3 = _ : pm.guitarModel(length3, 0.5);
model4 = _ : pm.guitarModel(length4, 0.5);

bassGain1 = hslider("bassGain1", 0.1, 0, 1, 0.001) : si.smoo;
bassGain2 = hslider("bassGain2", 0.1, 0, 1, 0.001) : si.smoo;

bass1 = os.sawtooth(freq1 * 0.25) * bassGain1 : fi.resonlp(2500, 1, 1);
bass2 = os.sawtooth(freq1 * 0.25 * 0.75) * bassGain2 : fi.resonlp(2500, 1, 1); 

process = _ * 0.25 <: pm.guitarModel(length1, 0.5) + pm.guitarModel(length2, 0.5) + pm.guitarModel(length3, 0.5) + pm.guitarModel(length4, 0.5) + bass1 + bass2 : co.compressor_mono(4, -20, 0.012, 0.012) : co.limiter_1176_R4_mono <: _,_;
 */

