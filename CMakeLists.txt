cmake_minimum_required(VERSION 3.18)
project(mediaPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)

# -------------------- Qt5 --------------------
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Svg)

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
# Пример: если у вас есть source/test.qrc, то:
set(TEST_QRC "${CMAKE_SOURCE_DIR}/source/test.qrc")
qt5_add_resources(RES_SOURCES ${TEST_QRC})

# -------------------- Основной исполняемый файл --------------------
add_executable(mediaPlayer
        # Список всех исходников:
        main.cpp
        src/music_player_window.cpp
        src/metadata_parser.cpp   # убрать, если не нужен

        # Явно указываем заголовки с Q_OBJECT, чтобы AUTOMOC их подхватил:
        include/RotatingLabel.h
        include/music_player_window.h
        include/ui_mediaPlayer.h  # UI-заголовок, сгенерированный uic

        ${RES_SOURCES}
)

# Указываем папку с нашими заголовками
target_include_directories(mediaPlayer PRIVATE include)

# Линкуем библиотеки
target_link_libraries(mediaPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
        ${MY_TAGLIB_TARGET}
        ZLIB::ZLIB
)
