// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/sim.h"

#include <iostream>
#include <string>
#include <chrono>

#include "reporter.h"

Sim::Sim(std::string simName) {
    this->simName = simName;
    this->currentTime = 0;
    this->reporter = new Reporter(simName);
}

void Sim::run() {
    auto startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Running simulation: " << this->simName << std::endl;
    this->outputState();
    //Execute simulation
    while(this->currentTime < this->stopTime) {
        std::cout << "Simulation tick: " << this->currentTime << std::endl;
        for(auto* agent: this->agents) {
           agent->tick();
        }
        this->outputState();
        this->currentTime++;
    }
    std::cout << "Simulation ended" << std::endl;
    this->outputState();

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endTime-startTime;
    std::cout << "Simulation durration: " << diff.count() << " s\n";
}

void Sim::outputState() const {
    std::cout << "== State ==" << std::endl;
    for(auto* agent: this->agents) {
        std::cout << "State for agent: " << agent->getAgentName() << std::endl;
        for(auto state: agent->getStateVariables()) {
            std::cout << state.name << ": " << this->parseStateVariable(state) << std::endl; 
        }
    }
    std::cout << "====" << std::endl;
}

std::string Sim::parseStateVariable(StateVariable stateVariable) const {
    if(stateVariable.type == StateVariableTypes::Int) {
        int value = *static_cast<int*>(stateVariable.value);
        return std::to_string(value);
    }
    throw "Inavalid StateVariable type";
}