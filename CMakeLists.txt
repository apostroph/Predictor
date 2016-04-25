# Copyright: (C) 2010 RobotCub Consortium
# Author: Paul Fitzpatrick
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
# YARP needs CMake 2.8.7 or greater
cmake_minimum_required(VERSION 2.8.7)

add_definitions(-std=gnu++0x)

# add YARP include directories
# Predictor
add_executable(Predictor 
Predictor/src/main.cpp 
Predictor/src/Predictor.cpp Predictor/src/Predictor.h )
# link with YARP libraries and Opencv Librariesr

install(TARGETS Predictor DESTINATION bin)