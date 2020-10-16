add_definitions(-std=c++17 -Wall -pedantic -O1 -llapack -lblas -lgtest -larmadillo )

set(ALL_SOURCES "../src")

add_executable(
        unit_tests
        ${ALL_SOURCES}
)

target_link_libraries(
        unit_tests
        gtest_main
        home_hub
)

add_test(
        NAME
        Sensor_Home_AUTOMATION
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)