/*
  ==============================================================================

    SynthVoice.h
    Created: 8 May 2023 10:00:44pm
    Author:  vleen

  ==============================================================================
*/

#pragma once 
//#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
public:
    bool SynthVoice::canPlaySound(juce::SynthesiserSound* s)override;
    void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;

    void SynthVoice::stopNote(float velocity, bool allowTailOff) override;
    void SynthVoice::pitchWheelMoved(int newPitchWheelValue) override;
    void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue) override;
    void  SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void SynthVoice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;
private:
    juce::ADSR adsr;
    juce::ADSR::Parameters param;

    //this will play a saw wave
    juce::dsp::Oscillator<float> osc{ [](float x) {   return x / juce::MathConstants<float>::pi;  } };
    //  juce::dsp::Oscillator<float> osc{ [](float x) { return x < 0.0f ? -1.0f : 1.0f; }, 200 };
    juce::dsp::Gain<float> gain;
    bool didPrepare = false;
};
