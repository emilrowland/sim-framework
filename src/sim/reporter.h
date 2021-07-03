// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>

#include <sim/agent.h>

class Reporter {
    public:
        Reporter(std::string simName);  
        void outputAgentStateVariables(std::string agentName, int currentTime, std::vector<StateVariable> StateVariables);
    private:
        std::string simPath;
};