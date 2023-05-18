/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/
#pragma once 
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthBasicAudioProcessorEditor::SynthBasicAudioProcessorEditor (SynthBasicAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    using shortened = juce::AudioProcessorValueTreeState::SliderAttachment;
    using combo = juce::AudioProcessorValueTreeState::ComboBoxAttachment;
    attAt = std::make_unique<shortened>(audioProcessor.tree, "ATA", attackSlider);
    decayAt = std::make_unique<shortened>(audioProcessor.tree, "DEA", decaySlider);
    susAt = std::make_unique<shortened>(audioProcessor.tree, "SUA", sustainSlider);
    relAt = std::make_unique<shortened>(audioProcessor.tree, "REA", releaseSlider);
   // std::unique_ptr<shortened> attAt;
  /*  std::unique_ptr<shortened> decayAt;
    std::unique_ptr<shortened> susAt;
    std::unique_ptr<shortened> relAt;

    std::unique_ptr<combo> selAt;*/

}

SynthBasicAudioProcessorEditor::~SynthBasicAudioProcessorEditor()
{
}

//==============================================================================
void SynthBasicAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SynthBasicAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
