cmake_minimum_required(VERSION 2.8)

project(Weather)

SET(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)

add_compile_options(-std=c++11)

#-------------------------------------------------------------------------------
# Add Threads
#-------------------------------------------------------------------------------
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

#-------------------------------------------------------------------------------
# Add PugiXML
#-------------------------------------------------------------------------------
# set PugiXML directory
set (PUGIXML_SRC_DIR "pugixml")

# include Pugixml source
add_subdirectory(${PUGIXML_SRC_DIR})

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
