set(SRC bdf-font.cc framebuffer.cc gpio.cc
graphics.cc hardware-mapping.c led-matrix.cc
options-initialize.cc thread.cc transformer.cc)

add_library(rgb_library ${SRC})
