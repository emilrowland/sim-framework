// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>

// Forward declaration
class Sim;

enum StateVariableTypes {Int, Float};

struct StateVariable {
    void* value;
    std::string name;
    StateVariableTypes type;
};

class Agent {
    public:
        Agent(std::string agentName)
        : agentName(agentName) {};

        virtual void tick(int currentTime) {};

        void setSimInstance(Sim* simInstance) {
            this->simInstance = simInstance;
        }

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
        Sim* simInstance;

        void registerStateVariable(void* variable, std::string name, StateVariableTypes type);
};