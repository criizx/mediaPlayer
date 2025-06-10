cmake_minimum_required(VERSION 3.18)
project(mediaPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)

# -------------------- Qt5 --------------------
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Svg Multimedia)

# -------------------- ZLIB --------------------
find_package(ZLIB REQUIRED)

# -------------------- TagLib --------------------
find_package(Taglib QUIET)
if (Taglib_FOUND AND TARGET Taglib::Taglib)
    set(MY_TAGLIB_TARGET Taglib::Taglib)
else()
    find_library(TAGLIB_LIB NAMES tag REQUIRED)
    set(MY_TAGLIB_TARGET ${TAGLIB_LIB})
endif()

message(STATUS "TagLib target: ${MY_TAGLIB_TARGET}")

# -------------------- Ресурсы (если есть .qrc-файлы) --------------------
set(TEST_QRC "${CMAKE_SOURCE_DIR}/source/test.qrc")
qt5_add_resources(RES_SOURCES ${TEST_QRC})

# -------------------- Исходники --------------------
set(SOURCES
        main.cpp

        src/ui/music_player_window.cpp
        src/ui/player_ui.cpp
        src/ui/disk_rotator.cpp

        src/player_logic/media_playback.cpp
        src/player_logic/metadata_parser.cpp
        src/player_logic/playlist_loader.cpp
)

# -------------------- Заголовки с Q_OBJECT --------------------
set(HEADERS
        include/ui/music_player_window.h
        include/ui/player_ui.h
        include/ui/disc_rotator.h
        include/ui/RotatingLabel.h
        include/ui/ui_mediaPlayer.h

        include/player_logic/media_playback.h
        include/player_logic/metadata_parser.h
        include/player_logic/playlist_loader.h
        include/player_logic/music_metadata.h
)

add_executable(mediaPlayer ${SOURCES} ${HEADERS} ${RES_SOURCES})

# -------------------- Подключаем директории --------------------
target_include_directories(mediaPlayer PRIVATE include)

# -------------------- Линкуем библиотеки --------------------
target_link_libraries(mediaPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
        Qt5::Multimedia
        ${MY_TAGLIB_TARGET}
        ZLIB::ZLIB
)
