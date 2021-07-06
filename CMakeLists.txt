cmake_minimum_required(VERSION 3.9)
project(Sim-Framework)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# download nlohmann_json
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.9.1)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()



add_library(sim
    lib/src/sim/sim.cpp
    lib/src/sim/agent.cpp
    lib/src/sim/reporter.cpp
)

target_include_directories(sim PRIVATE lib/include)
target_link_libraries(sim PRIVATE nlohmann_json::nlohmann_json)

add_executable(example
    example/main.cpp
    example/electric/electricSim.cpp
)

target_link_libraries(example sim)

target_include_directories(example PRIVATE lib/include)