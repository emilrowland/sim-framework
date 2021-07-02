// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>

class Agent {
    public:
        explicit Agent(std::string agentName)
        : agentName(agentName) {};

        virtual void tick() {};

        std::string getAgentName() const {
            return this->agentName;
        }
    private:
        std::string agentName;
};