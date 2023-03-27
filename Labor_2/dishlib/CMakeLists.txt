add_library(
        dishlib
        dishlib.cpp
)

target_include_directories(
        dishlib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)