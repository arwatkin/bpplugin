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
    void toggleFullScreen();

    [[maybe_unused]] PluginBoilerplateAudioProcessor& audioProcessor;
    juce::TextButton fullscreenButton { "Fullscreen" };
    juce::Rectangle<int> preFullScreenBounds;
    bool isFullScreen = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginBoilerplateAudioProcessorEditor)
};