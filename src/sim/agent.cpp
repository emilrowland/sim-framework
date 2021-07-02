// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "sim/agent.h"

void Agent::registerStateVariable(void* variable, std::string name, std::string type) {
    this->stateVariables.push_back(variable);
}