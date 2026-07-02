#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class PluginBoilerplateAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit PluginBoilerplateAudioProcessorEditor (PluginBoilerplateAudioProcessor&);
    ~PluginBoilerplateAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    PluginBoilerplateAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginBoilerplateAudioProcessorEditor)
};