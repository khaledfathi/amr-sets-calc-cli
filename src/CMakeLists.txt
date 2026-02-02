add_library(${APP_LIBS} STATIC  
    calculator.cpp
    cli_parser.cpp
    csv_processor.cpp
)

target_include_directories(${APP_LIBS} PUBLIC ${CMAKE_SOURCE_DIR}/inc)

add_executable(${EXEC} main.cpp)

target_link_libraries(${APP_LIBS} PUBLIC ${EXTERNAL_LIBS})

target_link_libraries(${EXEC} PUBLIC 
    ${EXTERNAL_LIBS}
    ${INTERNAL_LIBS}
    ${APP_LIBS}
)