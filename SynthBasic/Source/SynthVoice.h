/*
  ==============================================================================

    SynthVoice.h
    Created: 8 May 2023 10:00:44pm
    Author:  vleen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
public:
    bool SynthVoice::canPlaySound(juce::SynthesiserSound* s)
    {
        return dynamic_cast<juce::SynthesiserSound*>(s) != nullptr;
    }
    void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
    {

    }

    void SynthVoice::stopNote(float velocity, bool allowTailOff)
    {

    }
    void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

    }

    void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
    {

    }
    void prepareToPlay(double sampleRate, int samplesPerBlock) {}
    void SynthVoice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
    
    {
    }
private:
    //this will play a saw wave
    juce::dsp::Oscillator<float> osc{ [](float x) {   return x / juce::MathConstants<float>::pi;  } };
    //  juce::dsp::Oscillator<float> osc{ [](float x) { return x < 0.0f ? -1.0f : 1.0f; }, 200 };
    juce::dsp::Gain<float> gain;

};
