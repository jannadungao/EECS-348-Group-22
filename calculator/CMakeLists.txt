cmake_minimum_required(VERSION 3.16)

project(calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt Widgets and Qt QML
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Qml)

set(PROJECT_SOURCES
    main.cpp
    calculator.cpp
    calculator.h
    calculator.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(calculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(calculator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(calculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link to both Qt Widgets and Qt QML
target_link_libraries(calculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Qml)

# Bundle properties for macOS/iOS (as per your existing config)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.calculator)
endif()
set_target_properties(calculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(calculator)
endif()
