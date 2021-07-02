// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>

enum StateVariableTypes {Int};

struct StateVariable {
    void* value;
    std::string name;
    StateVariableTypes type;
};

class Agent {
    public:
        Agent(std::string agentName)
        : agentName(agentName) {};

        virtual void tick() {};

        std::string getAgentName() const {
            return this->agentName;
        }

        std::vector<StateVariable> getStateVariables() const {
            return this->stateVariables;
        }
    private:
        std::string agentName;
        std::vector<StateVariable> stateVariables;
    protected:
        void registerStateVariable(void* variable, std::string name, StateVariableTypes type);
};