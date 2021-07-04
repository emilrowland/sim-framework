// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/sim.h"

#include <iostream>
#include <string>
#include <chrono>

#include "reporter.h"

Sim::Sim(std::string simName) {
    this->simName = simName;
    this->silentMode = false;

    this->currentTime = 0;
    this->reporter = new Reporter(simName);
}

void Sim::run() {
    auto startTime = std::chrono::high_resolution_clock::now();
    this->logInfo("Running simulation: " + this->simName);
    this->outputState();
    //Execute simulation
    while(this->currentTime < this->stopTime) {
        this->currentTime++;
        this->logInfo("Simulation tick: " + this->currentTime);
        for(auto* agent: this->agents) {
           agent->tick(this->currentTime);
        }
        if(this->currentTime < this->stopTime) { //Don't output on last tick
            this->outputState();
        }
        
    }
    this->logInfo("Simulation ended");
    this->outputState();

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime-startTime;
    this->logInfo("Simulation durration: " + std::to_string(diff.count()));
}

void Sim::outputState() {
    this->logInfo("== State ==");
    for(auto* agent: this->agents) {
        this->logInfo("State for agent: " + agent->getAgentName());
        this->reporter->outputAgentStateVariables(agent->getAgentName(), this->currentTime, agent->getStateVariables());
        for(auto state: agent->getStateVariables()) {
            this->logInfo(state.name + ": " + Sim::parseStateVariable(state));
        }
    }
    this->logInfo("====");
}

const std::string Sim::parseStateVariable(StateVariable stateVariable) {
    if(stateVariable.type == StateVariableTypes::Int) {
        int value = *static_cast<int*>(stateVariable.value);
        return std::to_string(value);
    } else if(stateVariable.type == StateVariableTypes::Float) {
        float value = *static_cast<float*>(stateVariable.value);
        return std::to_string(value);
    }
    throw "Inavalid StateVariable type";
}

void Sim::logInfo(std::string message) {
    if(!this->silentMode){
        std::cout << message << std::endl;
    }
}