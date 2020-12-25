cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

set(CMAKE_PREFIX_PATH /opt/ros/noetic)

project(tracking_gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /opt/ros/noetic)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories($ {CMAKE_PREFIX_PATH})
include_directories( /opt/ros/noetic/include )

add_executable(tracking_gui
    main.cpp
    mainwindow.cpp
    tracking_gui.cpp
)

target_link_libraries( tracking_gui
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    ${catkin_LIBRARIES}
)


