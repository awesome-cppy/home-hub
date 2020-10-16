set(ALL_SOURCES main.cpp)
set(EXEC home_hub)

target_sources(
        PUBLIC
        ${ALL_SOURCES}
)

target_include_directories(
        home-hub
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)