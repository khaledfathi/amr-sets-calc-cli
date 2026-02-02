
add_library(${INTERNAL_LIBS} INTERFACE)

target_include_directories(${INTERNAL_LIBS} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory("external")