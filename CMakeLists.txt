cmake_minimum_required(VERSION 2.8)

project(Weather)

set(CMAKE_CXX_FLAGS "-Wall -std=gnu++11")

#-------------------------------------------------------------------------------
# Add Threads
#-------------------------------------------------------------------------------
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

#-------------------------------------------------------------------------------
# Add RGB Matrix Library
#-------------------------------------------------------------------------------
# set RGB directory
set (RGB_SRC_DIR "rgb_led_matrix")

# include RGB source
include_directories("${RGB_SRC_DIR}/include")
add_subdirectory(${RGB_SRC_DIR})

#-------------------------------------------------------------------------------
# Add src
#-------------------------------------------------------------------------------
#set sources
set(SOURCE_FILES main.cpp Clock.cpp Clock.h)

#-------------------------------------------------------------------------------
# Compile and Link
#-------------------------------------------------------------------------------
add_executable(Clock ${SOURCE_FILES})

#linking
target_link_libraries(Clock rgb_library)
target_link_libraries(Clock rt)
target_link_libraries(Clock m)
target_link_libraries(Clock pthread)

#add_custom_command(OUTPUT "${CMAKE_BINARY_DIR}\rgb_led_matrix/fonts/7x13.bdf"
#  COMMAND cp "${CMAKE_SOURCE_DIR}/rgb_led_matrix/fonts/7x13.bdf ${CMAKE_BINARY_DIR}\rgb_led_matrix/fonts/7x13.bdf"
#  VERBATIM
#)

#ADD_CUSTOM_COMMAND(TARGET Clock POST_BUILD
#          COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/rgb_led_matrix/fonts/7x13.bdf ${PROJECT_BINARY_DIR}/rgb_led_matrix/fonts/7x13.bdf
#)
