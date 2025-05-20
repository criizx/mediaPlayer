cmake_minimum_required(VERSION 3.31)
project(mediaPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

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
        mediaPlayer.ui
        RotatingLabel.h
        ${RES_SOURCES}
        RotatingLabel.h
)


target_link_libraries(mediaPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
)
