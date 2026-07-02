#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginBoilerplateAudioProcessorEditor::PluginBoilerplateAudioProcessorEditor (PluginBoilerplateAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

PluginBoilerplateAudioProcessorEditor::~PluginBoilerplateAudioProcessorEditor()
{
}

void PluginBoilerplateAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Boilerplate Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void PluginBoilerplateAudioProcessorEditor::resized()
{
}