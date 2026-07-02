#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginBoilerplateAudioProcessor::PluginBoilerplateAudioProcessor()
     : AudioProcessor (BusesProperties()
                      #if ! JucePlugin_IsMidiEffect
                       #if ! JucePlugin_IsSynth
                        .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       #endif
                        .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                      #endif
                       )
{
}

PluginBoilerplateAudioProcessor::~PluginBoilerplateAudioProcessor()
{
}

const juce::String PluginBoilerplateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PluginBoilerplateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PluginBoilerplateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PluginBoilerplateAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PluginBoilerplateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PluginBoilerplateAudioProcessor::getNumPrograms()
{
    return 1;
}

int PluginBoilerplateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PluginBoilerplateAudioProcessor::setCurrentProgram (int index)
{
    juce::ignoreUnused (index);
}

const juce::String PluginBoilerplateAudioProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void PluginBoilerplateAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}

void PluginBoilerplateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused (sampleRate, samplesPerBlock);
}

void PluginBoilerplateAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PluginBoilerplateAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
   #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
   #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
   #endif
}
#endif

void PluginBoilerplateAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused (midiMessages);

    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // TODO: your DSP goes here
}

bool PluginBoilerplateAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* PluginBoilerplateAudioProcessor::createEditor()
{
    return new PluginBoilerplateAudioProcessorEditor (*this);
}

void PluginBoilerplateAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::ignoreUnused (destData);
}

void PluginBoilerplateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    juce::ignoreUnused (data, sizeInBytes);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginBoilerplateAudioProcessor();
}