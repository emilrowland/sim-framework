// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "reporter.h"

#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

#include <sim/sim.h>

Reporter::Reporter(const std::string& simName) {
    this->simPath = "res/" + simName + "/";

    // Create new empty folder for the simulation
    std::filesystem::remove_all(this->simPath);
    std::filesystem::create_directories(this->simPath);
}

void Reporter::outputAgentStateVariables(const std::string& agentName, int currentTime, std::vector<StateVariable> StateVariables) {
    nlohmann::json j;
    j["_currentTime"] = currentTime;
    for(auto state: StateVariables) {
        j[state.name] = Sim::parseStateVariable(state);
    }

    std::string agentFolder = this->simPath + "agents/" + agentName + "/";

    std::filesystem::create_directories(agentFolder);

    std::filebuf fb;
    if(fb.open(agentFolder + "stateVariables.json", std::ios::out|std::ios::app) == nullptr){
        throw "Can't open file stateVariables.json for agent";
    }
    std::ostream os(&fb);
    os << j.dump() << "\n";
    fb.close();
}