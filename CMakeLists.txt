cmake_minimum_required(VERSION 2.6)

PROJECT(qSlides)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

SET(project_SOURCES src/main.cpp src/MainWindow.cpp)
SET(project_HEADERS src/MainWindow.h)
SET(project_FORMS forms/mainWindow.ui)

QT4_WRAP_CPP(project_HEADERS_MOC ${project_HEADERS})
QT4_WRAP_UI(project_FORMS_HEADERS ${project_FORMS})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(qSlides ${project_SOURCES} ${project_HEADERS_MOC} ${project_FORMS_HEADERS})
TARGET_LINK_LIBRARIES(qSlides ${QT_LIBRARIES})
