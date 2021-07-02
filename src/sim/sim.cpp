// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/sim.h"

#include <iostream>

Sim::Sim(std::string simName) {
    this->simName = simName;
    this->currentTime = 0;
}

void Sim::run() {
    std::cout << "Running simulation: " << this->simName << std::endl;
    //Execute simulation
    while(this->currentTime < this->stopTime) {
        std::cout << "Simulation tick: " << this->currentTime << std::endl;
        for(auto* agent: this->agents) {
           agent->tick();
        }
        this->currentTime++;
    }
    std::cout << "Simulation ended" << std::endl;
    this->outputState();
}

void Sim::outputState() {
    std::cout << "== State ==" << std::endl;
    for(auto* agent: this->agents) {
        std::cout << "State for agent: " << agent->getAgentName() << std::endl;
        for(auto* state: agent->getStateVariables()) {
            int value = *static_cast<int*>(state);
            std::cout << value << std::endl; 
        }
    }
    
    std::cout << "====" << std::endl;
}