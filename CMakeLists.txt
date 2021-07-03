cmake_minimum_required(VERSION 3.20)
project(Sim-Framework)

set(CMAKE_CXX_STANDARD 20)

add_library(sim
    src/sim/sim.cpp
    src/sim/agent.cpp
    src/sim/reporter.cpp
)

target_include_directories(sim PRIVATE include)

add_executable(example
    example/main.cpp
)

target_link_libraries(example sim)

target_include_directories(example PRIVATE include)