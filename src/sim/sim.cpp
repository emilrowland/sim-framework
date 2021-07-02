// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/sim.h"

#include <iostream>

Sim::Sim(std::string simName) {
    this->simName = simName;
    this->currentTime = 0;
}

void Sim::run() {
    std::cout << "Running simulation: " << this->getSimName() << std::endl;
    //Execute simulation
    while(this->currentTime < this->stopTime) {
        std::cout << "Simulation tick: " << this->currentTime << std::endl;
        this->currentTime++;
    }
    std::cout << "Simulation ended" << std::endl;
}

std::string Sim::getSimName() {
    return this->simName;
}