// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>

class Agent {
    public:
        Agent(std::string agentName)
        : agentName(agentName) {};

        virtual void tick() {};

        std::string getAgentName() const {
            return this->agentName;
        }

        std::vector<void*> getStateVariables() const {
            return this->stateVariables;
        }
    private:
        std::string agentName;
        std::vector<void*> stateVariables;
    protected:
        void registerStateVariable(void* variable, std::string name, std::string type);
};