# PluginBoilerplate

A cross-platform JUCE VST3/AU/Standalone plugin boilerplate.

## Clone

    git clone --recurse-submodules <your-repo-url>

## Build

    cmake -B build
    cmake --build build --config Release

## Updating JUCE to latest

    git submodule update --remote --merge
    git add JUCE
    git commit -m "Update JUCE to latest master"

## Starting a new plugin from this template

1. Rename the project in `CMakeLists.txt` (`project()` name, `juce_add_plugin` target name).
2. Change `PLUGIN_MANUFACTURER_CODE` and `PLUGIN_CODE` to unique 4-char codes.
3. Update `COMPANY_NAME` and `PRODUCT_NAME`.
4. Rename `Source/PluginProcessor.*` / `PluginEditor.*` classes if desired.
5. Flip `IS_SYNTH` / `NEEDS_MIDI_INPUT` in `CMakeLists.txt` if building an instrument.
