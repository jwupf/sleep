# CMakeList.txt : CMake project for sleep, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("sleep")

# Add source to this project's executable.
add_executable (sleep "sleep.cpp" "sleep.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sleep PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
