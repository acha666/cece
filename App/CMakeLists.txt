add_library(app STATIC)

# Add the source files for submodules
# app_main Module
target_sources(app PRIVATE
    app_main/app_main.cpp
)

# gpio Module
target_sources(app PRIVATE
    gpio/gpio.cpp
)

# i2c Module
target_sources(app PRIVATE
    i2c/i2c.cpp
)

# ps2 Module
target_sources(app PRIVATE
    ps2/ps2.cpp
)

# 添加App下的公共包含路径，若需要统一include路径，也可添加
target_include_directories(app PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/app_main
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio
    ${CMAKE_CURRENT_SOURCE_DIR}/i2c
    ${CMAKE_CURRENT_SOURCE_DIR}/ps2
)

# 如果模块之间需要特定的宏定义或编译选项，可在此添加
# target_compile_definitions(app PRIVATE SOME_DEFINE)
# target_compile_options(app PRIVATE -Wall)

# 若需要链接其他库(如math库)，可在这里指定
target_link_libraries(app PRIVATE stm32cubemx)
