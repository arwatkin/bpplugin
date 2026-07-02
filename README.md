## Starting a new plugin from this template

### 1. Clone and rename the folder

    git clone --recurse-submodules https://github.com/arwatkin/bpplugin.git MyNewPlugin
    cd MyNewPlugin

### 2. Edit CMakeLists.txt — required fields

| Field                                                                                 | What to change it to          | Notes                                                                                                                   |
| ------------------------------------------------------------------------------------- | ----------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| `project(PluginBoilerplate ...)`                                                      | `project(MyNewPlugin ...)`    | top of file                                                                                                             |
| `juce_add_plugin(PluginBoilerplate`                                                   | `juce_add_plugin(MyNewPlugin` | must match target name used below                                                                                       |
| `COMPANY_NAME`                                                                        | your company/artist name      | shows up in plugin metadata                                                                                             |
| `PLUGIN_MANUFACTURER_CODE`                                                            | unique 4-char code            | must contain ≥1 uppercase letter, can't start with a digit — pick something tied to YOU, reused across all your plugins |
| `PLUGIN_CODE`                                                                         | unique 4-char code            | same rules, but unique **per plugin** — this is what stops two of your plugins colliding in a DAW's plugin list         |
| `PRODUCT_NAME`                                                                        | the plugin's public name      | what shows up in the DAW plugin browser                                                                                 |
| every `target_sources` / `target_link_libraries` line referencing `PluginBoilerplate` | rename to match new target    | CMake target names must be consistent throughout the file                                                               |

### 3. Edit CMakeLists.txt — plugin type flags

| Building a...                                              | IS_SYNTH | NEEDS_MIDI_INPUT | NEEDS_MIDI_OUTPUT | IS_MIDI_EFFECT |
| ---------------------------------------------------------- | -------- | ---------------- | ----------------- | -------------- |
| Audio effect (EQ, compressor, reverb)                      | FALSE    | FALSE            | FALSE             | FALSE          |
| Instrument / synth                                         | TRUE     | TRUE             | FALSE             | FALSE          |
| MIDI effect (arpeggiator, chord gen)                       | FALSE    | TRUE             | TRUE              | TRUE           |
| Audio effect that reacts to MIDI (e.g. tempo-synced delay) | FALSE    | TRUE             | FALSE             | FALSE          |

### 4. Rename the C++ classes (optional, cosmetic only)

The compiler doesn't care whether the class is called `PluginBoilerplateAudioProcessor` or something else — it'll build fine either way. Rename purely so your own codebase reads sensibly:

- `src/PluginProcessor.h/.cpp`: `PluginBoilerplateAudioProcessor` → `MyNewPluginAudioProcessor`
- `src/PluginEditor.h/.cpp`: `PluginBoilerplateAudioProcessorEditor` → `MyNewPluginAudioProcessorEditor`
- Update the matching `#include` guards / references between the two files

Find-and-replace across `src/` handles this in one pass in any editor.

### 5. Clear the old build cache

CMake caches variables like the project name — if you ran a build before renaming, delete it and start fresh:
rm -rf build

### 6. Build

    cmake -B build
    cmake --build build --config Release

### 7. Sanity check

Open your DAW, rescan plugins, confirm `PRODUCT_NAME` shows up correctly and under the right manufacturer — this is the tell that steps 2–3 actually took.
