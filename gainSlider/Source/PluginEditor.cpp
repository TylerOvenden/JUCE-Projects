/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 300);
  // gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);


    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 30);
  //  gainSlider.setRange(-48.0, 0.0);
   // gainSlider.setValue(-1.0);
  //  gainSlider.addListener(this);

    gainSliderAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "GAIN", gainSlider);
       
    addAndMakeVisible(gainSlider);
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

 
  
}

void GainSliderAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..



   // gainSlider.setBounds(getLocalBounds());
    gainSlider.setBounds(getWidth()/2-100, getHeight()/2-500,200,100);
}
void GainSliderAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider)
        audioProcessor.rawVol = pow(10, gainSlider.getValue() / 20);

}