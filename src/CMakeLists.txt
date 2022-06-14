cmake_minimum_required(VERSION 3.17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(target_name Facerecognition)
set(TS_FILES ${target_name}_zh_CN.ts)

file(GLOB PROJECT_SOURCES *.h *.hpp *.cpp *.ui *.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${target_name} MANUAL_FINALIZATION ${PROJECT_SOURCES})
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    add_executable(${target_name} ${PROJECT_SOURCES})
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_include_directories(${target_name} PRIVATE ../include)

if (WIN32)
    target_link_directories(${target_name} PRIVATE ../lib/win32)
    target_link_libraries(${target_name} PRIVATE readerlib WltRS)
else()
    target_link_directories(${target_name} PRIVATE ../lib/armv7)
    target_link_libraries(${target_name} PRIVATE libReader libWltRS)
endif()

target_link_libraries(${target_name} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${target_name} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${target_name})
endif()
