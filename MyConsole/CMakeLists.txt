cmake_minimum_required(VERSION 3.5)

project(MyConsole VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/windowscore")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/figs")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/CustomElements")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/AbsClasses")

set(TS_FILES MyConsole_pt_BR.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyConsole
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        AbsClasses/Commands.h
        AbsClasses/thread_header.h
        windowscore/mainwinos.h windowscore/mainwinos.cpp
        windowscore/FileTree/FileTree.h windowscore/FileTree/FileTree.cpp
        windowscore/PathManager/pathmanager.h windowscore/PathManager/pathmanager.cpp
        windowscore/StringTools/stringtools.h windowscore/StringTools/stringtools.cpp
        windowscore/EnvVaribles/env_vars.h windowscore/EnvVaribles/env_vars.cpp
        windowscore/FileManager/filemanager.h windowscore/FileManager/filemanager.cpp
        CustomElements/customplaintext.h
        windowscore/CommandsClasses/cd.h
        windowscore/CommandsClasses/pwd.h
        windowscore/CommandsClasses/dir.h
        windowscore/CommandsClasses/grep.h
        windowscore/CommandsClasses/ls.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MyConsole APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(MyConsole SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MyConsole
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(MyConsole PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MyConsole)
endif()
set_target_properties(MyConsole PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MyConsole
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyConsole)
endif()
