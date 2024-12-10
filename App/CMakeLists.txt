# App Module CMakeLists
cmake_minimum_required(VERSION 3.22)

# Define a library for App
add_library(app STATIC)

# Automatically find source files in App directory
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.h"
)

# Add all found sources to the library
target_sources(app PUBLIC ${APP_SOURCES})

# Include all directories in App for headers
target_include_directories(app PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Link with stm32cubemx
target_link_libraries(app PUBLIC stm32cubemx)
