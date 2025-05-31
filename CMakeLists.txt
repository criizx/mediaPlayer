cmake_minimum_required(VERSION 3.30)
project(mediaPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Svg
        Widgets
        REQUIRED
)

set(TEST_QRC "${CMAKE_SOURCE_DIR}/source/test.qrc")

qt5_add_resources(RES_SOURCES ${TEST_QRC})

add_executable(mediaPlayer
        main.cpp
        ./include/RotatingLabel.h
        ${RES_SOURCES}
        ./include/ui_mediaPlayer.h
)


target_link_libraries(mediaPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
)
