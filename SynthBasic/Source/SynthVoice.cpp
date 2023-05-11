/*
  ==============================================================================

    SynthVoice.cpp
    Created: 11 May 2023 12:43:11pm
    Author:  vleen

  ==============================================================================
*/
#pragma once 
#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* s)
{
    return dynamic_cast<juce::SynthesiserSound*>(s) != nullptr;
}
void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{

    //freq will be set from the midiNoteNumber value, uses the getMidiNoteInHertz method
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    adsr.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr.noteOff();
}
void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}
void  SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels) {
    
    adsr.setSampleRate(sampleRate);

    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = numChannels;
    spec.sampleRate = sampleRate;

    osc.prepare(spec);
    //set gain to prevent possible loudness
    gain.prepare(spec);
  //  osc.setFrequency(220.0f);

    //setGainLinear range is (0-1)
    gain.setGainLinear(0.01f);
    didPrepare = true;

}
void SynthVoice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)

{
    jassert(didPrepare);
    juce::dsp::AudioBlock<float> audioBlock{
       outputBuffer
    };

    //audioBlock is an allias for the output buffer

    osc.process(juce::dsp::ProcessContextReplacing <float>(audioBlock));
    //decreases the volume;
    gain.process(juce::dsp::ProcessContextReplacing <float>(audioBlock));
    //passing in outbuffer = passing in the audioblock, will have the same data passed in from the osc & gain

    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}