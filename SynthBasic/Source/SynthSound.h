/*
  ==============================================================================

    SynthSound.h
    Created: 8 May 2023 10:00:25pm
    Author:  vleen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
    bool appliesToNote(int) {
        return true;
    }

    bool appliesToChannel(int) {
        return true;
    }

};