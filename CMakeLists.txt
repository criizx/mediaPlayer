cmake_minimum_required(VERSION 3.18)
project(mediaPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)

# -------------------------------------------------------
# Qt5
# -------------------------------------------------------
find_package(Qt5 REQUIRED COMPONENTS Core Gui Svg Widgets)

set(TEST_QRC "${CMAKE_SOURCE_DIR}/source/test.qrc")
qt5_add_resources(RES_SOURCES ${TEST_QRC})

# -------------------------------------------------------
# Основной исполняемый файл
# -------------------------------------------------------
add_executable(mediaPlayer
        main.cpp
        ${RES_SOURCES}
        include/RotatingLabel.h
        include/ui_mediaPlayer.h
)

target_link_libraries(mediaPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Svg
)

# -------------------------------------------------------
# TagLib + ZLIB
# -------------------------------------------------------
find_package(ZLIB REQUIRED)

# Попытка найти IMPORTED target
find_package(Taglib QUIET)

if (Taglib_FOUND AND TARGET Taglib::Taglib)
    set(MY_TAGLIB_TARGET Taglib::Taglib)
else()
    find_library(TAGLIB_LIB NAMES tag REQUIRED)
    set(MY_TAGLIB_TARGET ${TAGLIB_LIB})
endif()

# -------------------------------------------------------
# Тест на метаданные
# -------------------------------------------------------
add_executable(MetadataTest
        src/metadata_test.cpp
        src/metadata_parser.cpp
)

target_include_directories(MetadataTest PRIVATE include)

target_link_libraries(MetadataTest
        Qt5::Core
        Qt5::Gui
        ZLIB::ZLIB
        ${MY_TAGLIB_TARGET}
)

