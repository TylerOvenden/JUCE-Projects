/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SynthBasicAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SynthBasicAudioProcessorEditor (SynthBasicAudioProcessor&);
    ~SynthBasicAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthBasicAudioProcessor& audioProcessor;
    juce::Slider attackSlider;
    juce::Slider decaySlider;

    juce::Slider releaseSlider;

    juce::Slider susSlider;
    juce::ComboBox com;

    //use alias to make code cleaner
    using shortened = juce::AudioProcessorValueTreeState::SliderAttachment;
    using combo = juce::AudioProcessorValueTreeState::ComboBoxAttachment;
    std::unique_ptr<shortened> attAt;
    std::unique_ptr<shortened> decayAt;
    std::unique_ptr<shortened> susAt;
    std::unique_ptr<shortened> relAt;

    std::unique_ptr<combo> selAt;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthBasicAudioProcessorEditor)
};
