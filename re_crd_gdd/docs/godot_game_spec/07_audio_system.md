# 7. Audio System

## 7.1 Architecture

The game uses two distinct audio paths:
1. **Music (MIDI/FM Synthesis)**: Handled by an OPL2 synthesis engine.
2. **Sound Effects (RAW PCM)**: Handled by digital waveform patching.

## 7.2 SX Container Format
The `TIM2.SX` container holds all audio patches.
- **IDs < 300**: OPL2 FM patches (using SCI28 Sierra Creative Interpreter format).
- **IDs >= 1000**: Digital waveform patches (Background music).
- **IDs >= 3000**: Unsigned 8-bit PCM RAW sound effects.

## 7.3 Raw Sound Effects
- Format: Unsigned 8-bit PCM, mono, center = 128.
- Sample Rate: **11025 Hz** (Confirmed via EXE `SB` time constant `0xA5`).
- 113 unique sound files extracted into `res://data/wav/`.

## 7.4 Godot Audio Dispatcher

The Godot frontend uses an event-driven `AudioDispatcher.gd` node to play sounds.

1. **Monitor State**: Listens to the backend for state transitions (or catches `PLAY_SFX` opcodes from the `ANMPlayer`).
2. **Resource Lookup**: Maps the `sound_id` to the loaded `AudioStreamWAV` resource.
3. **Channel Pooling**: Finds an available `AudioStreamPlayer` node from an instantiated pool.
4. **Playback**: Assigns the stream and calls `play()`.
