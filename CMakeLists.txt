# Require CMake >= 2.6.3
cmake_minimum_required(VERSION 2.6.3)

# C++ version check
include("cmake/set_cxx_norm.cmake")

# Policies
cmake_policy(SET CMP0012 NEW)

# Add module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Define project's name
PROJECT(qSlides)

# Qt4 is required
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
SET(project_LINK_LIBS ${QT_LIBRARIES})

# Find Poppler
find_package(Poppler REQUIRED)
INCLUDE_DIRECTORIES(${POPPLER_QT4_INCLUDE_DIR})
SET(project_LINK_LIBS ${project_LINK_LIBS} ${POPPLER_QT4_LIBRARIES})

# Add source files
SET(project_SOURCES
    src/main.cpp
    src/StartWindow.cpp
    src/ControlWindow.cpp
    src/PresentationWindow.cpp
    src/IDocumentModel.cpp
    src/PdfModel.cpp
    src/PresentationController.cpp)

# Add header files
SET(project_HEADERS
    src/StartWindow.h
    src/ControlWindow.h
    src/PresentationWindow.h
    src/IDocumentModel.h
    src/PdfModel.h
    src/PresentationController.h)

# Add Qt UI files
SET(project_FORMS
    forms/startWindow.ui
    forms/controlWindow.ui
    forms/presentationWindow.ui)

# Generate qt mocs
QT4_WRAP_CPP(project_HEADERS_MOC ${project_HEADERS})
QT4_WRAP_UI(project_FORMS_HEADERS ${project_FORMS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

# Compiler flasgs (C++11)
set_cxx_norm(CXX_NORM_CXX11)
if(CMAKE_COMPILER_IS_GNUCXX OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_definitions("-pedantic -Wall")
endif()

# Compile & link
ADD_EXECUTABLE(qSlides ${project_SOURCES} ${project_HEADERS_MOC} ${project_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(qSlides ${project_LINK_LIBS})
