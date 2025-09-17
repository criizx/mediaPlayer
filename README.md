# Music Player

A modern Qt5-based music player with an animated vinyl record interface.

## Description

This application is a stylish music player featuring an animated interface that mimics a vinyl record player. The player automatically loads music from a specified folder, displays track metadata, and shows album covers.

## Features

- **Music Playback**: Supports MP3, WAV, FLAC, AAC, OGG formats
- **Animated Interface**: Rotating vinyl record and album cover
- **Playback Controls**: Play/Pause, Next, Previous
- **Volume Control**: Volume slider and +/- buttons
- **Metadata Display**: Shows track title, artist, and album artwork
- **Folder Selection**: Ability to choose different music folders
- **Random Playback**: Playlist in Random mode

## Technologies

- **Qt5**: Core, Gui, Widgets, Svg, Multimedia
- **TagLib**: Audio metadata parsing
- **CMake**: Build system
- **C++20**: Language standard

## Architecture

The project follows the MVC pattern:

- **Controller**: `Controller` - coordinates interaction between UI and logic
- **View**: `music_player_window`, `player_ui` - user interface
- **Model**: `media_playback`, `metadata_parser` - business logic

### Key Components

- `RotatingLabel`: Custom widget for rotation animation
- `disc_rotator`: Manages vinyl and cover animation
- `metadata_parser`: Extracts metadata from audio files
- `playlist_loader`: Loads playlist from folder

## Build

```bash
mkdir build
cd build
cmake ..
make
```

### Requirements

- Qt5 (Core, Gui, Widgets, Svg, Multimedia)
- TagLib
- ZLIB
- CMake 3.18+
- C++20 compatible compiler

## Usage

On startup, the player automatically searches for music in the user's Music folder. To select a different folder, use the path change button in the top-right corner.

**Controls:**
- Center button: Play/Pause
- Arrow buttons: Previous/Next track
- Right slider: Volume
- +/- buttons: Quick volume adjustment
