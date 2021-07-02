// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/sim.h"

Sim::Sim(std::string simName){
    this->simName = simName;
}

std::string Sim::getSimName() {
    return this->simName;
}